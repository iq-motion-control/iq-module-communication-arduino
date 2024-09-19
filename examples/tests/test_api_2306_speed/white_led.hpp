/*
  Copyright 2024 Vertiq, Inc support@vertiq.co

  This file is part of the Vertiq C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

#ifndef WHITE_LED_CLIENT_H
#define WHITE_LED_CLIENT_H

#include "client_communication.hpp"

const uint8_t kTypeWhiteLed = 101;

class WhiteLedClient : public ClientAbstract {
   public:
    WhiteLedClient(uint8_t obj_idn)
        : ClientAbstract(kTypeWhiteLed, obj_idn),
          intensity_(kTypeWhiteLed, obj_idn, kSubIntensity),
          strobe_active_(kTypeWhiteLed, obj_idn, kSubStrobeActive),
          strobe_period_(kTypeWhiteLed, obj_idn, kSubStrobePeriod),
          strobe_pattern_(kTypeWhiteLed, obj_idn, kSubStrobePattern){};

    // Client Entries
	ClientEntry<uint8_t> intensity_;
	ClientEntry<uint8_t> strobe_active_;
	ClientEntry<float> strobe_period_;
	ClientEntry<uint32_t> strobe_pattern_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubStrobePattern + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
			&intensity_,        // 0
			&strobe_active_,    // 1
			&strobe_period_,    // 2
			&strobe_pattern_    // 3
        };

        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubIntensity        = 0;
    static const uint8_t kSubStrobeActive     = 1;
    static const uint8_t kSubStrobePeriod     = 2;
    static const uint8_t kSubStrobePattern    = 3;

};

#endif  // WHITE_LED_CLIENT_H
