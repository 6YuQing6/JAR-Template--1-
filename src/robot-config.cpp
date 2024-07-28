#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;



// A global instance of brain used for printing to the V5 Brain screen.
motor leftDriveA = motor(PORT9, ratio6_1, true);
motor leftDriveB = motor(PORT20, ratio6_1, false); 
motor leftDriveC = motor(PORT5, ratio6_1, true);

motor rightDriveA = motor(PORT10, ratio6_1, false);
motor rightDriveB = motor(PORT6, ratio6_1, true); 
motor rightDriveC = motor(PORT4, ratio6_1, false);

inertial DrivetrainInertial = inertial(PORT8);

controller Controller1 = controller(primary);
brain Brain;

motor Intake = motor(PORT1, ratio6_1, false);
motor Arm = motor(PORT2, ratio6_1, true); 

digital_out Claw = digital_out(Brain.ThreeWirePort.A);

motor_group LeftDriveSmart = motor_group(leftDriveA, leftDriveB, leftDriveC);

motor_group RightDriveSmart = motor_group(rightDriveA, rightDriveB, rightDriveC);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 299.24, 320, 40, mm, 0.6);


/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize
}