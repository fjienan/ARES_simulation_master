// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ares_comm:srv/Execute.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__SRV__DETAIL__EXECUTE__BUILDER_HPP_
#define ARES_COMM__SRV__DETAIL__EXECUTE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ares_comm/srv/detail/execute__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ares_comm
{

namespace srv
{

namespace builder
{

class Init_Execute_Request_request_id
{
public:
  explicit Init_Execute_Request_request_id(::ares_comm::srv::Execute_Request & msg)
  : msg_(msg)
  {}
  ::ares_comm::srv::Execute_Request request_id(::ares_comm::srv::Execute_Request::_request_id_type arg)
  {
    msg_.request_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ares_comm::srv::Execute_Request msg_;
};

class Init_Execute_Request_arg3
{
public:
  explicit Init_Execute_Request_arg3(::ares_comm::srv::Execute_Request & msg)
  : msg_(msg)
  {}
  Init_Execute_Request_request_id arg3(::ares_comm::srv::Execute_Request::_arg3_type arg)
  {
    msg_.arg3 = std::move(arg);
    return Init_Execute_Request_request_id(msg_);
  }

private:
  ::ares_comm::srv::Execute_Request msg_;
};

class Init_Execute_Request_arg2
{
public:
  explicit Init_Execute_Request_arg2(::ares_comm::srv::Execute_Request & msg)
  : msg_(msg)
  {}
  Init_Execute_Request_arg3 arg2(::ares_comm::srv::Execute_Request::_arg2_type arg)
  {
    msg_.arg2 = std::move(arg);
    return Init_Execute_Request_arg3(msg_);
  }

private:
  ::ares_comm::srv::Execute_Request msg_;
};

class Init_Execute_Request_arg1
{
public:
  explicit Init_Execute_Request_arg1(::ares_comm::srv::Execute_Request & msg)
  : msg_(msg)
  {}
  Init_Execute_Request_arg2 arg1(::ares_comm::srv::Execute_Request::_arg1_type arg)
  {
    msg_.arg1 = std::move(arg);
    return Init_Execute_Request_arg2(msg_);
  }

private:
  ::ares_comm::srv::Execute_Request msg_;
};

class Init_Execute_Request_func_id
{
public:
  Init_Execute_Request_func_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Execute_Request_arg1 func_id(::ares_comm::srv::Execute_Request::_func_id_type arg)
  {
    msg_.func_id = std::move(arg);
    return Init_Execute_Request_arg1(msg_);
  }

private:
  ::ares_comm::srv::Execute_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ares_comm::srv::Execute_Request>()
{
  return ares_comm::srv::builder::Init_Execute_Request_func_id();
}

}  // namespace ares_comm


namespace ares_comm
{

namespace srv
{

namespace builder
{

class Init_Execute_Response_value
{
public:
  explicit Init_Execute_Response_value(::ares_comm::srv::Execute_Response & msg)
  : msg_(msg)
  {}
  ::ares_comm::srv::Execute_Response value(::ares_comm::srv::Execute_Response::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ares_comm::srv::Execute_Response msg_;
};

class Init_Execute_Response_success
{
public:
  Init_Execute_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Execute_Response_value success(::ares_comm::srv::Execute_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Execute_Response_value(msg_);
  }

private:
  ::ares_comm::srv::Execute_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ares_comm::srv::Execute_Response>()
{
  return ares_comm::srv::builder::Init_Execute_Response_success();
}

}  // namespace ares_comm

#endif  // ARES_COMM__SRV__DETAIL__EXECUTE__BUILDER_HPP_
