// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ares_comm:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__MSG__DETAIL__ERROR__TRAITS_HPP_
#define ARES_COMM__MSG__DETAIL__ERROR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ares_comm/msg/detail/error__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ares_comm
{

namespace msg
{

inline void to_flow_style_yaml(
  const Error & msg,
  std::ostream & out)
{
  out << "{";
  // member: request_id
  {
    out << "request_id: ";
    rosidl_generator_traits::value_to_yaml(msg.request_id, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Error & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: request_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "request_id: ";
    rosidl_generator_traits::value_to_yaml(msg.request_id, out);
    out << "\n";
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Error & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ares_comm

namespace rosidl_generator_traits
{

[[deprecated("use ares_comm::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ares_comm::msg::Error & msg,
  std::ostream & out, size_t indentation = 0)
{
  ares_comm::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ares_comm::msg::to_yaml() instead")]]
inline std::string to_yaml(const ares_comm::msg::Error & msg)
{
  return ares_comm::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ares_comm::msg::Error>()
{
  return "ares_comm::msg::Error";
}

template<>
inline const char * name<ares_comm::msg::Error>()
{
  return "ares_comm/msg/Error";
}

template<>
struct has_fixed_size<ares_comm::msg::Error>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ares_comm::msg::Error>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ares_comm::msg::Error>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARES_COMM__MSG__DETAIL__ERROR__TRAITS_HPP_
