// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ares_comm:srv/Execute.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ares_comm/srv/detail/execute__rosidl_typesupport_introspection_c.h"
#include "ares_comm/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ares_comm/srv/detail/execute__functions.h"
#include "ares_comm/srv/detail/execute__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ares_comm__srv__Execute_Request__init(message_memory);
}

void ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_fini_function(void * message_memory)
{
  ares_comm__srv__Execute_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_message_member_array[5] = {
  {
    "func_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ares_comm__srv__Execute_Request, func_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "arg1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ares_comm__srv__Execute_Request, arg1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "arg2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ares_comm__srv__Execute_Request, arg2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "arg3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ares_comm__srv__Execute_Request, arg3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ares_comm__srv__Execute_Request, request_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_message_members = {
  "ares_comm__srv",  // message namespace
  "Execute_Request",  // message name
  5,  // number of fields
  sizeof(ares_comm__srv__Execute_Request),
  ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_message_member_array,  // message members
  ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_message_type_support_handle = {
  0,
  &ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ares_comm
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ares_comm, srv, Execute_Request)() {
  if (!ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_message_type_support_handle.typesupport_identifier) {
    ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ares_comm__srv__Execute_Request__rosidl_typesupport_introspection_c__Execute_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ares_comm/srv/detail/execute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ares_comm/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ares_comm/srv/detail/execute__functions.h"
// already included above
// #include "ares_comm/srv/detail/execute__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ares_comm__srv__Execute_Response__init(message_memory);
}

void ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_fini_function(void * message_memory)
{
  ares_comm__srv__Execute_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ares_comm__srv__Execute_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ares_comm__srv__Execute_Response, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_message_members = {
  "ares_comm__srv",  // message namespace
  "Execute_Response",  // message name
  2,  // number of fields
  sizeof(ares_comm__srv__Execute_Response),
  ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_message_member_array,  // message members
  ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_message_type_support_handle = {
  0,
  &ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ares_comm
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ares_comm, srv, Execute_Response)() {
  if (!ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_message_type_support_handle.typesupport_identifier) {
    ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ares_comm__srv__Execute_Response__rosidl_typesupport_introspection_c__Execute_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ares_comm/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ares_comm/srv/detail/execute__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ares_comm__srv__detail__execute__rosidl_typesupport_introspection_c__Execute_service_members = {
  "ares_comm__srv",  // service namespace
  "Execute",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // ares_comm__srv__detail__execute__rosidl_typesupport_introspection_c__Execute_Request_message_type_support_handle,
  NULL  // response message
  // ares_comm__srv__detail__execute__rosidl_typesupport_introspection_c__Execute_Response_message_type_support_handle
};

static rosidl_service_type_support_t ares_comm__srv__detail__execute__rosidl_typesupport_introspection_c__Execute_service_type_support_handle = {
  0,
  &ares_comm__srv__detail__execute__rosidl_typesupport_introspection_c__Execute_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ares_comm, srv, Execute_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ares_comm, srv, Execute_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ares_comm
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ares_comm, srv, Execute)() {
  if (!ares_comm__srv__detail__execute__rosidl_typesupport_introspection_c__Execute_service_type_support_handle.typesupport_identifier) {
    ares_comm__srv__detail__execute__rosidl_typesupport_introspection_c__Execute_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ares_comm__srv__detail__execute__rosidl_typesupport_introspection_c__Execute_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ares_comm, srv, Execute_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ares_comm, srv, Execute_Response)()->data;
  }

  return &ares_comm__srv__detail__execute__rosidl_typesupport_introspection_c__Execute_service_type_support_handle;
}
