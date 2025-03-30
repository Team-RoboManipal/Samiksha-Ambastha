// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:srv/PolygonServer.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__POLYGON_SERVER__STRUCT_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__POLYGON_SERVER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__PolygonServer_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__PolygonServer_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PolygonServer_Request_
{
  using Type = PolygonServer_Request_<ContainerAllocator>;

  explicit PolygonServer_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sides = 0l;
      this->side_length = 0.0f;
      this->angular_speed = 0.0f;
    }
  }

  explicit PolygonServer_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sides = 0l;
      this->side_length = 0.0f;
      this->angular_speed = 0.0f;
    }
  }

  // field types and members
  using _sides_type =
    int32_t;
  _sides_type sides;
  using _side_length_type =
    float;
  _side_length_type side_length;
  using _angular_speed_type =
    float;
  _angular_speed_type angular_speed;

  // setters for named parameter idiom
  Type & set__sides(
    const int32_t & _arg)
  {
    this->sides = _arg;
    return *this;
  }
  Type & set__side_length(
    const float & _arg)
  {
    this->side_length = _arg;
    return *this;
  }
  Type & set__angular_speed(
    const float & _arg)
  {
    this->angular_speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__PolygonServer_Request
    std::shared_ptr<custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__PolygonServer_Request
    std::shared_ptr<custom_interfaces::srv::PolygonServer_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PolygonServer_Request_ & other) const
  {
    if (this->sides != other.sides) {
      return false;
    }
    if (this->side_length != other.side_length) {
      return false;
    }
    if (this->angular_speed != other.angular_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const PolygonServer_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PolygonServer_Request_

// alias to use template instance with default allocator
using PolygonServer_Request =
  custom_interfaces::srv::PolygonServer_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__PolygonServer_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__PolygonServer_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PolygonServer_Response_
{
  using Type = PolygonServer_Response_<ContainerAllocator>;

  explicit PolygonServer_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit PolygonServer_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__PolygonServer_Response
    std::shared_ptr<custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__PolygonServer_Response
    std::shared_ptr<custom_interfaces::srv::PolygonServer_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PolygonServer_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const PolygonServer_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PolygonServer_Response_

// alias to use template instance with default allocator
using PolygonServer_Response =
  custom_interfaces::srv::PolygonServer_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace srv
{

struct PolygonServer
{
  using Request = custom_interfaces::srv::PolygonServer_Request;
  using Response = custom_interfaces::srv::PolygonServer_Response;
};

}  // namespace srv

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__POLYGON_SERVER__STRUCT_HPP_
