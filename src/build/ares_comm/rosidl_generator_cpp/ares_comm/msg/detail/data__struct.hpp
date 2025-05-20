// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ares_comm:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__MSG__DETAIL__DATA__STRUCT_HPP_
#define ARES_COMM__MSG__DETAIL__DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ares_comm__msg__Data __attribute__((deprecated))
#else
# define DEPRECATED__ares_comm__msg__Data __declspec(deprecated)
#endif

namespace ares_comm
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Data_
{
  using Type = Data_<ContainerAllocator>;

  explicit Data_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data_id = 0;
    }
  }

  explicit Data_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data_id = 0;
    }
  }

  // field types and members
  using _data_id_type =
    uint16_t;
  _data_id_type data_id;
  using _data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data_id(
    const uint16_t & _arg)
  {
    this->data_id = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ares_comm::msg::Data_<ContainerAllocator> *;
  using ConstRawPtr =
    const ares_comm::msg::Data_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ares_comm::msg::Data_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ares_comm::msg::Data_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ares_comm::msg::Data_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ares_comm::msg::Data_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ares_comm::msg::Data_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ares_comm::msg::Data_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ares_comm::msg::Data_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ares_comm::msg::Data_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ares_comm__msg__Data
    std::shared_ptr<ares_comm::msg::Data_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ares_comm__msg__Data
    std::shared_ptr<ares_comm::msg::Data_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Data_ & other) const
  {
    if (this->data_id != other.data_id) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const Data_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Data_

// alias to use template instance with default allocator
using Data =
  ares_comm::msg::Data_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ares_comm

#endif  // ARES_COMM__MSG__DETAIL__DATA__STRUCT_HPP_
