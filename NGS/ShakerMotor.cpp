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

const int MotorOutputPin = 8;
const int LeftFlipperInputPin = 10;
const int RightFlipperInputPin = 12;

unsigned long MotorStopTime = 0;
ShakerIntensity CurrentIntensity;
// Ramp mode state
unsigned long RampStartTime = 0;
bool RampActive = false;
ShakerIntensity RampPeakIntensity;

void InitShakerMotor()
{
    pinMode(MotorOutputPin, OUTPUT);
    pinMode(LeftFlipperInputPin, INPUT_PULLUP);
    pinMode(RightFlipperInputPin, INPUT_PULLUP);
}

void ProcessShakerMotor(unsigned long currentTime)
{
    int PWMWidth = 0;

    // If a ramp is active, compute a parabolic envelope that starts low,
    // accelerates to a peak at the midpoint, then decays back down.
    if (RampActive && currentTime <= MotorStopTime)
    {
        unsigned long elapsed = currentTime - RampStartTime;
        unsigned long duration = MotorStopTime - RampStartTime; // durationMs

        // Protect against divide-by-zero and negative durations
        if (duration == 0)
        {
            PWMWidth = 0;
        }
        else
        {
            // normalized time t in [0,1]
            float t = (float)elapsed / (float)duration;
            if (t < 0.0f) t = 0.0f;
            if (t > 1.0f) t = 1.0f;

            // Parabolic envelope: f(t) = 4 * t * (1 - t)
            // peaks at t=0.5 with value 1. Starts and ends at 0.
            float envelope = 4.0f * t * (1.0f - t);

            int peakPWM = 0;
            switch (RampPeakIntensity)
            {
                case SHAKER_LOW: peakPWM = PWM_width_low; break;
                case SHAKER_MED: peakPWM = PWM_width_med; break;
                case SHAKER_HIGH: peakPWM = PWM_width_high; break;
                default: peakPWM = 0; break;
            }

            // Apply envelope to peak PWM. Optionally add a tiny floor to "start low" but nonzero.
            PWMWidth = (int)(envelope * (float)peakPWM + 0.5f);
            if (PWMWidth < 0) PWMWidth = 0;
            if (PWMWidth > 255) PWMWidth = 255;
        }
    }
    else
    {
        //Regular motor drive
        if (currentTime <= MotorStopTime)
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
    }

    analogWrite(MotorOutputPin, PWMWidth);
}

void RunShakerMotor(unsigned long currentTime, ShakerIntensity intensity, unsigned long durationMs)
{
    RampActive = false;
    MotorStopTime = currentTime + durationMs;
    CurrentIntensity = intensity;
}
void RampShakerMotor(unsigned long currentTime, ShakerIntensity peakIntensity, unsigned long durationMs)
{
    // Start a parabolic ramp that lasts durationMs and peaks at the provided intensity.
    if (durationMs == 0)
    {
        // nothing to do
        return;
    }

    RampStartTime = currentTime;
    MotorStopTime = currentTime + durationMs;
    RampPeakIntensity = peakIntensity;
    RampActive = true;
}

bool LeftFlipperButtonPressed()
{
    return (digitalRead(LeftFlipperInputPin) == HIGH);
}

bool RightFlipperButtonPressed()
{
    return (digitalRead(RightFlipperInputPin) == HIGH);
}