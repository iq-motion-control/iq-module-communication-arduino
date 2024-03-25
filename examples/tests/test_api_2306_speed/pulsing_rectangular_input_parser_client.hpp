/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: pulsing_rectangular_input_parser_client.hpp
  Last update: 2023/04/12 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef PULSING_RECTANGULAR_INPUT_PARSER_CLIENT_HPP_
#define PULSING_RECTANGULAR_INPUT_PARSER_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypePulsingRectangularInputParser = 89;

class PulsingRectangularInputParserClient : public ClientAbstract {
   public:
    PulsingRectangularInputParserClient(uint8_t obj_idn)
        : ClientAbstract(kTypePulsingRectangularInputParser, obj_idn),
          pulsing_voltage_mode_(kTypePulsingRectangularInputParser, obj_idn, kSubPulsingVoltageMode),
          pulsing_voltage_limit_(kTypePulsingRectangularInputParser, obj_idn, kSubPulsingVoltageLimit){};

    // Client Entries
    ClientEntry<uint8_t> pulsing_voltage_mode_;
    ClientEntry<float> pulsing_voltage_limit_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubPulsingVoltageLimit + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &pulsing_voltage_mode_,  // 0
            &pulsing_voltage_limit_  // 1
        };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubPulsingVoltageMode  = 0;
    static const uint8_t kSubPulsingVoltageLimit = 1;
};

#endif /* PULSING_RECTANGULAR_INPUT_PARSER_CLIENT_HPP_ */