#include <Servo.h>

// 28BYJ-48 Stepper Motor with ULN2003 Driver and Arduino Nano - Dual Motors

// Motor 1 Connections (12T Step Motor)
const int IN1_M1 = 8;
const int IN2_M1 = 9;
const int IN3_M1 = 10;
const int IN4_M1 = 11;

// Motor 2 Connections (Standard 28BYJ-48)
const int IN1_M2 = 4;
const int IN2_M2 = 5;
const int IN3_M2 = 6;
const int IN4_M2 = 7;

// Step sequence for full-step mode
int fullStepSequence[4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};

// Steps per revolution for each motor
const int STEPS_PER_REVOLUTION_M1 = 3096; // Adjust for your 12T motor
const int STEPS_PER_REVOLUTION_M2 = 3096; // Standard 28BYJ-48

// Servo Motor
Servo myServo;
const int servoPin = 3;

// Servo variables
int servoPosition = 0; // Initial position
int servoDirection = 1; // 1 for increasing, -1 for decreasing
unsigned long servoLastMoveTime = 0;
const long servoMoveInterval = 15; // Time between servo steps (adjust for speed)
const int minAngle = 0; // Minimum angle (0 degrees)
const int maxAngle = 90; // Maximum angle (90 degrees)

void setup() {
  // Motor 1 Pins
  pinMode(IN1_M1, OUTPUT);
  pinMode(IN2_M1, OUTPUT);
  pinMode(IN3_M1, OUTPUT);
  pinMode(IN4_M1, OUTPUT);

  // Motor 2 Pins
  pinMode(IN1_M2, OUTPUT);
  pinMode(IN2_M2, OUTPUT);
  pinMode(IN3_M2, OUTPUT);
  pinMode(IN4_M2, OUTPUT);

  // Servo Motor
  myServo.attach(servoPin);
  myServo.write(servoPosition); // Initial servo position
  servoLastMoveTime = millis();
}

void stepMotor(int in1, int in2, int in3, int in4, int step) {
  digitalWrite(in1, fullStepSequence[step][0]);
  digitalWrite(in2, fullStepSequence[step][1]);
  digitalWrite(in3, fullStepSequence[step][2]);
  digitalWrite(in4, fullStepSequence[step][3]);
}

void loop() {
  // Motor 1 and Motor 2 forward rotation
  for (int i = 0; i < STEPS_PER_REVOLUTION_M1; i++) {
    for (int j = 0; j < 4; j++) {
      stepMotor(IN1_M1, IN2_M1, IN3_M1, IN4_M1, j);
      stepMotor(IN1_M2, IN2_M2, IN3_M2, IN4_M2, j);
      delay(4); // Adjusted delay for moderate speed
    }
  }
  delay(50); // Reduced pause after forward rotation

  // Motor 1 and Motor 2 reverse rotation
  for (int i = 0; i < STEPS_PER_REVOLUTION_M1; i++) {
    for (int j = 3; j >= 0; j--) {
      stepMotor(IN1_M1, IN2_M1, IN3_M1, IN4_M1, j);
      stepMotor(IN1_M2, IN2_M2, IN3_M2, IN4_M2, j);
      delay(4); // Adjusted delay for moderate speed
    }
  }
  delay(50); // Reduced pause after reverse rotation

  // Servo movement (continuous)
  if (millis() - servoLastMoveTime >= servoMoveInterval) {
    // Update servo position
    servoPosition += servoDirection;

    // Reverse direction at limits (without pausing)
    if (servoPosition >= maxAngle) {
      servoPosition = maxAngle;
      servoDirection = -1;
    } else if (servoPosition <= minAngle) {
      servoPosition = minAngle;
      servoDirection = 1;
    }

    // Write the new position to the servo
    myServo.write(servoPosition);
    servoLastMoveTime = millis();
  }
}
