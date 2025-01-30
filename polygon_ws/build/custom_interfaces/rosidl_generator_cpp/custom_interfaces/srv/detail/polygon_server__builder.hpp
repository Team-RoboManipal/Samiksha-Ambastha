// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/PolygonServer.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__POLYGON_SERVER__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__POLYGON_SERVER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/polygon_server__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_PolygonServer_Request_angular_speed
{
public:
  explicit Init_PolygonServer_Request_angular_speed(::custom_interfaces::srv::PolygonServer_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::PolygonServer_Request angular_speed(::custom_interfaces::srv::PolygonServer_Request::_angular_speed_type arg)
  {
    msg_.angular_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::PolygonServer_Request msg_;
};

class Init_PolygonServer_Request_side_length
{
public:
  explicit Init_PolygonServer_Request_side_length(::custom_interfaces::srv::PolygonServer_Request & msg)
  : msg_(msg)
  {}
  Init_PolygonServer_Request_angular_speed side_length(::custom_interfaces::srv::PolygonServer_Request::_side_length_type arg)
  {
    msg_.side_length = std::move(arg);
    return Init_PolygonServer_Request_angular_speed(msg_);
  }

private:
  ::custom_interfaces::srv::PolygonServer_Request msg_;
};

class Init_PolygonServer_Request_sides
{
public:
  Init_PolygonServer_Request_sides()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PolygonServer_Request_side_length sides(::custom_interfaces::srv::PolygonServer_Request::_sides_type arg)
  {
    msg_.sides = std::move(arg);
    return Init_PolygonServer_Request_side_length(msg_);
  }

private:
  ::custom_interfaces::srv::PolygonServer_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::PolygonServer_Request>()
{
  return custom_interfaces::srv::builder::Init_PolygonServer_Request_sides();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_PolygonServer_Response_message
{
public:
  explicit Init_PolygonServer_Response_message(::custom_interfaces::srv::PolygonServer_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::PolygonServer_Response message(::custom_interfaces::srv::PolygonServer_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::PolygonServer_Response msg_;
};

class Init_PolygonServer_Response_success
{
public:
  Init_PolygonServer_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PolygonServer_Response_message success(::custom_interfaces::srv::PolygonServer_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_PolygonServer_Response_message(msg_);
  }

private:
  ::custom_interfaces::srv::PolygonServer_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::PolygonServer_Response>()
{
  return custom_interfaces::srv::builder::Init_PolygonServer_Response_success();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__POLYGON_SERVER__BUILDER_HPP_
