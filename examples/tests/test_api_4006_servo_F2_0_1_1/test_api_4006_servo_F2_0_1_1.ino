#include "iq_module_communication.hpp"

IqSerial ser(Serial1);                          // Use the hardware serial port on arduino board
IQUartFlightControllerInterfaceClient ifci(0);  // Initialize IQUart Flight Controller Interface Client
UavcanNodeClient uavcanNode(0);                 // Initialize UAVCAN Node Client
SystemControlClient sysctrl(0);                 // Initialize System Control Client


void setup() {
  // put your setup code here, to run once:
  // Set up serial port
  ser.begin(115200);
  Serial.begin(115200);  // This is used to print out voltage to the Serial Monitor
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

  uint8_t servoCvi = 0;
  if (ser.get(ifci.servo_cvi_, servoCvi)) {
    Serial.print("servo_cvi: ");
    Serial.print(servoCvi);
    Serial.println();
  }

  uint8_t newServoCviValue = 6;
  uint8_t newServoCvi = 0;
  Serial.print("settting servo_cvi: ");
  Serial.print(newServoCviValue);
  Serial.println();
  ser.set(ifci.servo_cvi_, newServoCviValue);
  if (ser.get(ifci.servo_cvi_, newServoCvi)) {
    Serial.print("new servo_cvi: ");
    Serial.print(newServoCvi);
    Serial.println();
  }

  uint32_t actuatorId = 0;
  if (ser.get(uavcanNode.actuator_id_, actuatorId)) {
    Serial.print("actuator_id: ");
    Serial.print(actuatorId);
    Serial.println();
  }

  uint32_t newActuatorIdValue = 6;
  uint32_t newActuatorId = 0;
  Serial.print("setting actuator_id: ");
  Serial.print(newActuatorIdValue);
  Serial.println();
  ser.set(uavcanNode.actuator_id_, newActuatorIdValue);
  if (ser.get(uavcanNode.actuator_id_, newActuatorId)) {
    Serial.print("new actuator_id: ");
    Serial.print(newActuatorId);
    Serial.println();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // float volts = 1.0;
  // ser.set(bdrive.drive_spin_volts_, volts);

  // delay(5000);
  // ser.set(bdrive.drive_coast_);

  // delay(1000);

  // ser.set(stowUserInterface.stow_);

  // delay(1000);
}
