// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ares_comm:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__MSG__DETAIL__ERROR__STRUCT_HPP_
#define ARES_COMM__MSG__DETAIL__ERROR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ares_comm__msg__Error __attribute__((deprecated))
#else
# define DEPRECATED__ares_comm__msg__Error __declspec(deprecated)
#endif

namespace ares_comm
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Error_
{
  using Type = Error_<ContainerAllocator>;

  explicit Error_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request_id = 0;
      this->error_code = 0;
    }
  }

  explicit Error_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request_id = 0;
      this->error_code = 0;
    }
  }

  // field types and members
  using _request_id_type =
    uint8_t;
  _request_id_type request_id;
  using _error_code_type =
    uint16_t;
  _error_code_type error_code;

  // setters for named parameter idiom
  Type & set__request_id(
    const uint8_t & _arg)
  {
    this->request_id = _arg;
    return *this;
  }
  Type & set__error_code(
    const uint16_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ares_comm::msg::Error_<ContainerAllocator> *;
  using ConstRawPtr =
    const ares_comm::msg::Error_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ares_comm::msg::Error_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ares_comm::msg::Error_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ares_comm::msg::Error_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ares_comm::msg::Error_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ares_comm::msg::Error_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ares_comm::msg::Error_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ares_comm::msg::Error_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ares_comm::msg::Error_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ares_comm__msg__Error
    std::shared_ptr<ares_comm::msg::Error_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ares_comm__msg__Error
    std::shared_ptr<ares_comm::msg::Error_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Error_ & other) const
  {
    if (this->request_id != other.request_id) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    return true;
  }
  bool operator!=(const Error_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Error_

// alias to use template instance with default allocator
using Error =
  ares_comm::msg::Error_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ares_comm

#endif  // ARES_COMM__MSG__DETAIL__ERROR__STRUCT_HPP_
