// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ares_comm:srv/Execute.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__SRV__DETAIL__EXECUTE__TRAITS_HPP_
#define ARES_COMM__SRV__DETAIL__EXECUTE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ares_comm/srv/detail/execute__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ares_comm
{

namespace srv
{

inline void to_flow_style_yaml(
  const Execute_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: func_id
  {
    out << "func_id: ";
    rosidl_generator_traits::value_to_yaml(msg.func_id, out);
    out << ", ";
  }

  // member: arg1
  {
    out << "arg1: ";
    rosidl_generator_traits::value_to_yaml(msg.arg1, out);
    out << ", ";
  }

  // member: arg2
  {
    out << "arg2: ";
    rosidl_generator_traits::value_to_yaml(msg.arg2, out);
    out << ", ";
  }

  // member: arg3
  {
    out << "arg3: ";
    rosidl_generator_traits::value_to_yaml(msg.arg3, out);
    out << ", ";
  }

  // member: request_id
  {
    out << "request_id: ";
    rosidl_generator_traits::value_to_yaml(msg.request_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Execute_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: func_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "func_id: ";
    rosidl_generator_traits::value_to_yaml(msg.func_id, out);
    out << "\n";
  }

  // member: arg1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg1: ";
    rosidl_generator_traits::value_to_yaml(msg.arg1, out);
    out << "\n";
  }

  // member: arg2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg2: ";
    rosidl_generator_traits::value_to_yaml(msg.arg2, out);
    out << "\n";
  }

  // member: arg3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg3: ";
    rosidl_generator_traits::value_to_yaml(msg.arg3, out);
    out << "\n";
  }

  // member: request_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "request_id: ";
    rosidl_generator_traits::value_to_yaml(msg.request_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Execute_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ares_comm

namespace rosidl_generator_traits
{

[[deprecated("use ares_comm::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ares_comm::srv::Execute_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ares_comm::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ares_comm::srv::to_yaml() instead")]]
inline std::string to_yaml(const ares_comm::srv::Execute_Request & msg)
{
  return ares_comm::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ares_comm::srv::Execute_Request>()
{
  return "ares_comm::srv::Execute_Request";
}

template<>
inline const char * name<ares_comm::srv::Execute_Request>()
{
  return "ares_comm/srv/Execute_Request";
}

template<>
struct has_fixed_size<ares_comm::srv::Execute_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ares_comm::srv::Execute_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ares_comm::srv::Execute_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ares_comm
{

namespace srv
{

inline void to_flow_style_yaml(
  const Execute_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Execute_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Execute_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ares_comm

namespace rosidl_generator_traits
{

[[deprecated("use ares_comm::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ares_comm::srv::Execute_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ares_comm::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ares_comm::srv::to_yaml() instead")]]
inline std::string to_yaml(const ares_comm::srv::Execute_Response & msg)
{
  return ares_comm::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ares_comm::srv::Execute_Response>()
{
  return "ares_comm::srv::Execute_Response";
}

template<>
inline const char * name<ares_comm::srv::Execute_Response>()
{
  return "ares_comm/srv/Execute_Response";
}

template<>
struct has_fixed_size<ares_comm::srv::Execute_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ares_comm::srv::Execute_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ares_comm::srv::Execute_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ares_comm::srv::Execute>()
{
  return "ares_comm::srv::Execute";
}

template<>
inline const char * name<ares_comm::srv::Execute>()
{
  return "ares_comm/srv/Execute";
}

template<>
struct has_fixed_size<ares_comm::srv::Execute>
  : std::integral_constant<
    bool,
    has_fixed_size<ares_comm::srv::Execute_Request>::value &&
    has_fixed_size<ares_comm::srv::Execute_Response>::value
  >
{
};

template<>
struct has_bounded_size<ares_comm::srv::Execute>
  : std::integral_constant<
    bool,
    has_bounded_size<ares_comm::srv::Execute_Request>::value &&
    has_bounded_size<ares_comm::srv::Execute_Response>::value
  >
{
};

template<>
struct is_service<ares_comm::srv::Execute>
  : std::true_type
{
};

template<>
struct is_service_request<ares_comm::srv::Execute_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ares_comm::srv::Execute_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ARES_COMM__SRV__DETAIL__EXECUTE__TRAITS_HPP_
