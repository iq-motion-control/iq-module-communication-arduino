/* 
 *  IQ propeller serial demo. 
 *  
 *  This code will command a propeller controller to vary its speed in the 
 *  positive and negative direction repeatedly.
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
// Sets the maximum speed (in rad/s)
const float kSpeed = 50.0f;
// Sets the velocity increment size (in rad/s/100ms)
const float kSpeedStep = 1.0f;
// END USER SETABLE VALUES-----------------------------------------------------

// Make an IqSerial object using Serial0 (same as Serial)
IqSerial ser(Serial);
// Make a PropellerMotorControlClient to interface with a motor module (ID 0)
PropellerMotorControlClient prop(0);

void setup() {
  // Initialize the Serial peripheral for motor controller
  ser.begin(115200);

  // The motor must already be powered on and booted up
  //   for these setup messages to be received.
  // Wait for one second just in case both devices are powered at the same time
  delay(1000);
}

void loop() {
  static float velocity_to_set = 0.0f; 
  static float velocity_sign = 1.0f;

  // Update velocity command
  if(abs(velocity_to_set) >= kSpeed)
  {
    velocity_sign = -1*velocity_sign;
  }
  velocity_to_set += kSpeedStep*velocity_sign;

  // Send velocity command to motor
  ser.set(prop.ctrl_velocity_,velocity_to_set);

  // Limit the acceleration by updating at a limited rate
  delay(25);
}
