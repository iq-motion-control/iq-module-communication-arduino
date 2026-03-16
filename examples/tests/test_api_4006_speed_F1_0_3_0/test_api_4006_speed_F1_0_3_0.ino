#include "iq_module_communication.hpp"

IqSerial ser(Serial1);  // Use the hardware serial port on arduino board
UavcanNodeClient uavcanNode(0);                       // Initialize UAVCAN Node Client
ThrottleSourceManagerClient throttleSourceManager(0); // Initialize Throttle Source Manager Client
SystemControlClient sysctrl(0);                       // Initialize System Control Client


void setup() {
    // put your setup code here, to run once:
    // Set up serial port
    ser.begin(115200);
    Serial.begin(115200);  // This is used to print out voltage to the Serial Monitor
    Serial.println("Starting script");

    // Get motor id
    uint32_t uids[] = {0, 0, 0};
    ser.get(sysctrl.uid1_, uids[0]);
    ser.get(sysctrl.uid2_, uids[1]);
    ser.get(sysctrl.uid3_, uids[2]);
    Serial.print("Motor id: ");
    for (int i = 0; i < 3; i++) {
        Serial.print(uids[i]);
        if (i < 2) Serial.print("_");
    }
    Serial.println();

    Serial.print("-----testing uavcan_node-----");
    Serial.println();
    uint32_t warningEnableBitmask = 0;
    if (ser.get(uavcanNode.warning_enable_bitmask_, warningEnableBitmask)){
      Serial.print("warning_enable_bitmask: ");
      Serial.print(warningEnableBitmask);
      Serial.println();
    }

    uint32_t newWarningEnableBitmaskValue = 6;
    uint32_t newWarningEnableBitmask= 0;
    Serial.print("setting warning_enable_bitmask: ");
    Serial.print(newWarningEnableBitmaskValue);
    Serial.println();
    ser.set(uavcanNode.warning_enable_bitmask_, newWarningEnableBitmaskValue);
    if (ser.get(uavcanNode.warning_enable_bitmask_, newWarningEnableBitmask)){
      Serial.print("new warning_enable_bitmask: ");
      Serial.print(newWarningEnableBitmask);
      Serial.println();
    }


    uint32_t errorEnableBitmask = 0;
    if (ser.get(uavcanNode.error_enable_bitmask_, errorEnableBitmask)){
      Serial.print("error_enable_bitmask: ");
      Serial.print(errorEnableBitmask);
      Serial.println();
    }

    uint32_t newErrorEnableBitmaskValue = 2;
    uint32_t newErrorEnableBitmask = 0;
    Serial.print("setting error_enable_bitmask: ");
    Serial.print(newErrorEnableBitmaskValue);
    Serial.println();
    ser.set(uavcanNode.error_enable_bitmask_, newErrorEnableBitmaskValue);
    if (ser.get(uavcanNode.error_enable_bitmask_, newErrorEnableBitmask)){
      Serial.print("new error_enable_bitmask: ");
      Serial.print(newErrorEnableBitmask);
      Serial.println();
    }

    uint32_t criticalEnableBitmask = 0;
    if (ser.get(uavcanNode.critical_enable_bitmask_, criticalEnableBitmask)){
      Serial.print("critical_enable_bitmask: ");
      Serial.print(criticalEnableBitmask);
      Serial.println();
    }
    uint32_t newCriticalEnableBitmaskValue = 2;
    uint32_t newCriticalEnableBitmask = 0;
    Serial.print("setting critical_enable_bitmask: ");
    Serial.print(newErrorEnableBitmaskValue);
    Serial.println();
    ser.set(uavcanNode.critical_enable_bitmask_, newCriticalEnableBitmaskValue);
    if (ser.get(uavcanNode.critical_enable_bitmask_, newCriticalEnableBitmask)){
      Serial.print("new critical_enable_bitmask: ");
      Serial.print(newCriticalEnableBitmask);
      Serial.println();
    }

    uint32_t errorCountConfiguration = 0;
    if (ser.get(uavcanNode.error_count_configuration_, errorCountConfiguration)){
      Serial.print("error_count_configuration: ");
      Serial.print(errorCountConfiguration);
      Serial.println();
    }

    uint32_t newErrorCountConfigurationValue = 2;
    uint32_t newErrorCountConfiguration = 0;
    Serial.print("setting error_count_configuration: ");
    Serial.print(newErrorCountConfigurationValue);
    Serial.println();
    ser.set(uavcanNode.error_count_configuration_, newErrorCountConfigurationValue);
    if (ser.get(uavcanNode.error_count_configuration_, newErrorCountConfiguration)){
      Serial.print("new error_count_configuration: ");
      Serial.print(newErrorCountConfiguration);
      Serial.println();
    }

    Serial.print("-----testing throttle_source_manager-----");
    Serial.println();
    uint8_t currentActiveThrottleSource = 0;
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
