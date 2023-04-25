/*
  Copyright 2019 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: propeller_motor_control_client.hpp
  Last update: 2023/04/11 by Ben Quan
  Author: Matthew Piccoli
  Contributors: Ben Quan, Raphael Van Hoffelen
*/

#ifndef PROPELLER_MOTOR_CONTROL_CLIENT_HPP_
#define PROPELLER_MOTOR_CONTROL_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypePropellerMotorControl = 52;

class PropellerMotorControlClient : public ClientAbstract {
   public:
    PropellerMotorControlClient(uint8_t obj_idn)
        : ClientAbstract(kTypePropellerMotorControl, obj_idn),
          ctrl_mode_(kTypePropellerMotorControl, obj_idn, kSubCtrlMode),
          ctrl_brake_(kTypePropellerMotorControl, obj_idn, kSubCtrlBrake),
          ctrl_coast_(kTypePropellerMotorControl, obj_idn, kSubCtrlCoast),
          ctrl_pwm_(kTypePropellerMotorControl, obj_idn, kSubCtrlPwm),
          ctrl_volts_(kTypePropellerMotorControl, obj_idn, kSubCtrlVolts),
          ctrl_velocity_(kTypePropellerMotorControl, obj_idn, kSubCtrlVelocity),
          ctrl_thrust_(kTypePropellerMotorControl, obj_idn, kSubCtrlThrust),
          velocity_kp_(kTypePropellerMotorControl, obj_idn, kSubVelocityKp),
          velocity_ki_(kTypePropellerMotorControl, obj_idn, kSubVelocityKi),
          velocity_kd_(kTypePropellerMotorControl, obj_idn, kSubVelocityKd),
          velocity_ff0_(kTypePropellerMotorControl, obj_idn, kSubVelocityFF0),
          velocity_ff1_(kTypePropellerMotorControl, obj_idn, kSubVelocityFF1),
          velocity_ff2_(kTypePropellerMotorControl, obj_idn, kSubVelocityFF2),
          propeller_kt_pos_(kTypePropellerMotorControl, obj_idn, kSubPropellerKtPos),
          propeller_kt_neg_(kTypePropellerMotorControl, obj_idn, kSubPropellerKtNeg),
          timeout_(kTypePropellerMotorControl, obj_idn, kSubTimeout),
          input_filter_fc_(kTypePropellerMotorControl, obj_idn, kSubInputFilterFc),
          timeout_meaning_(kTypePropellerMotorControl, obj_idn, kSubTimeoutMeaning),
          timeout_behavior_(kTypePropellerMotorControl, obj_idn, kSubTimeoutBehavior),
          timeout_song_option_(kTypePropellerMotorControl, obj_idn, kSubTimeoutSongOption){};

    // Client Entries
    // Control commands
    ClientEntry<uint8_t> ctrl_mode_;
    ClientEntryVoid ctrl_brake_;
    ClientEntryVoid ctrl_coast_;
    ClientEntry<float> ctrl_pwm_;
    ClientEntry<float> ctrl_volts_;
    ClientEntry<float> ctrl_velocity_;
    ClientEntry<float> ctrl_thrust_;
    // Velocity control
    ClientEntry<float> velocity_kp_;
    ClientEntry<float> velocity_ki_;
    ClientEntry<float> velocity_kd_;
    ClientEntry<float> velocity_ff0_;
    ClientEntry<float> velocity_ff1_;
    ClientEntry<float> velocity_ff2_;
    // Propeller values
    ClientEntry<float> propeller_kt_pos_;
    ClientEntry<float> propeller_kt_neg_;
    // Timeout
    ClientEntry<float> timeout_;
    // Filter
    ClientEntry<uint32_t> input_filter_fc_;
    ClientEntry<uint8_t> timeout_meaning_;
    ClientEntry<uint8_t> timeout_behavior_;
    ClientEntry<uint8_t> timeout_song_option_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubTimeoutSongOption + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &ctrl_mode_,           // 0
            &ctrl_brake_,          // 1
            &ctrl_coast_,          // 2
            &ctrl_pwm_,            // 3
            &ctrl_volts_,          // 4
            &ctrl_velocity_,       // 5
            &ctrl_thrust_,         // 6
            &velocity_kp_,         // 7
            &velocity_ki_,         // 8
            &velocity_kd_,         // 9
            &velocity_ff0_,        // 10
            &velocity_ff1_,        // 11
            &velocity_ff2_,        // 12
            &propeller_kt_pos_,    // 13
            &propeller_kt_neg_,    // 14
            &timeout_,             // 15
            &input_filter_fc_,     // 16
            &timeout_meaning_,     // 17
            &timeout_behavior_,    // 18
            &timeout_song_option_  // 19
        };

        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubCtrlMode          = 0;
    static const uint8_t kSubCtrlBrake         = 1;
    static const uint8_t kSubCtrlCoast         = 2;
    static const uint8_t kSubCtrlPwm           = 3;
    static const uint8_t kSubCtrlVolts         = 4;
    static const uint8_t kSubCtrlVelocity      = 5;
    static const uint8_t kSubCtrlThrust        = 6;
    static const uint8_t kSubVelocityKp        = 7;
    static const uint8_t kSubVelocityKi        = 8;
    static const uint8_t kSubVelocityKd        = 9;
    static const uint8_t kSubVelocityFF0       = 10;
    static const uint8_t kSubVelocityFF1       = 11;
    static const uint8_t kSubVelocityFF2       = 12;
    static const uint8_t kSubPropellerKtPos    = 13;
    static const uint8_t kSubPropellerKtNeg    = 14;
    static const uint8_t kSubTimeout           = 15;
    static const uint8_t kSubInputFilterFc     = 16;
    static const uint8_t kSubTimeoutMeaning    = 17;
    static const uint8_t kSubTimeoutBehavior   = 18;
    static const uint8_t kSubTimeoutSongOption = 19;
};

#endif /* PROPELLER_MOTOR_CONTROL_CLIENT_HPP_ */
