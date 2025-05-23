# 下位机通信测试工具

这个Python脚本用于向下位机发送执行帧并接收响应。使用您提供的代码将参数打包成执行帧，发送到下位机，然后接收并解析下位机返回的响应帧。

## 安装依赖

首先安装所需的Python依赖：

```bash
pip install -r requirements.txt
```

## 使用方法

```bash
python3 send_to_lower_machine.py <串口设备> [波特率]
```

例如：

```bash
python3 send_to_lower_machine.py /dev/ttyUSB0 115200
```

## 发送的数据

脚本将发送以下参数构成的执行帧：

- 功能ID: 0x0001 (速度命令)
- 参数1: 0x1234
- 参数2: 0x5678
- 参数3: 0x9ABC
- 请求ID: 0xDE

## 输出内容

脚本会输出：

1. 发送的执行帧（十六进制格式）
2. 接收到的响应帧（十六进制格式）
3. 响应帧的解析结果

### 正常响应帧解析

如果接收到正常响应帧，将显示：
- 功能ID
- 返回值
- 请求ID
- CRC值

### 错误帧解析

如果接收到错误帧，将显示：
- 请求ID
- 错误码和对应的错误描述

## 注意事项

- 需要正确的串口权限，可能需要使用 `sudo` 运行脚本
- 确保下位机已经连接到指定串口并且已经启动

```
