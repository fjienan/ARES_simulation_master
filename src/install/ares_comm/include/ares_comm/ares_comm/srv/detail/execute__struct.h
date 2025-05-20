// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ares_comm:srv/Execute.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__SRV__DETAIL__EXECUTE__STRUCT_H_
#define ARES_COMM__SRV__DETAIL__EXECUTE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Execute in the package ares_comm.
typedef struct ares_comm__srv__Execute_Request
{
  /// 2字节功能码 (协议中的Func ID)
  uint16_t func_id;
  /// 4字节参数1
  uint32_t arg1;
  /// 4字节参数2
  uint32_t arg2;
  /// 4字节参数3
  uint32_t arg3;
  /// 1字节请求ID (用于匹配响应)
  uint8_t request_id;
} ares_comm__srv__Execute_Request;

// Struct for a sequence of ares_comm__srv__Execute_Request.
typedef struct ares_comm__srv__Execute_Request__Sequence
{
  ares_comm__srv__Execute_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ares_comm__srv__Execute_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Execute in the package ares_comm.
typedef struct ares_comm__srv__Execute_Response
{
  /// 操作是否成功
  bool success;
  /// 4字节返回值 (协议中的Value字段)
  uint32_t value;
} ares_comm__srv__Execute_Response;

// Struct for a sequence of ares_comm__srv__Execute_Response.
typedef struct ares_comm__srv__Execute_Response__Sequence
{
  ares_comm__srv__Execute_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ares_comm__srv__Execute_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARES_COMM__SRV__DETAIL__EXECUTE__STRUCT_H_
