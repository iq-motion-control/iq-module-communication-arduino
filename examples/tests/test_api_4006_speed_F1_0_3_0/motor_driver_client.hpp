/*
    Copyright 2025 Vertiq, Inc support@vertiq.co

    This file is part of the IQ C++ API.

    This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
    Name: motor_driver_client.hpp
    Last update: 2025-03-11 by Ben Quan
    Author: Ben Quan
    Contributors:
*/

#ifndef MOTOR_DRIVER_CLIENT_HPP_
#define MOTOR_DRIVER_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeMotorDriver = 96;

class MotorDriverClient : public ClientAbstract {
    public:
    MotorDriverClient(uint8_t obj_idn)
        : ClientAbstract(kTypeMotorDriver, obj_idn),
            rotor_magnitude_(kTypeMotorDriver, obj_idn, kSubRotorMagnitude),
            rotor_angle_(kTypeMotorDriver, obj_idn, kSubRotorAngle),
            final_rotor_magnitude_(kTypeMotorDriver, obj_idn, kSubFinalRotorMagnitude),
            final_rotor_angle_(kTypeMotorDriver, obj_idn, kSubFinalRotorAngle),
            direct_stator_magnitude_(kTypeMotorDriver, obj_idn, kSubDirectStatorMagnitude),
            direct_stator_angle_(kTypeMotorDriver, obj_idn, kSubDirectStatorAngle),
            stator_magnitude_(kTypeMotorDriver, obj_idn, kSubStatorMagnitude),
            stator_electrical_angle_(kTypeMotorDriver, obj_idn, kSubStatorElectricalAngle),
            pwm_(kTypeMotorDriver, obj_idn, kSubPwm),
            coast_(kTypeMotorDriver, obj_idn, kSubCoast),
            brake_(kTypeMotorDriver, obj_idn, kSubBrake),
            set_apply_target_mode_(kTypeMotorDriver, obj_idn, kSubSetApplyTargetMode),
            set_apply_direct_stator_sv_mode_(kTypeMotorDriver, obj_idn, kSubSetApplyDirectStatorSvMode),
            driver_mode_(kTypeMotorDriver, obj_idn, kSubDriverMode),
            additional_drive_volts_(kTypeMotorDriver, obj_idn, kSubAdditionalDriveVolts),
            estimated_motor_amps_(kTypeMotorDriver, obj_idn, kSubEstimatedMotorAmps),
            commutation_hz_(kTypeMotorDriver, obj_idn, kSubCommutationHz)
            {};

    // Client Entries
    ClientEntry<float> rotor_magnitude_;
    ClientEntry<float> rotor_angle_;
    ClientEntry<float> final_rotor_magnitude_;
    ClientEntry<float> final_rotor_angle_;
    ClientEntry<float> direct_stator_magnitude_;
    ClientEntry<float> direct_stator_angle_;
    ClientEntry<float> stator_magnitude_;
    ClientEntry<float> stator_electrical_angle_;
    ClientEntry<float> pwm_;
    ClientEntryVoid coast_;
    ClientEntryVoid brake_;
    ClientEntryVoid set_apply_target_mode_;
    ClientEntryVoid set_apply_direct_stator_sv_mode_;
    ClientEntry<uint8_t> driver_mode_;
    ClientEntry<float> additional_drive_volts_;
    ClientEntry<float> estimated_motor_amps_;
    ClientEntry<uint32_t> commutation_hz_;
    
    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength = kSubCommutationHz + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &rotor_magnitude_, // 0
            &rotor_angle_, // 1
            &final_rotor_magnitude_, // 2
            &final_rotor_angle_, // 3
            &direct_stator_magnitude_, // 4
            &direct_stator_angle_, // 5
            &stator_magnitude_, // 6
            &stator_electrical_angle_, // 7
            &pwm_, // 8
            &coast_, // 9
            &brake_, // 10
            &set_apply_target_mode_, // 11
            &set_apply_direct_stator_sv_mode_, // 12
            &driver_mode_, // 13
            &additional_drive_volts_, // 14
            &estimated_motor_amps_, // 15
            &commutation_hz_, // 16
            };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

    private:
    static const uint8_t kSubRotorMagnitude = 0;
    static const uint8_t kSubRotorAngle = 1;
    static const uint8_t kSubFinalRotorMagnitude = 2;
    static const uint8_t kSubFinalRotorAngle = 3;
    static const uint8_t kSubDirectStatorMagnitude = 4;
    static const uint8_t kSubDirectStatorAngle = 5;
    static const uint8_t kSubStatorMagnitude = 6;
    static const uint8_t kSubStatorElectricalAngle = 7;
    static const uint8_t kSubPwm = 8;
    static const uint8_t kSubCoast = 9;
    static const uint8_t kSubBrake = 10;
    static const uint8_t kSubSetApplyTargetMode = 11;
    static const uint8_t kSubSetApplyDirectStatorSvMode = 12;
    static const uint8_t kSubDriverMode = 13;
    static const uint8_t kSubAdditionalDriveVolts = 14;
    static const uint8_t kSubEstimatedMotorAmps = 15;
    static const uint8_t kSubCommutationHz = 16;
    
};

#endif /* MOTOR_DRIVER_CLIENT_HPP_ */