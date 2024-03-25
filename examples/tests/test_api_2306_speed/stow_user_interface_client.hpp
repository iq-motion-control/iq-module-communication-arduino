/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: stow_user_interface_client.hpp
  Last update: 2023/04/12 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef STOW_USER_INTERFACE_CLIENT_HPP_
#define STOW_USER_INTERFACE_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeStowUserInterface = 85;

class StowUserInterfaceClient : public ClientAbstract {
   public:
    StowUserInterfaceClient(uint8_t obj_idn)
        : ClientAbstract(kTypeStowUserInterface, obj_idn),
          zero_angle_(kTypeStowUserInterface, obj_idn, kSubZeroAngle),
          target_angle_(kTypeStowUserInterface, obj_idn, kSubTargetAngle),
          target_acceleration_(kTypeStowUserInterface, obj_idn, kSubTargetAcceleration),
          sample_zero_(kTypeStowUserInterface, obj_idn, kSubSampleZero),
          user_stow_request_(kTypeStowUserInterface, obj_idn, kSubUserStowRequest),
          stow_kp_(kTypeStowUserInterface, obj_idn, kSubStowKp),
          stow_ki_(kTypeStowUserInterface, obj_idn, kSubStowKi),
          stow_kd_(kTypeStowUserInterface, obj_idn, kSubStowKd),
          hold_stow_(kTypeStowUserInterface, obj_idn, kSubHoldStow),
          stow_status_(kTypeStowUserInterface, obj_idn, kSubStowStatus),
          stow_result_(kTypeStowUserInterface, obj_idn, kSubStowResult){};

    // Client Entries
    ClientEntry<float> zero_angle_;
    ClientEntry<float> target_angle_;
    ClientEntry<float> target_acceleration_;
    ClientEntryVoid sample_zero_;
    ClientEntryVoid user_stow_request_;
    ClientEntry<float> stow_kp_;
    ClientEntry<float> stow_ki_;
    ClientEntry<float> stow_kd_;
    ClientEntry<uint8_t> hold_stow_;
    ClientEntry<uint8_t> stow_status_;
    ClientEntry<uint8_t> stow_result_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubStowResult + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &zero_angle_,           // 0
            &target_angle_,         // 1
            &target_acceleration_,  // 2
            &sample_zero_,          // 3
            &user_stow_request_,    // 4
            &stow_kp_,              // 5
            &stow_ki_,              // 6
            &stow_kd_,              // 7
            &hold_stow_,            // 8
            &stow_status_,          // 9
            &stow_result_           // 10
        };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubZeroAngle          = 0;
    static const uint8_t kSubTargetAngle        = 1;
    static const uint8_t kSubTargetAcceleration = 2;
    static const uint8_t kSubSampleZero         = 3;
    static const uint8_t kSubUserStowRequest    = 4;
    static const uint8_t kSubStowKp             = 5;
    static const uint8_t kSubStowKi             = 6;
    static const uint8_t kSubStowKd             = 7;
    static const uint8_t kSubHoldStow           = 8;
    static const uint8_t kSubStowStatus         = 9;
    static const uint8_t kSubStowResult         = 10;
};

#endif /* STOW_USER_INTERFACE_CLIENT_HPP_ */