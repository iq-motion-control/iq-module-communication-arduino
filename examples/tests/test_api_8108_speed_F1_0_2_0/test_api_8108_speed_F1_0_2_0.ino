#include "iq_module_communication_local.hpp"

IqSerial ser(Serial1);  // Use the hardware serial port on arduino board
SystemControlClient sysctrl(0);

ArmingHandlerClient armingHandler(0);                        // Initialize Arming Handler Client
BrushlessDriveClient brushlessDrive(0);                      // Initialize Brushless Drive Client
EscPropellerInputParserClient escPropellerInputParser(0);    // Initialize Esc Propeller Input Parser Client
HobbyInputClient hobbyInput(0);
MultiTurnAngleControlClient multiTurnAngleControl(0);        // Initialize Mult Turn Angle Control Client
PropellerMotorControlClient propellerMotorControl(0);  

void setup() {
    // put your setup code here, to run once:
    uint32_t uids[] = {0, 0, 0};

    // float voltage   = 0.0;
    // float amps      = 0.0;
    // float t_coil    = 0.0;
    // uint32_t controlFlags = 0;
    // float volts_cascaded = 0.0;
    // uint32_t volts_cascaded_filter_fc = 0;
    // uint8_t report_telemetry_as_speed = 0;




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


}

void loop() {
    // put your main code here, to run repeatedly:
    uint8_t playArmingSongOnArm = 0;
    uint16_t hobbyTelemtryFrequency = 0;
    uint8_t hobbyTelemetrySpeedStyle = 0;
    uint8_t allowDshotDisarmingMessage = 0;
    float lowPowerHoldAllowedTargetError = 0.0;
    float lowPowerHoldMaxBrakeError = 0.0;
        //Get voltage
    if (ser.get(armingHandler.play_arming_song_on_arm_, playArmingSongOnArm)) {
        Serial.print("play_arming_song_on_arm: ");
        Serial.print(playArmingSongOnArm);
        Serial.println();
    }

    // Get amps
    if (ser.get(hobbyInput.hobby_telemetry_frequency_, hobbyTelemtryFrequency)) {
        Serial.print("hobby_telemetry_frequency: ");
        Serial.print(hobbyTelemtryFrequency);
        Serial.println();
    }

    // Get t_coil
    if (ser.get(hobbyInput.hobby_telemetry_speed_style_, hobbyTelemetrySpeedStyle)) {
        Serial.print("hobby_telemetry_speed_style: ");
        Serial.print(hobbyTelemetrySpeedStyle);
        Serial.println();
    }
    
    // Get control flags
    if (ser.get(hobbyInput.allow_dshot_disarming_message_, allowDshotDisarmingMessage)) {
      Serial.print("allow_dshot_disarming_message: ");
      Serial.print(allowDshotDisarmingMessage);
      Serial.println();  
    }


    if (ser.get(multiTurnAngleControl.low_power_hold_allowed_target_error_, lowPowerHoldAllowedTargetError)){
      Serial.print("low_power_hold_allowed_target_error: ");
      Serial.print(lowPowerHoldAllowedTargetError);
      Serial.println(); 
    }

    if (ser.get(multiTurnAngleControl.low_power_hold_max_brake_error_, lowPowerHoldMaxBrakeError)){
      Serial.print("low_power_hold_max_brake_error: ");
      Serial.print(lowPowerHoldMaxBrakeError);
      Serial.println(); 
    }
}
