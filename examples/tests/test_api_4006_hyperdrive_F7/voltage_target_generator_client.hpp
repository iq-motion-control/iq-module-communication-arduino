/*
    Copyright 2025 Vertiq, Inc support@vertiq.co

    This file is part of the IQ C++ API.

    This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
    Name: voltage_target_generator_client.hpp
    Last update: 2025-03-11 by Ben Quan
    Author: Ben Quan
    Contributors:
*/

#ifndef VOLTAGE_TARGET_GENERATOR_CLIENT_HPP_
#define VOLTAGE_TARGET_GENERATOR_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeVoltageTargetGenerator = 94;

class VoltageTargetGeneratorClient : public ClientAbstract {
    public:
    VoltageTargetGeneratorClient(uint8_t obj_idn)
        : ClientAbstract(kTypeVoltageTargetGenerator, obj_idn),
            q_current_(kTypeVoltageTargetGenerator, obj_idn, kSubQCurrent),
            d_current_(kTypeVoltageTargetGenerator, obj_idn, kSubDCurrent),
            q_voltage_(kTypeVoltageTargetGenerator, obj_idn, kSubQVoltage),
            d_voltage_(kTypeVoltageTargetGenerator, obj_idn, kSubDVoltage)
            {};

    // Client Entries
    ClientEntry<float> q_current_;
    ClientEntry<float> d_current_;
    ClientEntry<float> q_voltage_;
    ClientEntry<float> d_voltage_;
    
    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength = kSubDVoltage + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &q_current_, // 0
            &d_current_, // 1
            &q_voltage_, // 2
            &d_voltage_, // 3
            };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

    private:
    static const uint8_t kSubQCurrent = 0;
    static const uint8_t kSubDCurrent = 1;
    static const uint8_t kSubQVoltage = 2;
    static const uint8_t kSubDVoltage = 3;
    
};

#endif /* VOLTAGE_TARGET_GENERATOR_CLIENT_HPP_ */