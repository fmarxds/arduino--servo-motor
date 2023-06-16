#include <Arduino.h>
#include <Servo.h>

#define SERVO 9
#define JOYSTICK_SW 2
#define JOYSTICK_X A4
#define JOYSTICK_Y A5

Servo servoMotor;

const int close = 170;
const int open = 90;

void setup() {
    pinMode(JOYSTICK_SW, INPUT_PULLUP);
    pinMode(JOYSTICK_X, INPUT);
    pinMode(JOYSTICK_Y, INPUT);
    servoMotor.attach(SERVO);
}

void loop() {

    int joystickSw = digitalRead(JOYSTICK_SW);
    int joystickX = analogRead(JOYSTICK_X);
    int joystickY = analogRead(JOYSTICK_Y);

    int servoNewValue = map(joystickX, 0, 1023, close, open);

    servoMotor.write(servoNewValue);

    delay(10);

}