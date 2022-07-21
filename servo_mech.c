
// Include Wire Library for I2C Communications
#include <Wire.h> 
 
// Include Adafruit PWM Library
#include <Adafruit_PWMServoDriver.h>
 
#define MIN_PULSE_WIDTH       500
#define MAX_PULSE_WIDTH       2500
#define FREQUENCY             50
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
 
// Define Potentiometer Inputs
 
int potInA = A0;
int potInB = A1;
int potInC = A2;
int potInD = A3;
 
// Define servo-motor outputs on PCA9685 board
 
int servoA = 0;
int servoB = 4;
int servoC = 8;
int servoD = 12;
 
void setup() 
{
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}
 
 
void move_servo(int potInX, int servoX)
{
  int pulse_wide, pulse_width, potVal;
  
  // Read values from potentiometer

  potVal = analogRead(potInX);
  
  // Convert to pulse width
  pulse_wide = map(potVal, 0, 1023, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  
  //Control Motor
  pwm.setPWM(servoX, 0, pulse_width);
 
}
 
void loop() {
 
  //Control Motor A
  move_servo(potInA, servoA);
  
  //Control Motor B
  move_servo(potInB, servoB);
    
  //Control Motor C
  move_servo(potInC, servoC);
  
  //Control Motor D
  move_servo(potInD, servoD);
 
 
}