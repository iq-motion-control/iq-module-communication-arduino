/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: power_safety_client.hpp
  Last update: 2023/04/24 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef POWER_SAFETY_CLIENT_HPP_
#define POWER_SAFETY_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypePowerSafety = 84;

class PowerSafetyClient : public ClientAbstract {
   public:
    PowerSafetyClient(uint8_t obj_idn)
        : ClientAbstract(kTypePowerSafety, obj_idn),
          fault_now_(kTypePowerSafety, obj_idn, kSubFaultNow),
          fault_ever_(kTypePowerSafety, obj_idn, kSubFaultEver),
          fault_latching_(kTypePowerSafety, obj_idn, kSubFaultLatching),
          volt_input_low_(kTypePowerSafety, obj_idn, kSubVoltInputLow),
          volt_input_high_(kTypePowerSafety, obj_idn, kSubVoltInputHigh),
          vref_int_low_(kTypePowerSafety, obj_idn, kSubVrefIntLow),
          vref_int_high_(kTypePowerSafety, obj_idn, kSubVrefIntHigh),
          current_input_low_(kTypePowerSafety, obj_idn, kSubCurrentInputLow),
          current_input_high_(kTypePowerSafety, obj_idn, kSubCurrentInputHigh),
          motor_current_low_(kTypePowerSafety, obj_idn, kSubMotorCurrentLow),
          motor_current_high_(kTypePowerSafety, obj_idn, kSubMotorCurrentHigh),
          temperature_uc_low_(kTypePowerSafety, obj_idn, kSubTemperatureUcLow),
          temperature_uc_high_(kTypePowerSafety, obj_idn, kSubTemperatureUcHigh),
          temperature_coil_low_(kTypePowerSafety, obj_idn, kSubTemperatureCoilLow),
          temperature_coil_high_(kTypePowerSafety, obj_idn, kSubTemperatureCoilHigh){};

    // Client Entries
    ClientEntry<float> fault_now_;
    ClientEntry<float> fault_ever_;
    ClientEntry<float> fault_latching_;
    ClientEntry<float> volt_input_low_;
    ClientEntry<float> volt_input_high_;
    ClientEntry<float> vref_int_low_;
    ClientEntry<float> vref_int_high_;
    ClientEntry<float> current_input_low_;
    ClientEntry<float> current_input_high_;
    ClientEntry<float> motor_current_low_;
    ClientEntry<float> motor_current_high_;
    ClientEntry<float> temperature_uc_low_;
    ClientEntry<float> temperature_uc_high_;
    ClientEntry<float> temperature_coil_low_;
    ClientEntry<float> temperature_coil_high_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubTemperatureCoilHigh + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &fault_now_,              // 0
            &fault_ever_,             // 1
            &fault_latching_,         // 2
            &volt_input_low_,         // 3
            &volt_input_high_,        // 4
            &vref_int_low_,           // 5
            &vref_int_high_,          // 6
            &current_input_low_,      // 7
            &current_input_high_,     // 8
            &motor_current_low_,      // 9
            &motor_current_high_,     // 10
            &temperature_uc_low_,     // 11
            &temperature_uc_high_,    // 12
            &temperature_coil_low_,   // 13
            &temperature_coil_high_,  // 14
        };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubFaultNow            = 0;
    static const uint8_t kSubFaultEver           = 1;
    static const uint8_t kSubFaultLatching       = 2;
    static const uint8_t kSubVoltInputLow        = 3;
    static const uint8_t kSubVoltInputHigh       = 4;
    static const uint8_t kSubVrefIntLow          = 5;
    static const uint8_t kSubVrefIntHigh         = 6;
    static const uint8_t kSubCurrentInputLow     = 7;
    static const uint8_t kSubCurrentInputHigh    = 8;
    static const uint8_t kSubMotorCurrentLow     = 9;
    static const uint8_t kSubMotorCurrentHigh    = 10;
    static const uint8_t kSubTemperatureUcLow    = 11;
    static const uint8_t kSubTemperatureUcHigh   = 12;
    static const uint8_t kSubTemperatureCoilLow  = 13;
    static const uint8_t kSubTemperatureCoilHigh = 14;
};

#endif /* POWER_SAFETY_CLIENT_HPP_ */