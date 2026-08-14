/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: adc_interface_client.hpp
  Last update: 2023/04/18 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef ADC_INTERFACE_CLIENT_HPP_
#define ADC_INTERFACE_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeAdcInterface = 91;

class AdcInterfaceClient : public ClientAbstract {
   public:
    AdcInterfaceClient(uint8_t obj_idn)
        : ClientAbstract(kTypeAdcInterface, obj_idn),
          adc_voltage_(kTypeAdcInterface, obj_idn, kSubAdcVoltage),
          raw_value_(kTypeAdcInterface, obj_idn, kSubRawValue){};

    // Client Entries
    ClientEntry<float> adc_voltage_;
    ClientEntry<uint16_t> raw_value_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubRawValue + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &adc_voltage_,  // 0
            &raw_value_     // 1
        };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubAdcVoltage = 0;
    static const uint8_t kSubRawValue   = 1;
};

#endif /* ADC_INTERFACE_CLIENT_HPP_ */