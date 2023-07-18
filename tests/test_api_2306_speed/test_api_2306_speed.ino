#include "iq_module_communication_local.hpp"

IqSerial ser(Serial1);  // Use the hardware serial port on arduino board
PowerMonitorClient power(0);
SystemControlClient sysctrl(0);
BrushlessDriveClient bdrive(0);
CoilTemperatureEstimatorClient coilTemperatureEstimator(0);
AnticoggingProClient anticog_pro(0);
MagAlphaClient mag_alpha(0);

void setup() {
    // put your setup code here, to run once:
    uint32_t uids[] = {0, 0, 0};
    float voltage   = 0.0;
    float amps      = 0.0;
    float t_coil    = 0.0;
    uint32_t controlFlags = 0;
    uint8_t num_harmonics = 0;
    float angle_rad = 0.0;

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

    // Get voltage
    if (ser.get(power.volts_, voltage)) {
        Serial.print("voltage: ");
        Serial.print(voltage);
        Serial.println();
    }

    // Get amps
    if (ser.get(power.amps_, amps)) {
        Serial.print("amps: ");
        Serial.print(amps);
        Serial.println();
    }

    // Get t_coil
    if (ser.get(coilTemperatureEstimator.t_coil_, t_coil)) {
        Serial.print("t_coil: ");
        Serial.print(t_coil);
        Serial.println();
    }
    
    // Get control flags
    if (ser.get(sysctrl.control_flags_, controlFlags)) {
      Serial.print("control flags: ");
      Serial.print(controlFlags);
      Serial.println();  
    }

    //Get num harmonics
    if (ser.get(anticog_pro.num_harmonics_, num_harmonics )) {
      Serial.print("num harmonics : ");
      Serial.print(num_harmonics );
      Serial.println(); 
    }

    //Get angle
    if (ser.get(mag_alpha.angle_rad_, angle_rad )) {
      Serial.print("angle rad : ");
      Serial.print(angle_rad );
      Serial.println(); 
    }
}

void loop() {
    // put your main code here, to run repeatedly:
    float volts = 1.0;
    ser.set(bdrive.drive_spin_volts_, volts);

    delay(5000);

    ser.set(bdrive.drive_coast_);

    delay(5000);

}
