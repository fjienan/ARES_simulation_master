## 1. 帧结构

`cmd_vel` 命令在通信时使用的是**执行帧**格式，其结构如下：

```
+--------+--------+--------+--------+--------+--------+--------+--------+
| 帧头(2字节) | 功能ID(2字节)|        参数1(4字节)      |        参数2(4字节)      |
+--------+--------+--------+--------+--------+--------+--------+--------+
|        参数3(4字节)      | 请求ID(1字节) | CRC(1字节) |     帧尾(2字节)        |
+--------+--------+--------+--------+--------+--------+--------+--------+
```

详细说明：
1. **帧头**: 固定值 `0xCAFE`，表示这是一个执行帧
2. **功能ID**: 用于区分不同功能，对于速度控制，通常使用 `0x0001`（大端序）
3. **参数1**: 线速度X分量 (float值，直接使用浮点数，小端序)
4. **参数2**: 线速度Y分量 (float值，直接使用浮点数，小端序)
5. **参数3**: 角速度Z分量 (float值，直接使用浮点数，小端序)
6. **请求ID**: 用于标识不同的请求，每次递增，范围0-255
7. **CRC**: CRC-8校验值，计算范围是从功能ID到请求ID (字节2-16)
8. **帧尾**: 固定值 `0xBABE`，表示执行帧结束

总共 **20字节**。

## 3. 速度值表示

程序中直接使用ROS中的速度值（浮点数格式），不再进行整数转换：

1. 线速度X：直接使用`msg->linear.x`的float值（单位：m/s）
2. 线速度Y：直接使用`msg->linear.y`的float值（单位：m/s）
3. 角速度Z：直接使用`msg->angular.z`的float值（单位：rad/s）

例如：
- 线速度 0.1 m/s 将作为浮点数0.1直接发送
- 角速度 0.2 rad/s 将作为浮点数0.2直接发送

## 4. 下位机解析示例代码

下面是用C语言解析执行帧的示例代码：

```c
#include <stdint.h>
#include <stdbool.h>

// 执行帧结构体
typedef struct {
    uint16_t func_id;
    float linear_x;
    float linear_y;
    float angular_z;
    uint8_t request_id;
} ExecuteFrame;

// CRC-8计算函数 (根据您的算法实现)
uint8_t calculate_crc8(const uint8_t* data, int length) {
    // 这里实现您的CRC-8算法
    // ...
}

// 解析执行帧
bool parse_execute_frame(const uint8_t* data, int length, ExecuteFrame* frame) {
    // 检查基本长度
    if (length < 20) {
        return false;
    }
    
    // 检查帧头
    if (data[0] != 0xCA || data[1] != 0xFE) {
        return false;
    }
    
    // 检查帧尾
    if (data[18] != 0xBA || data[19] != 0xBE) {
        return false;
    }
    
    // 计算CRC
    uint8_t expected_crc = calculate_crc8(&data[2], 15);
    if (data[17] != expected_crc) {
        return false;
    }
    
    // 提取功能ID (大端序)
    frame->func_id = (data[2] << 8) | data[3];
    
    // 检查功能ID是否为速度控制 (通常为0x0001)
    if (frame->func_id != 0x0001) {
        return false;
    }
    
    // 提取参数 (小端序) - 直接读取浮点数
    memcpy(&frame->linear_x, &data[4], sizeof(float));
    memcpy(&frame->linear_y, &data[8], sizeof(float));
    memcpy(&frame->angular_z, &data[12], sizeof(float));
    
    // 提取请求ID
    frame->request_id = data[16];
    
    return true;
}

// 处理速度命令
void process_velocity_command(const ExecuteFrame* frame) {
    // 直接使用浮点数值控制电机
    float linear_x = frame->linear_x;
    float linear_y = frame->linear_y;
    float angular_z = frame->angular_z;
    
    // 使用这些速度值控制电机...
    // motor_control_set_velocity(linear_x, linear_y, angular_z);
}

// 主循环中使用
void process_received_data(const uint8_t* data, int length) {
    ExecuteFrame frame;
    if (parse_execute_frame(data, length, &frame)) {
        process_velocity_command(&frame);
    }
}
```

## 5. 注意事项

1. **字节序**: 
   - 功能ID使用大端序 (高位在前)
   - 线速度和角速度参数使用小端序 (低位在前)，直接传输IEEE-754浮点数

2. **返回帧**: 
   - 下位机收到速度命令后，可以发送一个响应帧，包含执行结果
   - 响应帧格式: `0xC0DE + 功能ID + 值(小端序) + 请求ID + CRC + 0xBEEF`
   - 但通常速度控制命令不需要等待响应帧

3. **频率设置**:
   - 当前代码中，速度控制命令以每秒20次的频率发送 (50ms间隔)
   - 下位机应能以相同或更高的频率处理这些命令

4. **异常处理**:
   - 当cmd_vel停止发送时，下位机应有超时机制停止机器人移动
   - 推荐超时时间: 200-500ms

## 6. 示例数据

以下是一个典型的cmd_vel执行帧示例（浮点数值：线速度X=0.1 m/s，线速度Y=0 m/s，角速度Z=0.2 rad/s）:

```
发送执行帧: CA FE 00 01 CD CC CC 3D 00 00 00 00 CD CC 4C 3E 01 2B BA BE
```

解析:
- 帧头: `0xCAFE`
- 功能ID: `0x0001` (速度控制，大端序)
- 参数1: `0x3DCCCCCD` (小端序，IEEE-754浮点数表示的0.1)
- 参数2: `0x00000000` (小端序，IEEE-754浮点数表示的0.0)
- 参数3: `0x3E4CCCCD` (小端序，IEEE-754浮点数表示的0.2)
- 请求ID: `0x01`
- CRC: `0x2B`
- 帧尾: `0xBABE` 