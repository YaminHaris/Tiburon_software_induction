// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/DrawShape.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DRAW_SHAPE__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__DRAW_SHAPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/srv/detail/draw_shape__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DrawShape_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: shape
  {
    out << "shape: ";
    rosidl_generator_traits::value_to_yaml(msg.shape, out);
    out << ", ";
  }

  // member: size
  {
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DrawShape_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: shape
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shape: ";
    rosidl_generator_traits::value_to_yaml(msg.shape, out);
    out << "\n";
  }

  // member: size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DrawShape_Request & msg, bool use_flow_style = false)
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

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::DrawShape_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::DrawShape_Request & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::DrawShape_Request>()
{
  return "interfaces::srv::DrawShape_Request";
}

template<>
inline const char * name<interfaces::srv::DrawShape_Request>()
{
  return "interfaces/srv/DrawShape_Request";
}

template<>
struct has_fixed_size<interfaces::srv::DrawShape_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::srv::DrawShape_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::srv::DrawShape_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DrawShape_Response & msg,
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
  const DrawShape_Response & msg,
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

inline std::string to_yaml(const DrawShape_Response & msg, bool use_flow_style = false)
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

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::DrawShape_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::DrawShape_Response & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::DrawShape_Response>()
{
  return "interfaces::srv::DrawShape_Response";
}

template<>
inline const char * name<interfaces::srv::DrawShape_Response>()
{
  return "interfaces/srv/DrawShape_Response";
}

template<>
struct has_fixed_size<interfaces::srv::DrawShape_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::srv::DrawShape_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::srv::DrawShape_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::DrawShape>()
{
  return "interfaces::srv::DrawShape";
}

template<>
inline const char * name<interfaces::srv::DrawShape>()
{
  return "interfaces/srv/DrawShape";
}

template<>
struct has_fixed_size<interfaces::srv::DrawShape>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::DrawShape_Request>::value &&
    has_fixed_size<interfaces::srv::DrawShape_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::DrawShape>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::DrawShape_Request>::value &&
    has_bounded_size<interfaces::srv::DrawShape_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::DrawShape>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::DrawShape_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::DrawShape_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__DRAW_SHAPE__TRAITS_HPP_
