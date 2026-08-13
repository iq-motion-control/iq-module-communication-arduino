/*
  Copyright 2026 Vertiq, Inc support@vertiq.co

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: throttle_source_manager_client.hpp
  Last update: 2026/03/13 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef THROTTLE_SOURCE_MANAGER_CLIENT_HPP_
#define THROTTLE_SOURCE_MANAGER_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeThrottleSourceManager = 104;

class ThrottleSourceManagerClient : public ClientAbstract {
   public:
    ThrottleSourceManagerClient(uint8_t obj_idn)
        : ClientAbstract(kTypeThrottleSourceManager, obj_idn),
          throttle_timeout_(kTypeThrottleSourceManager, obj_idn, kSubThrottleTimeout),
          dronecan_priority_(kTypeThrottleSourceManager, obj_idn, kSubDronecanPriority),
          hobby_priority_(kTypeThrottleSourceManager, obj_idn, kSubHobbyPriority),
          iquart_priority_(kTypeThrottleSourceManager, obj_idn, kSubIquartPriority),
          current_active_throttle_source_(kTypeThrottleSourceManager, obj_idn, kSubCurrentActiveThrottleSource)
          {};

    // Client Entries
    ClientEntry<float>      throttle_timeout_;
    ClientEntry<uint8_t>    dronecan_priority_;
    ClientEntry<uint8_t>    hobby_priority_;
    ClientEntry<uint8_t>    iquart_priority_;
    ClientEntry<uint8_t>    current_active_throttle_source_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubCurrentActiveThrottleSource + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &throttle_timeout_,               // 0
            &dronecan_priority_,              // 1
            &hobby_priority_,                 // 2
            &iquart_priority_,                // 3
            &current_active_throttle_source_  // 4
        };

        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubThrottleTimeout              = 0;
    static const uint8_t kSubDronecanPriority             = 1;
    static const uint8_t kSubHobbyPriority                = 2;
    static const uint8_t kSubIquartPriority               = 3;
    static const uint8_t kSubCurrentActiveThrottleSource  = 4;
};

#endif /* THROTTLE_SOURCE_MANAGER_CLIENT_HPP_ */
