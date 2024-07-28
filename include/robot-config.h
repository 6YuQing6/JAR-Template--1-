using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;
extern controller Controller1;
extern motor Intake;
extern motor Arm;
extern digital_out Claw;
extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;
extern smartdrive DriveTrain;

//Add your devices below, and don't forget to do the same in robot-config.cpp:



void  vexcodeInit( void );