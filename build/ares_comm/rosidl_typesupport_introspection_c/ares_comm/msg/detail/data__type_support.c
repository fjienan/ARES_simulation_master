// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ares_comm:msg/Data.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ares_comm/msg/detail/data__rosidl_typesupport_introspection_c.h"
#include "ares_comm/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ares_comm/msg/detail/data__functions.h"
#include "ares_comm/msg/detail/data__struct.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ares_comm__msg__Data__init(message_memory);
}

void ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_fini_function(void * message_memory)
{
  ares_comm__msg__Data__fini(message_memory);
}

size_t ares_comm__msg__Data__rosidl_typesupport_introspection_c__size_function__Data__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * ares_comm__msg__Data__rosidl_typesupport_introspection_c__get_const_function__Data__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ares_comm__msg__Data__rosidl_typesupport_introspection_c__get_function__Data__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void ares_comm__msg__Data__rosidl_typesupport_introspection_c__fetch_function__Data__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ares_comm__msg__Data__rosidl_typesupport_introspection_c__get_const_function__Data__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ares_comm__msg__Data__rosidl_typesupport_introspection_c__assign_function__Data__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ares_comm__msg__Data__rosidl_typesupport_introspection_c__get_function__Data__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool ares_comm__msg__Data__rosidl_typesupport_introspection_c__resize_function__Data__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_message_member_array[2] = {
  {
    "data_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ares_comm__msg__Data, data_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ares_comm__msg__Data, data),  // bytes offset in struct
    NULL,  // default value
    ares_comm__msg__Data__rosidl_typesupport_introspection_c__size_function__Data__data,  // size() function pointer
    ares_comm__msg__Data__rosidl_typesupport_introspection_c__get_const_function__Data__data,  // get_const(index) function pointer
    ares_comm__msg__Data__rosidl_typesupport_introspection_c__get_function__Data__data,  // get(index) function pointer
    ares_comm__msg__Data__rosidl_typesupport_introspection_c__fetch_function__Data__data,  // fetch(index, &value) function pointer
    ares_comm__msg__Data__rosidl_typesupport_introspection_c__assign_function__Data__data,  // assign(index, value) function pointer
    ares_comm__msg__Data__rosidl_typesupport_introspection_c__resize_function__Data__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_message_members = {
  "ares_comm__msg",  // message namespace
  "Data",  // message name
  2,  // number of fields
  sizeof(ares_comm__msg__Data),
  ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_message_member_array,  // message members
  ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_init_function,  // function to initialize message memory (memory has to be allocated)
  ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_message_type_support_handle = {
  0,
  &ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ares_comm
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ares_comm, msg, Data)() {
  if (!ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_message_type_support_handle.typesupport_identifier) {
    ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ares_comm__msg__Data__rosidl_typesupport_introspection_c__Data_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
