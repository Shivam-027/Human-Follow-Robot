#include <NewPing.h>
#include <Servo.h>
#include <AFMotor.h>

#define RIGHT_SENSOR A2
#define LEFT_SENSOR A3
#define SONAR_TRIGGER A1
#define SONAR_ECHO A0
#define MAX_DETECTION_DISTANCE 200

unsigned int currentDistance = 0;
unsigned int rightSensorValue = 0;
unsigned int leftSensorValue = 0;

NewPing sonar(SONAR_TRIGGER, SONAR_ECHO, MAX_DETECTION_DISTANCE);

AF_DCMotor motorFrontLeft(1, MOTOR12_1KHZ);
AF_DCMotor motorFrontRight(2, MOTOR12_1KHZ);
AF_DCMotor motorBackLeft(3, MOTOR34_1KHZ);
AF_DCMotor motorBackRight(4, MOTOR34_1KHZ);

Servo servoMotor;
int servoPosition = 0;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(10);
  for (servoPosition = 90; servoPosition <= 180; servoPosition += 1) {
    servoMotor.write(servoPosition);
    delay(15);
  }
  for (servoPosition = 180; servoPosition >= 0; servoPosition -= 1) {
    servoMotor.write(servoPosition);
    delay(15);
  }
  for (servoPosition = 0; servoPosition <= 90; servoPosition += 1) {
    servoMotor.write(servoPosition);
    delay(15);
  }
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(LEFT_SENSOR, INPUT);
}

void loop() {
  delay(50);
  currentDistance = sonar.ping_cm();
  Serial.print("Distance: ");
  Serial.println(currentDistance);

  rightSensorValue = digitalRead(RIGHT_SENSOR);
  leftSensorValue = digitalRead(LEFT_SENSOR);
  Serial.print("Right Sensor: ");
  Serial.println(rightSensorValue);
  Serial.print("Left Sensor: ");
  Serial.println(leftSensorValue);

  if ((currentDistance > 1) && (currentDistance < 15)) {
    motorFrontLeft.setSpeed(130);
    motorFrontLeft.run(FORWARD);
    motorFrontRight.setSpeed(130);
    motorFrontRight.run(FORWARD);
    motorBackLeft.setSpeed(130);
    motorBackLeft.run(FORWARD);
    motorBackRight.setSpeed(130);
    motorBackRight.run(FORWARD);
  } else if ((rightSensorValue == 0) && (leftSensorValue == 1)) {
    motorFrontLeft.setSpeed(150);
    motorFrontLeft.run(FORWARD);
    motorFrontRight.setSpeed(150);
    motorFrontRight.run(FORWARD);
    motorBackLeft.setSpeed(150);
    motorBackLeft.run(BACKWARD);
    motorBackRight.setSpeed(150);
    motorBackRight.run(BACKWARD);
    delay(150);
  } else if ((rightSensorValue == 1) && (leftSensorValue == 0)) {
    motorFrontLeft.setSpeed(150);
    motorFrontLeft.run(BACKWARD);
    motorFrontRight.setSpeed(150);
    motorFrontRight.run(BACKWARD);
    motorBackLeft.setSpeed(150);
    motorBackLeft.run(FORWARD);
    motorBackRight.setSpeed(150);
    motorBackRight.run(FORWARD);
    delay(150);
  } else if (currentDistance > 15) {
    motorFrontLeft.setSpeed(0);
    motorFrontLeft.run(RELEASE);
    motorFrontRight.setSpeed(0);
    motorFrontRight.run(RELEASE);
    motorBackLeft.setSpeed(0);
    motorBackLeft.run(RELEASE);
    motorBackRight.setSpeed(0);
    motorBackRight.run(RELEASE);
  }
}
