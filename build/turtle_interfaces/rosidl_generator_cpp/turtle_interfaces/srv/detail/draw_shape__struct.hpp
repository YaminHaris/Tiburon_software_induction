// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_interfaces:srv/DrawShape.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACES__SRV__DETAIL__DRAW_SHAPE__STRUCT_HPP_
#define TURTLE_INTERFACES__SRV__DETAIL__DRAW_SHAPE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtle_interfaces__srv__DrawShape_Request __attribute__((deprecated))
#else
# define DEPRECATED__turtle_interfaces__srv__DrawShape_Request __declspec(deprecated)
#endif

namespace turtle_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DrawShape_Request_
{
  using Type = DrawShape_Request_<ContainerAllocator>;

  explicit DrawShape_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shape = "";
      this->size = 0.0f;
    }
  }

  explicit DrawShape_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : shape(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shape = "";
      this->size = 0.0f;
    }
  }

  // field types and members
  using _shape_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _shape_type shape;
  using _size_type =
    float;
  _size_type size;

  // setters for named parameter idiom
  Type & set__shape(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->shape = _arg;
    return *this;
  }
  Type & set__size(
    const float & _arg)
  {
    this->size = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_interfaces__srv__DrawShape_Request
    std::shared_ptr<turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_interfaces__srv__DrawShape_Request
    std::shared_ptr<turtle_interfaces::srv::DrawShape_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DrawShape_Request_ & other) const
  {
    if (this->shape != other.shape) {
      return false;
    }
    if (this->size != other.size) {
      return false;
    }
    return true;
  }
  bool operator!=(const DrawShape_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DrawShape_Request_

// alias to use template instance with default allocator
using DrawShape_Request =
  turtle_interfaces::srv::DrawShape_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_interfaces


#ifndef _WIN32
# define DEPRECATED__turtle_interfaces__srv__DrawShape_Response __attribute__((deprecated))
#else
# define DEPRECATED__turtle_interfaces__srv__DrawShape_Response __declspec(deprecated)
#endif

namespace turtle_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DrawShape_Response_
{
  using Type = DrawShape_Response_<ContainerAllocator>;

  explicit DrawShape_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit DrawShape_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_interfaces__srv__DrawShape_Response
    std::shared_ptr<turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_interfaces__srv__DrawShape_Response
    std::shared_ptr<turtle_interfaces::srv::DrawShape_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DrawShape_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const DrawShape_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DrawShape_Response_

// alias to use template instance with default allocator
using DrawShape_Response =
  turtle_interfaces::srv::DrawShape_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace turtle_interfaces

namespace turtle_interfaces
{

namespace srv
{

struct DrawShape
{
  using Request = turtle_interfaces::srv::DrawShape_Request;
  using Response = turtle_interfaces::srv::DrawShape_Response;
};

}  // namespace srv

}  // namespace turtle_interfaces

#endif  // TURTLE_INTERFACES__SRV__DETAIL__DRAW_SHAPE__STRUCT_HPP_
