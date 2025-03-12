/*
    Copyright 2025 Vertiq, Inc support@vertiq.co

    This file is part of the IQ C++ API.

    This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
    Name: motor_model_client.hpp
    Last update: 2025-03-11 by Ben Quan
    Author: Ben Quan
    Contributors:
*/

#ifndef MOTOR_MODEL_CLIENT_HPP_
#define MOTOR_MODEL_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeMotorModel = 98;

class MotorModelClient : public ClientAbstract {
    public:
    MotorModelClient(uint8_t obj_idn)
        : ClientAbstract(kTypeMotorModel, obj_idn),
            mechanical_inductance_(kTypeMotorModel, obj_idn, kSubMechanicalInductance),
            mechanical_velocity_(kTypeMotorModel, obj_idn, kSubMechanicalVelocity),
            mechanical_ke_at_20c_(kTypeMotorModel, obj_idn, kSubMechanicalKeAt20c),
            mechanical_ke_(kTypeMotorModel, obj_idn, kSubMechanicalKe),
            coil_resistance_at_20c_(kTypeMotorModel, obj_idn, kSubCoilResistanceAt20c),
            coil_resistance_(kTypeMotorModel, obj_idn, kSubCoilResistance),
            additional_resistance_(kTypeMotorModel, obj_idn, kSubAdditionalResistance),
            effective_resistance_(kTypeMotorModel, obj_idn, kSubEffectiveResistance),
            pole_pairs_(kTypeMotorModel, obj_idn, kSubPolePairs),
            lead_time_(kTypeMotorModel, obj_idn, kSubLeadTime),
            permute_wires_(kTypeMotorModel, obj_idn, kSubPermuteWires),
            calibration_angle_(kTypeMotorModel, obj_idn, kSubCalibrationAngle),
            lead_angle_(kTypeMotorModel, obj_idn, kSubLeadAngle),
            back_emf_(kTypeMotorModel, obj_idn, kSubBackEmf),
            encoder_angle_(kTypeMotorModel, obj_idn, kSubEncoderAngle),
            coil_temperature_(kTypeMotorModel, obj_idn, kSubCoilTemperature),
            mechanical_acceleration_(kTypeMotorModel, obj_idn, kSubMechanicalAcceleration)
            {};

    // Client Entries
    ClientEntry<float> mechanical_inductance_;
    ClientEntry<float> mechanical_velocity_;
    ClientEntry<float> mechanical_ke_at_20c_;
    ClientEntry<float> mechanical_ke_;
    ClientEntry<float> coil_resistance_at_20c_;
    ClientEntry<float> coil_resistance_;
    ClientEntry<float> additional_resistance_;
    ClientEntry<float> effective_resistance_;
    ClientEntry<uint16_t> pole_pairs_;
    ClientEntry<float> lead_time_;
    ClientEntry<uint8_t> permute_wires_;
    ClientEntry<float> calibration_angle_;
    ClientEntry<float> lead_angle_;
    ClientEntry<float> back_emf_;
    ClientEntry<float> encoder_angle_;
    ClientEntry<float> coil_temperature_;
    ClientEntry<float> mechanical_acceleration_;
    
    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength = kSubMechanicalAcceleration + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &mechanical_inductance_, // 0
            &mechanical_velocity_, // 1
            &mechanical_ke_at_20c_, // 2
            &mechanical_ke_, // 3
            &coil_resistance_at_20c_, // 4
            &coil_resistance_, // 5
            &additional_resistance_, // 6
            &effective_resistance_, // 7
            &pole_pairs_, // 8
            &lead_time_, // 9
            &permute_wires_, // 10
            &calibration_angle_, // 11
            &lead_angle_, // 12
            &back_emf_, // 13
            &encoder_angle_, // 14
            &coil_temperature_, // 15
            &mechanical_acceleration_, // 16
            };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

    private:
    static const uint8_t kSubMechanicalInductance = 0;
    static const uint8_t kSubMechanicalVelocity = 1;
    static const uint8_t kSubMechanicalKeAt20c = 2;
    static const uint8_t kSubMechanicalKe = 3;
    static const uint8_t kSubCoilResistanceAt20c = 4;
    static const uint8_t kSubCoilResistance = 5;
    static const uint8_t kSubAdditionalResistance = 6;
    static const uint8_t kSubEffectiveResistance = 7;
    static const uint8_t kSubPolePairs = 8;
    static const uint8_t kSubLeadTime = 9;
    static const uint8_t kSubPermuteWires = 10;
    static const uint8_t kSubCalibrationAngle = 11;
    static const uint8_t kSubLeadAngle = 12;
    static const uint8_t kSubBackEmf = 13;
    static const uint8_t kSubEncoderAngle = 14;
    static const uint8_t kSubCoilTemperature = 15;
    static const uint8_t kSubMechanicalAcceleration = 16;
    
};

#endif /* MOTOR_MODEL_CLIENT_HPP_ */