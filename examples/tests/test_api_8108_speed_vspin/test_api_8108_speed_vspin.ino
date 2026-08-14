#include "iq_module_communication_local.hpp"

IqSerial ser(Serial1);  // Use the hardware serial port on arduino board
PowerMonitorClient power(0);
SystemControlClient sysctrl(0);
CoilTemperatureEstimatorClient coilTemperatureEstimator(0);
PowerMonitorClient powerMonitorClient(0);                    // Initialize Power Monitor Client

// Initialize hyperdrive clients
CurrentSafetiesClient currentSafeties(0);
DriveControlInterfaceClient driveControlInterface(0);
MotorDriverClient motorDriver(0);
MotorModelClient motorModel(0);
RotorAngleGeneratorClient rotorAngleGenerator(0);
VoltageTargetGeneratorClient voltageTargetGenerator(0);

void setup() {
    // put your setup code here, to run once:
    uint32_t uids[] = {0, 0, 0};
    float voltage   = 0.0;
    float amps      = 0.0;
    float t_coil    = 0.0;
    uint32_t controlFlags = 0;
    float volts_cascaded = 0.0;
    uint32_t volts_cascaded_filter_fc = 0;

    // hyperdrive values
    float final_max_current_derate = 0.0;
    float voltage_target = 0.0;
    float rotor_magnitude = 0.0;
    float mechanical_inductance = 0.0;
    float rotor_angle = 0.0;
    float q_current = 0.0;

    // Set up serial port
    ser.begin(115200);
    Serial.begin(115200);  // This is used to print to the Serial Monitor
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

    //Get voltage
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


    if (ser.get(powerMonitorClient.volts_cascaded_, volts_cascaded)){
      Serial.print("volts cascaded: ");
      Serial.print(volts_cascaded);
      Serial.println(); 
    }

    if (ser.get(powerMonitorClient.volts_cascaded_filter_fc_, volts_cascaded_filter_fc)){
      Serial.print("volts cascaded filter fc: ");
      Serial.print(volts_cascaded_filter_fc);
      Serial.println(); 
    }

    Serial.println("Now testing hyperdrive clients");

    if (ser.get(currentSafeties.final_max_current_derate_, final_max_current_derate)){
      Serial.print("final max current derate: ");
      Serial.print(final_max_current_derate);
      Serial.println(); 
    }

    if (ser.get(driveControlInterface.voltage_target_, voltage_target)){
      Serial.print("voltage target: ");
      Serial.print(voltage_target);
      Serial.println(); 
    }

    if (ser.get(motorDriver.rotor_magnitude_, rotor_magnitude)){
      Serial.print("rotor magnitude: ");
      Serial.print(rotor_magnitude);
      Serial.println(); 
    }

    if (ser.get(motorModel.mechanical_inductance_, mechanical_inductance)){
      Serial.print("mechanical inductance: ");
      Serial.print(mechanical_inductance);
      Serial.println(); 
    }

    if (ser.get(rotorAngleGenerator.rotor_angle_, rotor_angle)){
      Serial.print("rotor angle: ");
      Serial.print(rotor_angle);
      Serial.println(); 
    }

    if (ser.get(voltageTargetGenerator.q_current_, q_current)){
      Serial.print("q current: ");
      Serial.print(q_current);
      Serial.println(); 
    }


}

void loop() {
    // put your main code here, to run repeatedly:
}
