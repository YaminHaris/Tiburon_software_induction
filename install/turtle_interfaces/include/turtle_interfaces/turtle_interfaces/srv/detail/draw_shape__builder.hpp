// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_interfaces:srv/DrawShape.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__SRV__DETAIL__DRAW_SHAPE__BUILDER_HPP_
#define TURTLE_INTERFACES__SRV__DETAIL__DRAW_SHAPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_interfaces/srv/detail/draw_shape__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_interfaces
{

namespace srv
{

namespace builder
{

class Init_DrawShape_Request_size
{
public:
  explicit Init_DrawShape_Request_size(::turtle_interfaces::srv::DrawShape_Request & msg)
  : msg_(msg)
  {}
  ::turtle_interfaces::srv::DrawShape_Request size(::turtle_interfaces::srv::DrawShape_Request::_size_type arg)
  {
    msg_.size = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_interfaces::srv::DrawShape_Request msg_;
};

class Init_DrawShape_Request_shape
{
public:
  Init_DrawShape_Request_shape()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DrawShape_Request_size shape(::turtle_interfaces::srv::DrawShape_Request::_shape_type arg)
  {
    msg_.shape = std::move(arg);
    return Init_DrawShape_Request_size(msg_);
  }

private:
  ::turtle_interfaces::srv::DrawShape_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_interfaces::srv::DrawShape_Request>()
{
  return turtle_interfaces::srv::builder::Init_DrawShape_Request_shape();
}

}  // namespace turtle_interfaces


namespace turtle_interfaces
{

namespace srv
{

namespace builder
{

class Init_DrawShape_Response_message
{
public:
  explicit Init_DrawShape_Response_message(::turtle_interfaces::srv::DrawShape_Response & msg)
  : msg_(msg)
  {}
  ::turtle_interfaces::srv::DrawShape_Response message(::turtle_interfaces::srv::DrawShape_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_interfaces::srv::DrawShape_Response msg_;
};

class Init_DrawShape_Response_success
{
public:
  Init_DrawShape_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DrawShape_Response_message success(::turtle_interfaces::srv::DrawShape_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_DrawShape_Response_message(msg_);
  }

private:
  ::turtle_interfaces::srv::DrawShape_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_interfaces::srv::DrawShape_Response>()
{
  return turtle_interfaces::srv::builder::Init_DrawShape_Response_success();
}

}  // namespace turtle_interfaces

#endif  // TURTLE_INTERFACES__SRV__DETAIL__DRAW_SHAPE__BUILDER_HPP_
