/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: gpio_controller_client.hpp
  Last update: 2023/04/18 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef GPIO_CONTROLLER_CLIENT_HPP_
#define GPIO_CONTROLLER_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeGpioController = 90;

class GpioControllerClient : public ClientAbstract {
   public:
    GpioControllerClient(uint8_t obj_idn)
        : ClientAbstract(kTypeGpioController, obj_idn),
          mode_register_(kTypeGpioController, obj_idn, kSubModeRegister),
          inputs_register_(kTypeGpioController, obj_idn, kSubInputsRegister),
          outputs_register_(kTypeGpioController, obj_idn, kSubOutputsRegister),
          use_pull_register_(kTypeGpioController, obj_idn, kSubUsePullRegister),
          pull_type_register_(kTypeGpioController, obj_idn, kSubPullTypeRegister),
          push_pull_open_drain_register_(kTypeGpioController, obj_idn, kSubPushPullOpenDrainRegister),
          addressable_gpio_mode_(kTypeGpioController, obj_idn, kSubAddressableGpioMode),
          addressable_outputs_(kTypeGpioController, obj_idn, kSubAddressableOutputs),
          addressable_use_pull_(kTypeGpioController, obj_idn, kSubAddressableUsePull),
          addressable_pull_type_(kTypeGpioController, obj_idn, kSubAddressablePullType),
          addressable_push_pull_open_drain_(kTypeGpioController, obj_idn, kSubAddressablePushPullOpenDrain){};

    // Client Entries
    ClientEntry<uint8_t> mode_register_;                     // 0
    ClientEntry<uint8_t> inputs_register_;                   // 1
    ClientEntry<uint8_t> outputs_register_;                  // 2
    ClientEntry<uint8_t> use_pull_register_;                 // 3
    ClientEntry<uint8_t> pull_type_register_;                // 4
    ClientEntry<uint8_t> push_pull_open_drain_register_;     // 5
    ClientEntry<uint8_t> addressable_gpio_mode_;             // 6
    ClientEntry<uint8_t> addressable_outputs_;               // 7
    ClientEntry<uint8_t> addressable_use_pull_;              // 8
    ClientEntry<uint8_t> addressable_pull_type_;             // 9
    ClientEntry<uint8_t> addressable_push_pull_open_drain_;  // 10

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubAddressablePushPullOpenDrain + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &mode_register_,                    // 0
            &inputs_register_,                  // 1
            &outputs_register_,                 // 2
            &use_pull_register_,                // 3
            &pull_type_register_,               // 4
            &push_pull_open_drain_register_,    // 5
            &addressable_gpio_mode_,            // 6
            &addressable_outputs_,              // 7
            &addressable_use_pull_,             // 8
            &addressable_pull_type_,            // 9
            &addressable_push_pull_open_drain_  // 10
        };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubModeRegister                 = 0;
    static const uint8_t kSubInputsRegister               = 1;
    static const uint8_t kSubOutputsRegister              = 2;
    static const uint8_t kSubUsePullRegister              = 3;
    static const uint8_t kSubPullTypeRegister             = 4;
    static const uint8_t kSubPushPullOpenDrainRegister    = 5;
    static const uint8_t kSubAddressableGpioMode          = 6;
    static const uint8_t kSubAddressableOutputs           = 7;
    static const uint8_t kSubAddressableUsePull           = 8;
    static const uint8_t kSubAddressablePullType          = 9;
    static const uint8_t kSubAddressablePushPullOpenDrain = 10;
};

#endif /* GPIO_CONTROLLER_CLIENT_HPP_ */