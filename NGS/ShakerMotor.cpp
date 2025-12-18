/*
* Function definitions for shaker motor drive functions
* Created by Trevor Seyfried, 2025
*/

#include "ShakerMotor.h"
#include <Arduino.h>

// Scale of the PW from 0-255
const int PWM_width_low = 75;
const int PWM_width_med = 150;
const int PWM_width_high = 220;

const int FlipperHoldCount = 10; //Consecutive readings required to register the flipper as pressed

const int MotorOutputPin = 8;
const int LeftFlipperInputPin = 10;
const int RightFlipperInputPin = 12;

int leftFlipperPressCount = 0;
int rightFlipperPressCount = 0;
unsigned long MotorStopTime = 0;
ShakerIntensity CurrentIntensity;

void InitShakerMotor()
{
    pinMode(MotorOutputPin, OUTPUT);
    pinMode(LeftFlipperInputPin, INPUT_PULLUP);
    pinMode(RightFlipperInputPin, INPUT_PULLUP);
}

void ProcessShakerMotor(unsigned long CurrentTime)
{
    int PWMWidth = 0;

    if (CurrentTime <= MotorStopTime)
    {
        switch (CurrentIntensity)
        {
            case SHAKER_LOW:
                PWMWidth = PWM_width_low;
                break;
            case SHAKER_MED:
                PWMWidth = PWM_width_med;
                break;
            case SHAKER_HIGH:
                PWMWidth = PWM_width_high;
                break;
            default:
                PWMWidth = 0;
                break;
        }
    }

    analogWrite(MotorOutputPin, PWMWidth);
}

void RunShakerMotor(unsigned long currentTime, ShakerIntensity intensity, unsigned long durationMs)
{
    MotorStopTime = currentTime + durationMs;
    CurrentIntensity = intensity;
}

bool LeftFlipperButtonPressed()
{
    return (digitalRead(LeftFlipperInputPin) == LOW);

    /*
    bool readHigh = (digitalRead(LeftFlipperInputPin) == HIGH);
    if (readHigh) 
    {
        leftFlipperPressCount++;
    }
    else
    {
        leftFlipperPressCount = 0;
    }

    return (leftFlipperPressCount >= FlipperHoldCount);
    */
}

bool RightFlipperButtonPressed()
{
    return (digitalRead(RightFlipperInputPin) == LOW);

    /*
    bool readHigh = (digitalRead(LeftFlipperInputPin) == HIGH);
    if (readHigh) 
    {
        rightFlipperPressCount++;
    }
    else
    {
        rightFlipperPressCount = 0;
    }

    return (rightFlipperPressCount >= FlipperHoldCount);
    */
}