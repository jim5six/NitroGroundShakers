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
void ProcessShakerMotor(unsigned long CurrentTime);

//Start the shaker for a specific time and intensity.
void RunShakerMotor(unsigned long CurrentTime, ShakerIntensity intensity, unsigned long durationMs);