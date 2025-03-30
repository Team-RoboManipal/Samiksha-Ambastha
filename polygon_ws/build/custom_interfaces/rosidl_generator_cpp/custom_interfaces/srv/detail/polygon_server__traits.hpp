// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/PolygonServer.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__POLYGON_SERVER__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__POLYGON_SERVER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/polygon_server__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PolygonServer_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: sides
  {
    out << "sides: ";
    rosidl_generator_traits::value_to_yaml(msg.sides, out);
    out << ", ";
  }

  // member: side_length
  {
    out << "side_length: ";
    rosidl_generator_traits::value_to_yaml(msg.side_length, out);
    out << ", ";
  }

  // member: angular_speed
  {
    out << "angular_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PolygonServer_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sides
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sides: ";
    rosidl_generator_traits::value_to_yaml(msg.sides, out);
    out << "\n";
  }

  // member: side_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "side_length: ";
    rosidl_generator_traits::value_to_yaml(msg.side_length, out);
    out << "\n";
  }

  // member: angular_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PolygonServer_Request & msg, bool use_flow_style = false)
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

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::PolygonServer_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::PolygonServer_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::PolygonServer_Request>()
{
  return "custom_interfaces::srv::PolygonServer_Request";
}

template<>
inline const char * name<custom_interfaces::srv::PolygonServer_Request>()
{
  return "custom_interfaces/srv/PolygonServer_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::PolygonServer_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::srv::PolygonServer_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::srv::PolygonServer_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PolygonServer_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PolygonServer_Response & msg,
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

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PolygonServer_Response & msg, bool use_flow_style = false)
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

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::PolygonServer_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::PolygonServer_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::PolygonServer_Response>()
{
  return "custom_interfaces::srv::PolygonServer_Response";
}

template<>
inline const char * name<custom_interfaces::srv::PolygonServer_Response>()
{
  return "custom_interfaces/srv/PolygonServer_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::PolygonServer_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::PolygonServer_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::PolygonServer_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::PolygonServer>()
{
  return "custom_interfaces::srv::PolygonServer";
}

template<>
inline const char * name<custom_interfaces::srv::PolygonServer>()
{
  return "custom_interfaces/srv/PolygonServer";
}

template<>
struct has_fixed_size<custom_interfaces::srv::PolygonServer>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::PolygonServer_Request>::value &&
    has_fixed_size<custom_interfaces::srv::PolygonServer_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::PolygonServer>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::PolygonServer_Request>::value &&
    has_bounded_size<custom_interfaces::srv::PolygonServer_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::PolygonServer>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::PolygonServer_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::PolygonServer_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__POLYGON_SERVER__TRAITS_HPP_
