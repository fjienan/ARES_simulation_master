// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ares_comm:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__MSG__DETAIL__DATA__TRAITS_HPP_
#define ARES_COMM__MSG__DETAIL__DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ares_comm/msg/detail/data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ares_comm
{

namespace msg
{

inline void to_flow_style_yaml(
  const Data & msg,
  std::ostream & out)
{
  out << "{";
  // member: data_id
  {
    out << "data_id: ";
    rosidl_generator_traits::value_to_yaml(msg.data_id, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Data & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_id: ";
    rosidl_generator_traits::value_to_yaml(msg.data_id, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Data & msg, bool use_flow_style = false)
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
  const ares_comm::msg::Data & msg,
  std::ostream & out, size_t indentation = 0)
{
  ares_comm::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ares_comm::msg::to_yaml() instead")]]
inline std::string to_yaml(const ares_comm::msg::Data & msg)
{
  return ares_comm::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ares_comm::msg::Data>()
{
  return "ares_comm::msg::Data";
}

template<>
inline const char * name<ares_comm::msg::Data>()
{
  return "ares_comm/msg/Data";
}

template<>
struct has_fixed_size<ares_comm::msg::Data>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ares_comm::msg::Data>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ares_comm::msg::Data>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARES_COMM__MSG__DETAIL__DATA__TRAITS_HPP_
