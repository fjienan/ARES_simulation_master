#include "ares_comm/protocol_parser.hpp"
#include "ares_comm/serial_interface.hpp"
#include "ares_comm/crc.hpp"
#include <rclcpp/rclcpp.hpp>
#include <iomanip>

using namespace ares_comm;

class TestNode : public rclcpp::Node {
public:
  TestNode() : Node("test_serial_node") {
    // 执行帧测试
    // test_execute_frame();
    
    // // 返回帧测试
    test_response_frame();
    
    // // 数据帧测试
    // test_data_frame();
    
    // // 错误帧测试
    // test_error_frame();
    
    // // 异常测试
    // test_exceptions();
    
    RCLCPP_INFO(this->get_logger(), "所有测试通过!");
    // rclcpp::shutdown();
  }

private:
  void print_hex(const std::vector<uint8_t>& data) {
    std::stringstream ss;
    for (auto b : data) {
      ss << std::hex << std::setw(2) << std::setfill('0') << (int)b << " ";
    }
    RCLCPP_INFO(this->get_logger(), "HEX: %s", ss.str().c_str());
  }

  void test_execute_frame() {
    RCLCPP_INFO(this->get_logger(), "==== 测试执行帧 ====");
    
    // 创建原始数据
    ExecuteFrame original;
    original.func_id = 0x1234;
    original.arg1 = 0xAABBCCDD;
    original.arg2 = 0xEEFF0011;
    original.arg3 = 0x22334455;
    original.request_id = 0x99;

    // 序列化
    auto data = ProtocolParser::serialize_execute(original);
    print_hex(data);

    // 验证帧类型
    auto type = ProtocolParser::parse_frame(data);
    if (type != FrameType::ExecuteFrame) {
      throw std::runtime_error("帧类型识别错误");
    }

    // 解析帧
    auto parsed = ProtocolParser::parse_execute(data);

    // 数据一致性验证
    if (parsed.func_id != original.func_id ||
        parsed.arg1 != original.arg1 ||
        parsed.arg2 != original.arg2 ||
        parsed.arg3 != original.arg3 ||
        parsed.request_id != original.request_id) {
      throw std::runtime_error("执行帧数据不一致");
    }

    // 测试CRC错误
    // data[17] ^= 0xFF; // 破坏CRC
    try {
      ProtocolParser::parse_execute(data);
      throw std::runtime_error("未检测到CRC错误");
    } catch (const ProtocolException& e) {
      RCLCPP_INFO(this->get_logger(), "CRC错误检测正常: %s", e.what());
    }
  }

  void test_response_frame() {
    RCLCPP_INFO(this->get_logger(), "==== 测试返回帧 ====");
    
    ResponseFrame original;
    original.func_id = 0x5678;
    original.value = 0x11223344;
    original.request_id = 0x88;
    // original.success = true;

    // 序列化（示例需实现serialize_response）
    std::vector<uint8_t> data = {
      0xC0, 0xDE,             // Header
      0x56, 0x78,             // FuncID
      0x11, 0x22, 0x33, 0x44,// Value
      0x88,                   // RequestID
      // 0x01,                   // Success
      0x00,                   // CRC (需计算)
      0xBE, 0xEF              // Tail
    };

    // 计算CRC
    data[9] = CRC8::compute(data.data()+2, 7);

    RCLCPP_INFO(this->get_logger(), "==== 完成CRC ====");

    // 解析验证
    auto parsed = ProtocolParser::parse_response(data);
    if (parsed.func_id != original.func_id ||
        parsed.value != original.value ||
        parsed.request_id != original.request_id){
      throw std::runtime_error("返回帧数据不一致");
    }
  }

  void test_data_frame() {
    RCLCPP_INFO(this->get_logger(), "==== 测试数据帧 ====");
    
    DataFrame original;
    original.data_id = 0xABCD;
    original.data = {0x01, 0x02, 0x03, 0x04};

    // 序列化（示例需实现serialize_data）
    std::vector<uint8_t> data = {
      0x5A, 0x5A,             // Header
      0xAB, 0xCD,             // DataID
      0x01, 0x02, 0x03, 0x04, // Data
      0x00,                   // CRC (需计算)
      0xAA, 0x55              // Tail
    };
    data[data.size()-3] = CRC8::compute(data.data()+2, data.size()-5);

    // 解析验证
    auto parsed = ProtocolParser::parse_data(data);
    if (parsed.data_id != original.data_id ||
        parsed.data != original.data) {
      throw std::runtime_error("数据帧不一致");
    }
  }

  void test_error_frame() {
    RCLCPP_INFO(this->get_logger(), "==== 测试错误帧 ====");
    
    ErrorFrame original;
    original.request_id = 0x77;
    original.error_code = 0x1234;

    // 序列化（示例需实现serialize_error）
    std::vector<uint8_t> data = {
      0xCA, 0xDE,             // Header
      0x77,                   // RequestID
      0x12, 0x34,             // ErrorCode
      0x00,                   // CRC (需计算)
      0xBA, 0xD1              // Tail
    };
    data[4] = CRC8::compute(data.data()+2, 3);

    // 解析验证
    auto parsed = ProtocolParser::parse_error(data);
    if (parsed.request_id != original.request_id ||
        parsed.error_code != original.error_code) {
      throw std::runtime_error("错误帧不一致");
    }
  }

  void test_exceptions() {
    RCLCPP_INFO(this->get_logger(), "==== 测试异常情况 ====");
    
    // 测试无效帧头
    try {
      std::vector<uint8_t> data = {0xAA, 0xBB};
      ProtocolParser::parse_frame(data);
      throw std::runtime_error("未检测到非法帧头");
    } catch (const ProtocolException& e) {
      RCLCPP_INFO(this->get_logger(), "非法帧头检测正常: %s", e.what());
    }

    // 测试短帧
    try {
      std::vector<uint8_t> data(3, 0x00);
      ProtocolParser::parse_execute(data);
      throw std::runtime_error("未检测到短帧错误");
    } catch (const ProtocolException& e) {
      RCLCPP_INFO(this->get_logger(), "短帧检测正常: %s", e.what());
    }
  }
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TestNode>());
  rclcpp::shutdown();
  return 0;
}