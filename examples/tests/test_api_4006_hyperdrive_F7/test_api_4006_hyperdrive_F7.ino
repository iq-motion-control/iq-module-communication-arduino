#include "iq_module_communication.hpp"

IqSerial ser(Serial1);                          // Use the hardware serial port on arduino board

SystemControlClient sysctrl(0);          // Initialize System Control Client with Module ID 0
EscPropellerInputParserClient epip(0);   // Initialize ESC Propeller Input Parser Client with Module ID 0
PropellerMotorControlClient pmc(0);      // Initialize Propeller Motor Control Client with Module ID 0

// This test involves spinning your module.
// Please make sure no propellers are attached and your module is secured!
void setup() {
  // put your setup code here, to run once:
  // Set up serial port for the module and the Serial Monitor
  ser.begin(115200);
  Serial.begin(115200);  // this is used to print out client entry values to the serial monitor
  Serial.println("Starting script");

  // Get motor id
  uint32_t uids[] = { 0, 0, 0 };
  ser.get(sysctrl.uid1_, uids[0]);
  ser.get(sysctrl.uid2_, uids[1]);
  ser.get(sysctrl.uid3_, uids[2]);
  Serial.print("Motor id: ");
  for (int i = 0; i < 3; i++) {
    Serial.print(uids[i]);
    if (i < 2) Serial.print("_");
  }
  Serial.println();

  Serial.print("-----testing esc_propeller_input_parser-----");
  Serial.println();
  float torqueMax = 0;
  if (ser.get(epip.torque_max_, torqueMax)) {
    Serial.print("torque_max: ");
    Serial.print(torqueMax);
    Serial.println();
  }

  float newTorqueMaxValue = 0.34;
  float newTorqueMax = 0;
  Serial.print("settting torque_max: ");
  Serial.print(newTorqueMaxValue);
  Serial.println();
  ser.set(epip.torque_max_, newTorqueMaxValue);
  if (ser.get(epip.torque_max_, newTorqueMax)) {
    Serial.print("new torque_max: ");
    Serial.print(newTorqueMax);
    Serial.println();
  }

  Serial.print("-----testing propeller_motor_control-----");
  Serial.println();
  float ctrlTorque = 0;
  if (ser.get(pmc.ctrl_torque_, ctrlTorque)) {
    Serial.print("ctrl_torque: ");
    Serial.print(ctrlTorque);
    Serial.println();
  }

  // This test will attempt to spin your module.
  // Please make sure no propellers are attached and your module is secured!
  float newCtrlTorqueValue = 0.10;
  float newCtrlTorque = 0;
  Serial.print("setting ctrl_torque: ");
  Serial.print(newCtrlTorqueValue);
  Serial.println();
  ser.set(pmc.ctrl_torque_, newCtrlTorqueValue);
  if (ser.get(pmc.ctrl_torque_, newCtrlTorque)) {
    Serial.print("new ctrl_torque: ");
    Serial.print(newCtrlTorque);
    Serial.println();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
