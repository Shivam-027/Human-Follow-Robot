# Human-Follow-Robot

## Description

The Human Follow Robot is an Arduino-based project designed to follow a human or object using ultrasonic distance measurement and sensor feedback. The system employs a combination of servo and DC motors to navigate the robot and follow the human or object based on real-time sensor data. The robot is equipped with a servo motor to perform scanning operations and four DC motors to control its movement. The ultrasonic sensor measures the distance to obstacles, while the IR sensors help in making directional decisions.

## Language Used

- **C/C++**: The project is implemented using the Arduino programming language, which is a subset of C/C++. The code utilizes various Arduino libraries to interface with sensors and motors.

## Components Used

- **Arduino Board**: The central microcontroller used for processing and control.
- **Ultrasonic Distance Sensor**: Measures the distance to obstacles.
- **DC Motors**: Four DC motors are used to drive the robot's wheels.
- **Servo Motor**: Used for scanning or positioning tasks.
- **IR Sensors**: IR sensors for right and left side detection.
  
- **NewPing Library**: For interfacing with the ultrasonic distance sensor.
- **AFMotor Library**: For controlling DC motors.
- **Servo Library**: For controlling the servo motor.

## Working

1. **Initialization**: Upon startup, the servo motor performs a sweeping motion from 90 to 180 degrees, then back to 0 degrees, and finally to 90 degrees. This initialization helps in calibrating the servo.

2. **Distance Measurement**: The ultrasonic sensor continuously measures the distance to the nearest human or object. The distance is printed to the Serial Monitor for debugging purposes.

3. **Movement Control**:
   - **Obstacle Detection**: If an object is detected within 15 cm, all four DC motors are activated to move the robot forward.
   - **Directional Movement**:
     - **Right Sensor Active**: If the right IR sensor detects an object while the left sensor does not, the robot will turn left by moving the front motors forward and the back motors backward.
     - **Left Sensor Active**: If the left IR sensor detects an object while the right sensor does not, the robot will turn right by moving the front motors backward and the back motors forward.
   - **No Objects**: If no object is detected within 15 cm, the motors are stopped, and the robot remains stationary.

4. **Servo Control**: The servo motor sweeps through a specified range to assist in scanning or positioning tasks based on the robot's operational needs.

## Setup

1. Connect the ultrasonic sensor to the defined `TRIGGER_PIN` and `ECHO_PIN`.
2. Connect the right and left IR sensors to the corresponding pins.
3. Attach the DC motors and the servo motor to their respective motor drivers and the Arduino.
