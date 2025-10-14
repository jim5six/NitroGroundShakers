// Lamp, Switch and coil definitions

// Lamp Definitions
#if (RPU_MPU_ARCHITECTURE<10)
#define LAMP_BONUS_L1                       0
#define LAMP_BONUS_L2                       1
#define LAMP_BONUS_L3                       2
#define LAMP_BONUS_L4                       3
#define LAMP_BONUS_L5                       4
#define LAMP_BONUS_L6                       5
#define LAMP_BONUS_L7                       6
#define LAMP_BONUS_L8                       7
#define LAMP_BONUS_L9                       8
#define LAMP_BONUS_L10                      9
#define LAMP_BONUS_L20                      10
#define LAMP_BONUS_SPINNER                  11
#define LAMP_BONUS_R1                       12
#define LAMP_BONUS_R2                       13
#define LAMP_BONUS_R3                       14
#define LAMP_BONUS_R4                       15
#define LAMP_BONUS_R5                       16
#define LAMP_BONUS_R6                       17
#define LAMP_BONUS_R7                       18
#define LAMP_BONUS_R8                       19
#define LAMP_BONUS_R9                       20
#define LAMP_BONUS_R10                      21
#define LAMP_BONUS_R20                      22
#define LAMP_CENTER_SPECIAL                 23
#define LAMP_A                              24
#define LAMP_B                              25
#define LAMP_C                              26
#define LAMP_D                              27
#define LAMP_E                              28
#define LAMP_F                              29
#define LAMP_EXTRABALL                      30
#define LAMP_DROP_TARGET_SPECIAL            31
#define LAMP_DROP_TARGET_5000               32

#define LAMP_COLLECT_BONUS_LEFT             34
#define LAMP_COLLECT_BONUS_RIGHT            35
#define LAMP_TOP_ARROW_LEFT                 36
#define LAMP_TOP_ARROW_CENTER               37
#define LAMP_TOP_ARROW_RIGHT                38
#define LAMP_DOUBLE_BONUS_TOP               39
#define LAMP_HEAD_SAME_PLAYER_SHOOTS_AGAIN  40
#define LAMP_SHOOT_AGAIN                    40
#define LAMP_HEAD_BIP                       41
#define LAMP_DOUBLE_BONUS_BOTTOM            42
#define LAMP_APRON_CREDIT                   43
#define LAMP_SUPER_BONUS                    44
#define LAMP_NITRO_BONUS                    45
#define LAMP_ARROW_ADD_LR_BONUS             46
#define LAMP_POP_BUMPER                     47
#define LAMP_HEAD_MATCH                     48 //?
#define LAMP_HEAD_HIGH_SCORE                49
#define LAMP_HEAD_GAME_OVER                 50
#define LAMP_HEAD_TILT                      51
#define LAMP_R_OUTLANE_SPECIAL              52
#define LAMP_L_OUTLANE_SPECIAL              53

#define LAMP_HEAD_PLAYER_1_UP               56
#define LAMP_HEAD_PLAYER_2_UP               57
#define LAMP_HEAD_PLAYER_3_UP               58
#define LAMP_HEAD_PLAYER_4_UP               59
#endif

// Switch Definitions
#if (RPU_MPU_ARCHITECTURE<10)
#define SW_                          0 //?
#define SW_                          1 //?
#define SW_                          2 //?
#define SW_                          3 //?
#define SW_RUBBER                    4 //?
#define SW_CREDIT_RESET              5
// Different definitions for Tilt so I can have the same
// code for different architectures
#define SW_TILT                      6 //?
#define SW_PLUMB_TILT                6 //?
#define SW_ROLL_TILT                 6 //?
#define SW_OUTHOLE                   7 //?
#define SW_COIN_1                    8 //?
#define SW_COIN_2                    9 //?
#define SW_COIN_3                   10 //?
#define SW_SLAM                     15 //?
#define SW_PLAYFIELD_TILT           15 //?

#define SW_DROP_TARGET1             11 //TOP
#define SW_DROP_TARGET2             12
#define SW_DROP_TARGET3             13
#define SW_DROP_TARGET4             14

#define SW_RIGHT_INLANE             17
#define SW_LEFT_INLANE              18
#define SW_D_TARGET                 19
#define SW_C_TARGET                 20
#define SW_B_LANE                   21
#define SW_A_LANE                   22
#define SW_CENTER_SAUCER            23
#define SW_SPINNER                  24

#define SW_LEFT_SAUCER              31
#define SW_RIGHT_OUTLANE            32
#define SW_LEFT_OUTLANE             33
#define SW_TARGET_ADVANCE_LR_BONUS  34
#define SW_BOTTOM_POP               35
#define SW_RIGHT_SLING              36
#define SW_LEFT_SLING               37
#define SW_RIGHT_POP                38
#define SW_LEFT_POP                 39
#endif

// Coil Definitions
#define SOL_KNOCKER                 5
#define SOL_OUTHOLE                 6
#define SOL_LEFT_SAUCER             7
#define SOL_CENTER_SAUCER           8
#define SOL_LEFT_POP_BUMPER         9
#define SOL_RIGHT_POP_BUMPER        10
#define SOL_LEFT_SLING              11
#define SOL_RIGHT_SLING             12
#define SOL_BOTTOM_POP_BUMPER       13
#define SOL_DROP_TARGET_RESET       14
#define SOLCONT_COIN_LOCKOUT        99 //unknown



#if (RPU_MPU_ARCHITECTURE<10)
// Machines with a -17, -35, 100, and 200 architecture
// almost always have software based switch-triggered solenoids. 
// For those, you can define an array of solenoids and the switches
// that will trigger them:

#define NUM_SWITCHES_WITH_TRIGGERS          5 // total number of solenoid/switch pairs
#define NUM_PRIORITY_SWITCHES_WITH_TRIGGERS 5 // This number should match the define above

struct PlayfieldAndCabinetSwitch SolenoidAssociatedSwitches[] = {
  { SW_RIGHT_SLING, SOL_RIGHT_SLING, 4},
  { SW_LEFT_SLING, SOL_LEFT_SLING, 4},
  { SW_BOTTOM_POP, SOL_BOTTOM_POP_BUMPER, 4},
  { SW_RIGHT_POP, SOL_RIGHT_POP_BUMPER, 4},
  { SW_LEFT_POP, SOL_LEFT_POP_BUMPER, 4}
};
#endif