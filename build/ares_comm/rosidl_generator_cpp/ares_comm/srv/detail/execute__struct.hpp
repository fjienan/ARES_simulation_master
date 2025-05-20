// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ares_comm:srv/Execute.idl
// generated code does not contain a copyright notice

#ifndef ARES_COMM__SRV__DETAIL__EXECUTE__STRUCT_HPP_
#define ARES_COMM__SRV__DETAIL__EXECUTE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ares_comm__srv__Execute_Request __attribute__((deprecated))
#else
# define DEPRECATED__ares_comm__srv__Execute_Request __declspec(deprecated)
#endif

namespace ares_comm
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Execute_Request_
{
  using Type = Execute_Request_<ContainerAllocator>;

  explicit Execute_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->func_id = 0;
      this->arg1 = 0ul;
      this->arg2 = 0ul;
      this->arg3 = 0ul;
      this->request_id = 0;
    }
  }

  explicit Execute_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->func_id = 0;
      this->arg1 = 0ul;
      this->arg2 = 0ul;
      this->arg3 = 0ul;
      this->request_id = 0;
    }
  }

  // field types and members
  using _func_id_type =
    uint16_t;
  _func_id_type func_id;
  using _arg1_type =
    uint32_t;
  _arg1_type arg1;
  using _arg2_type =
    uint32_t;
  _arg2_type arg2;
  using _arg3_type =
    uint32_t;
  _arg3_type arg3;
  using _request_id_type =
    uint8_t;
  _request_id_type request_id;

  // setters for named parameter idiom
  Type & set__func_id(
    const uint16_t & _arg)
  {
    this->func_id = _arg;
    return *this;
  }
  Type & set__arg1(
    const uint32_t & _arg)
  {
    this->arg1 = _arg;
    return *this;
  }
  Type & set__arg2(
    const uint32_t & _arg)
  {
    this->arg2 = _arg;
    return *this;
  }
  Type & set__arg3(
    const uint32_t & _arg)
  {
    this->arg3 = _arg;
    return *this;
  }
  Type & set__request_id(
    const uint8_t & _arg)
  {
    this->request_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ares_comm::srv::Execute_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ares_comm::srv::Execute_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ares_comm::srv::Execute_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ares_comm::srv::Execute_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ares_comm::srv::Execute_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ares_comm::srv::Execute_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ares_comm::srv::Execute_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ares_comm::srv::Execute_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ares_comm::srv::Execute_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ares_comm::srv::Execute_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ares_comm__srv__Execute_Request
    std::shared_ptr<ares_comm::srv::Execute_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ares_comm__srv__Execute_Request
    std::shared_ptr<ares_comm::srv::Execute_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Execute_Request_ & other) const
  {
    if (this->func_id != other.func_id) {
      return false;
    }
    if (this->arg1 != other.arg1) {
      return false;
    }
    if (this->arg2 != other.arg2) {
      return false;
    }
    if (this->arg3 != other.arg3) {
      return false;
    }
    if (this->request_id != other.request_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Execute_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Execute_Request_

// alias to use template instance with default allocator
using Execute_Request =
  ares_comm::srv::Execute_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ares_comm


#ifndef _WIN32
# define DEPRECATED__ares_comm__srv__Execute_Response __attribute__((deprecated))
#else
# define DEPRECATED__ares_comm__srv__Execute_Response __declspec(deprecated)
#endif

namespace ares_comm
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Execute_Response_
{
  using Type = Execute_Response_<ContainerAllocator>;

  explicit Execute_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->value = 0ul;
    }
  }

  explicit Execute_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->value = 0ul;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _value_type =
    uint32_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__value(
    const uint32_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ares_comm::srv::Execute_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ares_comm::srv::Execute_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ares_comm::srv::Execute_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ares_comm::srv::Execute_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ares_comm::srv::Execute_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ares_comm::srv::Execute_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ares_comm::srv::Execute_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ares_comm::srv::Execute_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ares_comm::srv::Execute_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ares_comm::srv::Execute_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ares_comm__srv__Execute_Response
    std::shared_ptr<ares_comm::srv::Execute_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ares_comm__srv__Execute_Response
    std::shared_ptr<ares_comm::srv::Execute_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Execute_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Execute_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Execute_Response_

// alias to use template instance with default allocator
using Execute_Response =
  ares_comm::srv::Execute_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ares_comm

namespace ares_comm
{

namespace srv
{

struct Execute
{
  using Request = ares_comm::srv::Execute_Request;
  using Response = ares_comm::srv::Execute_Response;
};

}  // namespace srv

}  // namespace ares_comm

#endif  // ARES_COMM__SRV__DETAIL__EXECUTE__STRUCT_HPP_
