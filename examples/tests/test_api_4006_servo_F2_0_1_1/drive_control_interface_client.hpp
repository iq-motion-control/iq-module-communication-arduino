/*
    Copyright 2025 Vertiq, Inc support@vertiq.co

    This file is part of the IQ C++ API.

    This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
    Name: drive_control_interface_client.hpp
    Last update: 2025-03-12 by Ben Quan
    Author: Ben Quan
    Contributors:
*/

#ifndef DRIVE_CONTROL_INTERFACE_CLIENT_HPP_
#define DRIVE_CONTROL_INTERFACE_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeDriveControlInterface = 97;

class DriveControlInterfaceClient : public ClientAbstract {
    public:
    DriveControlInterfaceClient(uint8_t obj_idn)
        : ClientAbstract(kTypeDriveControlInterface, obj_idn),
            voltage_target_(kTypeDriveControlInterface, obj_idn, kSubVoltageTarget),
            pwm_target_(kTypeDriveControlInterface, obj_idn, kSubPwmTarget),
            torque_target_(kTypeDriveControlInterface, obj_idn, kSubTorqueTarget),
            q_current_target_(kTypeDriveControlInterface, obj_idn, kSubQCurrentTarget),
            d_current_target_(kTypeDriveControlInterface, obj_idn, kSubDCurrentTarget),
            coast_(kTypeDriveControlInterface, obj_idn, kSubCoast),
            brake_(kTypeDriveControlInterface, obj_idn, kSubBrake),
            mode_(kTypeDriveControlInterface, obj_idn, kSubMode)
            {};

    // Client Entries
    ClientEntry<float> voltage_target_;
    ClientEntry<float> pwm_target_;
    ClientEntry<float> torque_target_;
    ClientEntry<float> q_current_target_;
    ClientEntry<float> d_current_target_;
    ClientEntryVoid coast_;
    ClientEntryVoid brake_;
    ClientEntry<uint8_t> mode_;
    
    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength = kSubMode + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &voltage_target_, // 0
            &pwm_target_, // 1
            &torque_target_, // 2
            &q_current_target_, // 3
            &d_current_target_, // 4
            &coast_, // 5
            &brake_, // 6
            &mode_ // 7
            };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

    private:
    static const uint8_t kSubVoltageTarget = 0;
    static const uint8_t kSubPwmTarget = 1;
    static const uint8_t kSubTorqueTarget = 2;
    static const uint8_t kSubQCurrentTarget = 3;
    static const uint8_t kSubDCurrentTarget = 4;
    static const uint8_t kSubCoast = 5;
    static const uint8_t kSubBrake = 6;
    static const uint8_t kSubMode = 7;
    
};

#endif /* DRIVE_CONTROL_INTERFACE_CLIENT_HPP_ */