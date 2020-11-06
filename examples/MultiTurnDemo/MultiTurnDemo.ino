/* 
 *  IQ multi turn serial demo. 
 *  
 *  This code will command a multi turn controller to go to the zero position,
 *  then go to a predefined position, then spin at a constant velocity and 
 *  repeat.
 *  
 *  The circuit:
 *    Arduino RX is directly connected to motor TX
 *    Arduino TX is directly connected to motor RX
 *
 *  For more information about communicating to IQ Motor Modules please go to:
 *  http://iq-control.com/support
 *    
 *  Created       2019/3/6 by Matthew Piccoli
 *  Last updated  2020/11/6 by Matthew Piccoli
 *  
 *  This example code is in the public domain.
 */

#include <iq_module_communication.hpp>

 // USER SETABLE VALUES HERE---------------------------------------------------
// Sets the angle to go to in radians
const float kAngle = 12.0f*PI;
// Sets the trajectory time in seconds
const float kTime = 5;
// Sets the average speed of the return trajectory in rad/s
const float kAverageSpeed = 4*PI;
// Sets the constant velocity in rad/s
const float kConstantVelocity = -PI;
// END USER SETABLE VALUES-----------------------------------------------------

// Make an IqSerial object using Serial0 (same as Serial)
// Every board is different.  Ensure the Serial number you are using is correct
// and of the HardwareSerial class.
IqSerial ser(Serial);
// Make a MultiTurnAngleControlClient to interface with a motor module (ID 0)
MultiTurnAngleControlClient angle(0);

void setup() {
  // Initialize the Serial peripheral for motor controller
  ser.begin(115200);

  // The motor must already be powered on and booted up
  //   for these setup messages to be received.

  // Set custom values values
  ser.set(angle.obs_angular_displacement_,0.0f); // Set current location to zero
  ser.set(angle.trajectory_queue_mode_,(int8_t)0); // Set trajectory mode to append mode

  // Send two trajectories.  They will queue in the motor.
  // First trajectory: average speed based back to 0
  sendTrajectorySpeed(kAverageSpeed, 0);
  // Second trajectory: time based to a predefined angle
  sendTrajectoryTime(kTime, kAngle);
  
}

void loop() {
  int8_t mode = 0;

  // At this point the motor should be executing a trajectory.
  // Wait for the trajectory to finish
  do
  {
    // Gets ctrl_mode_ from the module and puts the result in the mode variable
    ser.get(angle.ctrl_mode_, mode);
  }while(mode == 6); // Check if the motor is still executing the last trajectory

  // We should be sitting at kAngle now.  The motor has already fallen back to angle hold mode.
  // If the motor wasn't already in angle mode, we could force it with:
  // ser.set(angle.ctrl_angle_,kAngle);

  // Spin at a constant velocity.  This will abruptly start, so keep kConstantVelocity slow
  ser.set(angle.ctrl_velocity_,kConstantVelocity);
  delay(3000); // Let it spin for 3 seconds

  // Send two trajectories.  They will queue in the motor.
  // First trajectory: average speed based back to 0
  // This will smoothly transition from the previous state, which should be a constant speed of kConstantVelocity
  sendTrajectorySpeed(kAverageSpeed, 0);
  // Second trajectory: time based to a predefined angle
  sendTrajectoryTime(kTime, kAngle);
}

void sendTrajectoryTime(float time_cmd, float angle_cmd)
{
  // Generate the set messages
  ser.set(angle.trajectory_angular_displacement_,angle_cmd);
  ser.set(angle.trajectory_duration_,time_cmd);
}

void sendTrajectorySpeed(float speed_cmd, float angle_cmd)
{
  // Generate the set messages
  ser.set(angle.trajectory_angular_displacement_,angle_cmd);
  ser.set(angle.trajectory_average_speed_,speed_cmd);
}
