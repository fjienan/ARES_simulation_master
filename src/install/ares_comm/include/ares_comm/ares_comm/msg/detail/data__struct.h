// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ares_comm:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__MSG__DETAIL__DATA__STRUCT_H_
#define ARES_COMM__MSG__DETAIL__DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Data in the package ares_comm.
/**
  * 对应协议中的同步数据帧(0x5A5A开头)
 */
typedef struct ares_comm__msg__Data
{
  /// 2字节数据标识符 (对应协议中的Data ID)
  uint16_t data_id;
  /// 可变长度数据载荷 (最长22字节)
  rosidl_runtime_c__uint8__Sequence data;
} ares_comm__msg__Data;

// Struct for a sequence of ares_comm__msg__Data.
typedef struct ares_comm__msg__Data__Sequence
{
  ares_comm__msg__Data * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ares_comm__msg__Data__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARES_COMM__MSG__DETAIL__DATA__STRUCT_H_
