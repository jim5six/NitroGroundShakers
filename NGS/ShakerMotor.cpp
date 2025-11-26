/*
* Function definitions for shaker motor drive functions
* Created by Trevor Seyfried, 2025
*/

#include "ShakerMotor.h"
#include <Arduino.h>

// Scale of the PW from 0-255
const int PWM_width_low = 100;
const int PWM_width_med = 150;
const int PWM_width_high = 175;

const int MotorOutputPin = 8;

unsigned long MotorStopTime = 0;
ShakerIntensity CurrentIntensity;

void InitShakerMotor()
{
    pinMode(MotorOutputPin, OUTPUT);
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