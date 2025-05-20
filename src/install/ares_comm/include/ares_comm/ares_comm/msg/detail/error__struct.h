// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ares_comm:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__MSG__DETAIL__ERROR__STRUCT_H_
#define ARES_COMM__MSG__DETAIL__ERROR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Error in the package ares_comm.
/**
  * 对应协议中的错误帧(0xCADE开头)
 */
typedef struct ares_comm__msg__Error
{
  /// 1字节请求标识符 (可能是执行帧或数据帧的ID)
  uint8_t request_id;
  /// 2字节错误码 (使用位掩码组合)
  uint16_t error_code;
} ares_comm__msg__Error;

// Struct for a sequence of ares_comm__msg__Error.
typedef struct ares_comm__msg__Error__Sequence
{
  ares_comm__msg__Error * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ares_comm__msg__Error__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARES_COMM__MSG__DETAIL__ERROR__STRUCT_H_
