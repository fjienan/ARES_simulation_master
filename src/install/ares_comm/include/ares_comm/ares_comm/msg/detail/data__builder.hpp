// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ares_comm:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__MSG__DETAIL__DATA__BUILDER_HPP_
#define ARES_COMM__MSG__DETAIL__DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ares_comm/msg/detail/data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ares_comm
{

namespace msg
{

namespace builder
{

class Init_Data_data
{
public:
  explicit Init_Data_data(::ares_comm::msg::Data & msg)
  : msg_(msg)
  {}
  ::ares_comm::msg::Data data(::ares_comm::msg::Data::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ares_comm::msg::Data msg_;
};

class Init_Data_data_id
{
public:
  Init_Data_data_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Data_data data_id(::ares_comm::msg::Data::_data_id_type arg)
  {
    msg_.data_id = std::move(arg);
    return Init_Data_data(msg_);
  }

private:
  ::ares_comm::msg::Data msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ares_comm::msg::Data>()
{
  return ares_comm::msg::builder::Init_Data_data_id();
}

}  // namespace ares_comm

#endif  // ARES_COMM__MSG__DETAIL__DATA__BUILDER_HPP_
