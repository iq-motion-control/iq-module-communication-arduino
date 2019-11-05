/* 
 *  IQ multi turn serial demo. 
 *  
 *  This code will command a multi turn controller to go to a position,
 *  then return to the zero position repeatedly.
 *  
 *  The circuit:
 *    Arduino RX is directly connected to motor TX
 *    Arduino TX is directly connected to motor RX
 *
 *  For more information about communicating to IQ Motor Modules please go to:
 *  http://iq-control.com/documentation
 *    
 *  Created       2019/3/6 by Matthew Piccoli
 *  Last updated  2019/11/5 by Matthew Piccoli
 *  
 *  This example code is in the public domain.
 */

#include <iq_module_communication.hpp>

 // USER SETABLE VALUES HERE---------------------------------------------------
// Sets the angle to go to in radians
const float kAngle = 12.0f*PI;
// Sets the trajectory time in seconds
const float kTime = 5;
// END USER SETABLE VALUES-----------------------------------------------------

// Make an IqSerial object using Serial0 (same as Serial)
IqSerial ser(Serial);
// Make a MultiTurnAngleControlClient to interface with a motor module (ID 0)
MultiTurnAngleControlClient angle(0);

void setup() {
  // Initialize the Serial peripheral for motor controller
  ser.begin(115200);

  // The motor must already be powered on and booted up
  //   for these setup messages to be received.

  // Set custom PID values
  ser.set(angle.angle_Kp_,0.5f);
  ser.set(angle.angle_Ki_,0.0f);
  ser.set(angle.angle_Kd_,0.0f);

  // Send first message
  sendTrajectory(kTime, kAngle);
}

void loop() {
  static int spin_direction = -1;
  uint8_t mode = 0;

  do
  {
    // Gets ctrl_mode_ from the module and puts the result in the mode variable
    ser.get(angle.ctrl_mode_, mode);
  }while(mode == 6); // Check if the motor is still executing the last trajectory
  
  // Send next message
  if(spin_direction == 1)
  {
    sendTrajectory(kTime, kAngle);
  }
  else
  {
    sendTrajectory(kTime, 0);
  }
  
  // Change the direction for next time
  spin_direction = -1*spin_direction;
}

void sendTrajectory(float time_cmd, float angle_cmd)
{
  // Generate the set messages
  ser.set(angle.trajectory_angular_displacement_,angle_cmd);
  ser.set(angle.trajectory_duration_,time_cmd);
}
