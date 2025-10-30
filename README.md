````markdown
# Tiburon Software Induction

This repository contains ROS 2 packages and nodes created as part of the Tiburon software induction tasks. It includes various turtle simulation nodes demonstrating service calls, parameter handling, and motion control.

---

## 🧩 Packages Overview

### 1. `turtle_interfaces`
Contains custom service definitions:
- **DrawShape.srv**
  ```plaintext
  string shape
  float32 size
  ---
  bool success
  string message
````

### 2. `turtle_controller`

Implements ROS 2 nodes for turtle control and motion.
Key nodes:

* **draw_shape_service.py** — Draws geometric shapes based on `DrawShape` service requests.
* **spiral_turtle_parameters.py** — Moves the turtle in a dynamic spiral using parameters that can be changed live.

---

## ⚙️ Setup Instructions

### 1. Clone the Repository

```bash
cd ~/ros2_ws/src
git clone https://github.com/YaminHaris/Tiburon_software_induction.git
```

### 2. Build the Workspace

```bash
cd ~/ros2_ws
colcon build
source install/setup.bash
```

---

## 🐢 Nodes and Usage

### 1. **Draw Shape Node**

**Launch the Service Node:**

```bash
ros2 run turtle_controller draw_shape_service
```

**Check Available Services:**

```bash
ros2 service list
```

**Check Service Type:**

```bash
ros2 service type /draw_shape
```

**Call the Service:**

```bash
ros2 service call /draw_shape turtle_interfaces/srv/DrawShape "{shape: 'square', size: 2.0}"
```

---

### 2. **Spiral Turtle with Parameters**

**Run Node:**

```bash
ros2 run turtle_controller spiral_turtle_parameters
```

This node uses two parameters:

* `spiral_linear_velocity`
* `spiral_angular_velocity`

Default values are declared in the node.

**View Parameters:**

```bash
ros2 param list
```

**Check Current Values:**

```bash
ros2 param get /spiral_turtle_parameters spiral_linear_velocity
ros2 param get /spiral_turtle_parameters spiral_angular_velocity
```

**Change Parameter Live:**

```bash
ros2 param set /spiral_turtle_parameters spiral_linear_velocity 3.0
ros2 param set /spiral_turtle_parameters spiral_angular_velocity 5.0
```

The turtle's movement updates instantly without restarting the node.

---

## 🧠 Notes

* Ensure `turtlesim` is running before executing control nodes:

  ```bash
  ros2 run turtlesim turtlesim_node
  ```
* Always source your workspace before running any node:

  ```bash
  source ~/ros2_ws/install/setup.bash
  ```
* Use `rqt_graph` to visualize node and topic connections.

---

## 🧾 Author

**Yamin Haris**
NIT Rourkela | Robotics & Software Development Enthusiast
[GitHub Profile](https://github.com/YaminHaris)

---

## 🛠️ License

MIT License — free to use and modify.
