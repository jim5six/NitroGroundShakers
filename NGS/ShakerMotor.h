/*
* Function declarations for shaker motor drive functions
* Created by Trevor Seyfried, 2025
*/

enum ShakerIntensity
{
    SHAKER_LOW,
    SHAKER_MED,
    SHAKER_HIGH
};

//Setup the motor driver pin, must be called once on startup
void InitShakerMotor();

//Should be called once every loop. Checks to see if shaker motor should be driven.
void ProcessShakerMotor(unsigned long currentTime);

//Start the shaker for a specific time and intensity.
void RunShakerMotor(unsigned long currentTime, ShakerIntensity intensity, unsigned long durationMs);

//Steadily ramp or "rev" the shaker motor to a peak intensity then back down over a given duration.
void RampShakerMotor(unsigned long currentTime, ShakerIntensity peakIntensity, unsigned long durationMs);

bool LeftFlipperButtonPressed();
bool RightFlipperButtonPressed();