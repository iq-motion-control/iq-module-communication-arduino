/*
  Copyright 2019 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: esc_propeller_input_parser_client.hpp
  Last update: 2023/04/12 by Ben Quan
  Author: Matthew Piccoli
  Contributors: Ben Quan, Raphael Van Hoffelen
*/

#ifndef ESC_PROPELLER_INPUT_PARSER_CLIENT_HPP_
#define ESC_PROPELLER_INPUT_PARSER_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeEscPropellerInputParser = 60;

class EscPropellerInputParserClient : public ClientAbstract {
   public:
    EscPropellerInputParserClient(uint8_t obj_idn)
        : ClientAbstract(kTypeEscPropellerInputParser, obj_idn),
          mode_(kTypeEscPropellerInputParser, obj_idn, kSubMode),
          raw_value_(kTypeEscPropellerInputParser, obj_idn, kSubRawValue),
          sign_(kTypeEscPropellerInputParser, obj_idn, kSubSign),
          volts_max_(kTypeEscPropellerInputParser, obj_idn, kSubVoltsMax),
          velocity_max_(kTypeEscPropellerInputParser, obj_idn, kSubVelocityMax),
          thrust_max_(kTypeEscPropellerInputParser, obj_idn, kSubThrustMax),
          safe_factor_(kTypeEscPropellerInputParser, obj_idn, kSubSafeFactor),
          flip_negative_(kTypeEscPropellerInputParser, obj_idn, kSubFlipNegative),
          zero_spin_throttle_(kTypeEscPropellerInputParser, obj_idn, kSubZeroSpinThrottle),
          zero_spin_tolerance_(kTypeEscPropellerInputParser, obj_idn, kSubZeroSpinTolerance){};

    // Client Entries
    // Control commands
    ClientEntry<uint8_t> mode_;
    ClientEntry<float> raw_value_;
    ClientEntry<uint8_t> sign_;
    ClientEntry<float> volts_max_;
    ClientEntry<float> velocity_max_;
    ClientEntry<float> thrust_max_;
    ClientEntry<float> safe_factor_;
    ClientEntry<uint8_t> flip_negative_;
    ClientEntry<float> zero_spin_throttle_;
    ClientEntry<float> zero_spin_tolerance_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubZeroSpinTolerance + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &mode_,                // 0
            &raw_value_,           // 1
            nullptr,               // 2
            &sign_,                // 3
            &volts_max_,           // 4
            &velocity_max_,        // 5
            &thrust_max_,          // 6
            &safe_factor_,         // 7
            &flip_negative_,       // 8
            &zero_spin_throttle_,  // 9
            &zero_spin_tolerance_  // 10
        };

        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubMode              = 0;
    static const uint8_t kSubRawValue          = 1;
    static const uint8_t kSubSign              = 3;
    static const uint8_t kSubVoltsMax          = 4;
    static const uint8_t kSubVelocityMax       = 5;
    static const uint8_t kSubThrustMax         = 6;
    static const uint8_t kSubSafeFactor        = 7;
    static const uint8_t kSubFlipNegative      = 8;
    static const uint8_t kSubZeroSpinThrottle  = 9;
    static const uint8_t kSubZeroSpinTolerance = 10;
};

#endif /* ESC_PROPELLER_INPUT_PARSER_CLIENT_HPP_ */
