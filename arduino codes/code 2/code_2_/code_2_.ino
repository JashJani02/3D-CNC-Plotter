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
const int STEPS_PER_REVOLUTION_M1 = 4096; // Adjust for your 12T motor
const int STEPS_PER_REVOLUTION_M2 = 4096; // Standard 28BYJ-48

// Servo Motor
Servo myServo;
const int servoPin = 3; // Choose an available pin

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
  myServo.write(90); // Initial servo position (90 degrees)
}

void stepMotor(int in1, int in2, int in3, int in4, int step) {
  digitalWrite(in1, fullStepSequence[step][0]);
  digitalWrite(in2, fullStepSequence[step][1]);
  digitalWrite(in3, fullStepSequence[step][2]);
  digitalWrite(in4, fullStepSequence[step][3]);
}

void loop() {
  // Motor 1 and Motor 2 forward rotation
  for (int i = 0; i < STEPS_PER_REVOLUTION_M1; i++) { //motor 1 steps.
    for (int j = 0; j < 4; j++) {
      stepMotor(IN1_M1, IN2_M1, IN3_M1, IN4_M1, j); // Motor 1 step
      stepMotor(IN1_M2, IN2_M2, IN3_M2, IN4_M2, j); // Motor 2 step
      delay(4); // Adjusted delay for moderate speed
    }
  }
  delay(500); // Adjusted pause

  // Servo movement
  myServo.write(0); // Move servo to 0 degrees
  delay(1000);

  myServo.write(180); // Move servo to 180 degrees
  delay(1000);

  myServo.write(90); // Return servo to 90 degrees
  delay(500);

  // Motor 1 and Motor 2 reverse rotation
  for (int i = 0; i < STEPS_PER_REVOLUTION_M1; i++) { //motor 1 steps.
    for (int j = 3; j >= 0; j--) {
      stepMotor(IN1_M1, IN2_M1, IN3_M1, IN4_M1, j);
      stepMotor(IN1_M2, IN2_M2, IN3_M2, IN4_M2, j);
      delay(4); // Adjusted delay for moderate speed
    }
  }
  delay(1000); // Adjusted pause
}
