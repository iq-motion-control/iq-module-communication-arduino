/*
    Copyright 2025 Vertiq, Inc support@vertiq.co

    This file is part of the IQ C++ API.

    This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
    Name: rotor_angle_generator_client.hpp
    Last update: 2025-03-11 by Ben Quan
    Author: Ben Quan
    Contributors:
*/

#ifndef ROTOR_ANGLE_GENERATOR_CLIENT_HPP_
#define ROTOR_ANGLE_GENERATOR_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeRotorAngleGenerator = 95;

class RotorAngleGeneratorClient : public ClientAbstract {
    public:
    RotorAngleGeneratorClient(uint8_t obj_idn)
        : ClientAbstract(kTypeRotorAngleGenerator, obj_idn),
            rotor_angle_(kTypeRotorAngleGenerator, obj_idn, kSubRotorAngle),
            manual_angle_(kTypeRotorAngleGenerator, obj_idn, kSubManualAngle),
            use_manual_angle_(kTypeRotorAngleGenerator, obj_idn, kSubUseManualAngle)
            {};

    // Client Entries
    ClientEntry<float> rotor_angle_;
    ClientEntry<float> manual_angle_;
    ClientEntry<uint8_t> use_manual_angle_;
    
    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength = kSubUseManualAngle + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &rotor_angle_, // 0
            &manual_angle_, // 1
            &use_manual_angle_, // 2
            };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

    private:
    static const uint8_t kSubRotorAngle = 0;
    static const uint8_t kSubManualAngle = 1;
    static const uint8_t kSubUseManualAngle = 2;
    
};

#endif /* ROTOR_ANGLE_GENERATOR_CLIENT_HPP_ */