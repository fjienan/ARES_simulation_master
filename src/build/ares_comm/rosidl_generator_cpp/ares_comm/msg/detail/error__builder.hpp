// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ares_comm:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__MSG__DETAIL__ERROR__BUILDER_HPP_
#define ARES_COMM__MSG__DETAIL__ERROR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ares_comm/msg/detail/error__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ares_comm
{

namespace msg
{

namespace builder
{

class Init_Error_error_code
{
public:
  explicit Init_Error_error_code(::ares_comm::msg::Error & msg)
  : msg_(msg)
  {}
  ::ares_comm::msg::Error error_code(::ares_comm::msg::Error::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ares_comm::msg::Error msg_;
};

class Init_Error_request_id
{
public:
  Init_Error_request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Error_error_code request_id(::ares_comm::msg::Error::_request_id_type arg)
  {
    msg_.request_id = std::move(arg);
    return Init_Error_error_code(msg_);
  }

private:
  ::ares_comm::msg::Error msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ares_comm::msg::Error>()
{
  return ares_comm::msg::builder::Init_Error_request_id();
}

}  // namespace ares_comm

#endif  // ARES_COMM__MSG__DETAIL__ERROR__BUILDER_HPP_
