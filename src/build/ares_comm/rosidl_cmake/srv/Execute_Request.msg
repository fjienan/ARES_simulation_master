# 服务请求结构（对应发送帧）
uint16 func_id    # 2字节功能码 (协议中的Func ID)
uint32 arg1       # 4字节参数1
uint32 arg2       # 4字节参数2
uint32 arg3       # 4字节参数3
uint8 request_id  # 1字节请求ID (用于匹配响应)
