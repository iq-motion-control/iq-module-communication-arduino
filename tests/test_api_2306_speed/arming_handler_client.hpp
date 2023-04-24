/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: arming_handler_client.hpp
  Last update: 2023/04/19 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef ARMING_HANDLER_CLIENT_HPP_
#define ARMING_HANDLER_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeArmingHandler = 86;

class ArmingHandlerClient : public ClientAbstract {
   public:
    ArmingHandlerClient(uint8_t obj_idn)
        : ClientAbstract(kTypeArmingHandler, obj_idn),
          always_armed_(kTypeArmingHandler, obj_idn, kSubAlwaysArmed),
          arm_on_throttle_(kTypeArmingHandler, obj_idn, kSubArmOnThrottle),
          arm_throttle_upper_limit_(kTypeArmingHandler, obj_idn, kSubArmThrottleUpperLimit),
          arm_throttle_lower_limit_(kTypeArmingHandler, obj_idn, kSubArmThrottleLowerLimit),
          disarm_on_throttle_(kTypeArmingHandler, obj_idn, kSubDisarmOnThrottle),
          disarm_throttle_upper_limit_(kTypeArmingHandler, obj_idn, kSubDisarmThrottleUpperLimit),
          disarm_throttle_lower_limit_(kTypeArmingHandler, obj_idn, kSubDisarmThrottleLowerLimit),
          consecutive_arming_throttles_to_arm_(kTypeArmingHandler, obj_idn,
                                               kSubConsecutiveArmingThrottlesToArm),
          disarm_behavior_(kTypeArmingHandler, obj_idn, kSubDisarmBehavior),
          disarm_song_option_(kTypeArmingHandler, obj_idn, kSubDisarmSongOption),
          manual_arming_throttle_source_(kTypeArmingHandler, obj_idn, kSubManualArmingThrottleSource),
          motor_armed_(kTypeArmingHandler, obj_idn, kSubMotorArmed){};

    // Client Entries
    ClientEntry<uint8_t> always_armed_;
    ClientEntry<uint8_t> arm_on_throttle_;
    ClientEntry<float> arm_throttle_upper_limit_;
    ClientEntry<float> arm_throttle_lower_limit_;
    ClientEntry<uint8_t> disarm_on_throttle_;
    ClientEntry<float> disarm_throttle_upper_limit_;
    ClientEntry<float> disarm_throttle_lower_limit_;
    ClientEntry<uint32_t> consecutive_arming_throttles_to_arm_;
    ClientEntry<uint8_t> disarm_behavior_;
    ClientEntry<uint8_t> disarm_song_option_;
    ClientEntry<uint8_t> manual_arming_throttle_source_;
    ClientEntry<uint8_t> motor_armed_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubMotorArmed + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            nullptr,                                // 0
            &always_armed_,                         // 1
            &arm_on_throttle_,                      // 2
            &arm_throttle_upper_limit_,             // 3
            &arm_throttle_lower_limit_,             // 4
            &disarm_on_throttle_,                   // 5
            &disarm_throttle_upper_limit_,          // 6
            &disarm_throttle_lower_limit_,          // 7
            &consecutive_arming_throttles_to_arm_,  // 8
            &disarm_behavior_,                      // 9
            &disarm_song_option_,                   // 10
            &manual_arming_throttle_source_,        // 11
            &motor_armed_                           // 12
        };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubAlwaysArmed                     = 1;
    static const uint8_t kSubArmOnThrottle                   = 2;
    static const uint8_t kSubArmThrottleUpperLimit           = 3;
    static const uint8_t kSubArmThrottleLowerLimit           = 4;
    static const uint8_t kSubDisarmOnThrottle                = 5;
    static const uint8_t kSubDisarmThrottleUpperLimit        = 6;
    static const uint8_t kSubDisarmThrottleLowerLimit        = 7;
    static const uint8_t kSubConsecutiveArmingThrottlesToArm = 8;
    static const uint8_t kSubDisarmBehavior                  = 9;
    static const uint8_t kSubDisarmSongOption                = 10;
    static const uint8_t kSubManualArmingThrottleSource      = 11;
    static const uint8_t kSubMotorArmed                      = 12;
};

#endif /* ARMING_HANDLER_CLIENT_HPP_ */