#include "iq_module_communication.hpp"

IqSerial ser(Serial1);  // Use the hardware serial port on arduino board
UavcanNodeClient uavcanNode(0);                       // Initialize UAVCAN Node Client
ThrottleSourceManagerClient throttleSourceManager(0); // Initialize Throttle Source Manager Client
SystemControlClient sysctrl(0);                       // Initialize System Control Client


void setup() {
    // put your setup code here, to run once:
    uint32_t uids[] = {0, 0, 0};
    uint32_t warningEnableBitmask = 0;
    uint32_t errorEnableBitmask = 0;
    uint32_t criticalEnableBitmask = 0;
    uint32_t errorCountConfiguration = 0;
    uint8_t currentActiveThrottleSource = 0;

    // Set up serial port
    ser.begin(115200);
    Serial.begin(115200);  // This is used to print out voltage to the Serial Monitor
    Serial.println("Starting script");

    // Get motor id
    ser.get(sysctrl.uid1_, uids[0]);
    ser.get(sysctrl.uid2_, uids[1]);
    ser.get(sysctrl.uid3_, uids[2]);
    Serial.print("Motor id: ");
    for (int i = 0; i < 3; i++) {
        Serial.print(uids[i]);
        if (i < 2) Serial.print("_");
    }
    Serial.println();

    if (ser.get(uavcanNode.warning_enable_bitmask_, warningEnableBitmask)){
      Serial.print("warning_enable_bitmask: ");
      Serial.print(warningEnableBitmask);
      Serial.println();
    }

    if (ser.get(uavcanNode.error_enable_bitmask_, errorEnableBitmask)){
      Serial.print("error_enable_bitmask: ");
      Serial.print(errorEnableBitmask);
      Serial.println();
    }

    if (ser.get(uavcanNode.critical_enable_bitmask_, criticalEnableBitmask)){
      Serial.print("critical_enable_bitmask: ");
      Serial.print(criticalEnableBitmask);
      Serial.println();
    }

    if (ser.get(uavcanNode.error_count_configuration_, errorCountConfiguration)){
      Serial.print("error_count_configuration: ");
      Serial.print(errorCountConfiguration);
      Serial.println();
    }

    if (ser.get(throttleSourceManager.current_active_throttle_source_, currentActiveThrottleSource)){
      Serial.print("current_active_throttle_source: ");
      Serial.print(currentActiveThrottleSource);
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
