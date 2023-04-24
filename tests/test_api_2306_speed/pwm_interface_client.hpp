/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: pwm_interface_client.hpp
  Last update: 2023/04/18 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef PWM_INTERFACE_CLIENT_HPP_
#define PWM_INTERFACE_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypePwmInterface = 92;

class PwmInterfaceClient : public ClientAbstract {
   public:
    PwmInterfaceClient(uint8_t obj_idn)
        : ClientAbstract(kTypePwmInterface, obj_idn),
          pwm_frequency_(kTypePwmInterface, obj_idn, kSubPwmFrequency),
          duty_cycle_(kTypePwmInterface, obj_idn, kSubDutyCycle),
          pwm_mode_(kTypePwmInterface, obj_idn, kSubPwmMode){};

    // Client Entries
    ClientEntry<uint32_t> pwm_frequency_;
    ClientEntry<uint8_t> duty_cycle_;
    ClientEntry<uint8_t> pwm_mode_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubPwmMode + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &pwm_frequency_,  // 0
            &duty_cycle_,     // 1
            &pwm_mode_        // 2
        };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubPwmFrequency = 0;
    static const uint8_t kSubDutyCycle    = 1;
    static const uint8_t kSubPwmMode      = 2;
};

#endif /* PWM_INTERFACE_CLIENT_HPP_ */