#include "ares_comm/serial_interface.hpp"
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <thread>
#include <atomic>

using namespace std::chrono_literals;

class SerialTestNode : public rclcpp::Node {
public:
  SerialTestNode() : Node("serial_test_node"), running_(true) {
    // 参数配置
    declare_parameter<std::string>("port", "/dev/ttyACM1");
    declare_parameter<int>("baudrate", 115200);
    
    // 获取参数
    const auto port = get_parameter("port").as_string();
    const auto baudrate = get_parameter("baudrate").as_int();

    try {
      // 初始化串口
      serial_ = ares_comm::SerialInterface::create(port, baudrate);
      RCLCPP_INFO(this->get_logger(), "串口初始化成功: %s", port.c_str());
      
      // 启动发送线程
      tx_thread_ = std::thread(&SerialTestNode::tx_worker, this);
      
      // 启动接收线程
      rx_thread_ = std::thread(&SerialTestNode::rx_worker, this);
      
    } catch (const ares_comm::SerialException& e) {
      RCLCPP_FATAL(this->get_logger(), "初始化失败: %s", e.what());
      rclcpp::shutdown();
    }
  }

  ~SerialTestNode() {
    running_ = false;
    if(tx_thread_.joinable()) tx_thread_.join();
    if(rx_thread_.joinable()) rx_thread_.join();
  }

private:
  void tx_worker() {
    const std::vector<uint8_t> test_data{'H','e','l','l','o',' ','W','o','r','l','d','!'};
    
    while(running_ && rclcpp::ok()) {
      try {
        serial_->write(test_data);
        RCLCPP_INFO(this->get_logger(), "成功发送 %zu 字节", test_data.size());
        std::this_thread::sleep_for(1s);
      } catch (const ares_comm::SerialException& e) {
        RCLCPP_ERROR(this->get_logger(), "发送失败: %s", e.what());
      }
    }
  } 

  void rx_worker() {
    while(running_ && rclcpp::ok()) {
      try {
        auto frame = serial_->read_frame();
        RCLCPP_INFO(this->get_logger(), "收到数据 [%zu字节]:", frame.size());
        
        // 打印ASCII和十六进制格式
        std::string ascii_str(frame.begin(), frame.end());
        std::string hex_str;
        for(auto& b : frame) {
          hex_str += std::to_string(static_cast<int>(b)) + " ";
        }
        
        RCLCPP_INFO(this->get_logger(), "ASCII: %s", ascii_str.c_str());
        RCLCPP_INFO(this->get_logger(), "HEX: %s\n", hex_str.c_str());
        
      } catch (const ares_comm::SerialException& e) {
        RCLCPP_WARN(this->get_logger(), "接收错误: %s", e.what());
      }
    }
  }

  std::atomic<bool> running_;
  std::thread tx_thread_;
  std::thread rx_thread_;
  std::unique_ptr<ares_comm::SerialInterface> serial_;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SerialTestNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}