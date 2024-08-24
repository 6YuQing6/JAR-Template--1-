#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 12;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */
// digital_out Claw = digital_out(Brain.ThreeWirePort.A);

void tank_odom_test(){
  chassis.drive_distance(10);
  // Brain.Screen.print("stuff 2");
  // odom_constants();
  // Brain.Screen.print("stuff 3");
  // chassis.set_coordinates(0, 0, 0);
  // chassis.drive_distance(10);
  // Brain.Screen.print("stuff 4");
  // chassis.turn_to_point(0,-10);
  // chassis.turn_to_point(24, 24);
  // chassis.drive_to_point(24,24);
  // chassis.drive_to_point(0,0);
  // chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}

void auton_red_left() {
  // chassis.set_coordinates(-50, 23, 90);
  // Claw.set(true); //change later after sayansh tests it
  // chassis.drive_to_point(-23.5, 23.5);
  // //Get the mobile goal
  // Claw.set(false);
  // chasis.turnFor(-90, degrees);
  // chassis.drive_to_point(-23.776, 40.5);
  // chassis.turnFor(180, degrees);
  // chassis.drive_to_point(-23.8, 32.4);
  // chassis.turnFor(-120, degrees);
  // chassis.drive_to_point(-11.6, 38.7);
  // chassis.turnFor(150, degrees);
  // chassis.drive_to_point(-10.7, 12.5);
}

void auton_blue_right() {
  chassis.set_coordinates(-50, 23, 90);
  Claw.set(true); //change later after sayansh tests it
  chassis.drive_to_point(-23.5, 23.5);
  //Get the mobile goal
  // Claw.set(false);
  // chasis.turnFor(-90, degrees);
  // chassis.drive_to_point(-23.776, 40.5);
  // chassis.turnFor(180, degrees);
  // chassis.drive_to_point(-23.8, 32.4);
  // chassis.turnFor(-120, degrees);
  // chassis.drive_to_point(-11.6, 38.7);
  // chassis.turnFor(150, degrees);
  // chassis.drive_to_point(-10.7, 12.5);
}


//skills functions


void firstStake() {
  chassis.set_coordinates(-150, 0, 0);
  chassis.turn_to_point(-171, 45);
  chassis.drive_to_point(-120, -62);
  Claw.set(true);
  Intake.spin(forward, 100, pct);
  chassis.drive_to_point(-62, -62);
  chassis.turn_to_point(-60, -120);
  chassis.drive_to_point(-60, -120);
  chassis.turn_to_point(-120, -120);
  chassis.drive_to_point(-120, -120);

  chassis.drive_to_point(-150, -120);
  chassis.turn_to_point(-120, -150);
  chassis.drive_to_point(-120, -150);
  chassis.turn_to_point(0, -150);
  chassis.drive_to_point(0, -150);
  chassis.turn_to_point(-150, -150);
  chassis.drive_to_point(-150, -150);
  chassis.turn_to_point(-120, -120);
  Claw.set(false);
}


void secondStake() {
  chassis.drive_to_point(-120, -61);
  chassis.turn_to_point(-120, -120);
  chassis.drive_to_point(-120, 61);
  Claw.set(true);
  Intake.spin(forward, 100, pct);
  chassis.turn_to_point(-60, 60);
  chassis.drive_to_point(-60, 60);
  chassis.turn_to_point(-60, 120);
  chassis.drive_to_point(-60, 120);
  chassis.turn_to_point(-120, 120);
  chassis.drive_to_point(-120, 120);
  chassis.drive_to_point(-150, 120);
  chassis.turn_to_point(-120, 150);
  chassis.drive_to_point(-120, 150);
  chassis.turn_to_point(0, 150);
  chassis.drive_to_point(0, 150);
  chassis.turn_to_point(-155, 155);
  chassis.drive_to_point(-155, 155);
  chassis.turn_to_point(-120, -120);
  Claw.set(false);
}

void thirdStake() {
  chassis.turn_to_point(116, 75);
  chassis.drive_to_point(116, 75);
  chassis.turn_to_point(118, 100);
  chassis.drive_to_point(120, 0);
  Claw.set(true);
  chassis.turn_to_point(60, -60);
  chassis.drive_to_point(60, -60);
  chassis.turn_to_point(60, -120);
  chassis.drive_to_point(60, -120);
  chassis.turn_to_point(130, -120);
  chassis.drive_to_point(130, -120);
  chassis.turn_to_point(113, -160);
  chassis.drive_to_point(113, -160);
  chassis.turn_to_point(82, -160);
  chassis.drive_to_point(160, 166);
  Claw.set(false);
}

void hang() {
  chassis.turn_to_point(30, -30);
  chassis.drive_to_point(30, -30); 
}

void autonomous_one_minute() {
  firstStake();
  secondStake();
  thirdStake();
  hang();
}

