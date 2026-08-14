/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: voltage_superposition_client.hpp
  Last update: 2023/04/19 by Ben Quan
  Author: Luca Scheuer
  Contributors: Ben Quan, Luca Scheuer
*/

#ifndef COMMON_CPP_INC_VOLTAGE_SUPERPOSITION_CLIENT_HPP_
#define COMMON_CPP_INC_VOLTAGE_SUPERPOSITION_CLIENT_HPP_

#include "client_communication.hpp"
#include "communication_interface.h"

const uint8_t kTypeVoltageSuperposition = 74;

class VoltageSuperPositionClient : public ClientAbstract {
   public:
    VoltageSuperPositionClient(uint8_t obj_idn)
        : ClientAbstract(kTypeVoltageSuperposition, obj_idn),
          zero_angle_(kTypeVoltageSuperposition, obj_idn, kSubZeroAngle),
          frequency_(kTypeVoltageSuperposition, obj_idn, kSubFrequency),
          phase_(kTypeVoltageSuperposition, obj_idn, kSubPhase),
          amplitude_(kTypeVoltageSuperposition, obj_idn, kSubAmplitude),
          voltage_(kTypeVoltageSuperposition, obj_idn, kSubVoltage),
          max_allowed_amplitude_(kTypeVoltageSuperposition, obj_idn, kSubMaxAllowedAmplitude),
          velocity_cutoff_(kTypeVoltageSuperposition, obj_idn, kSubVelocityCutoff),
          poly_limit_zero_(kTypeVoltageSuperposition, obj_idn, kSubPolyLimitZero),
          poly_limit_one_(kTypeVoltageSuperposition, obj_idn, kSubPolyLimitOne),
          poly_limit_two_(kTypeVoltageSuperposition, obj_idn, kSubPolyLimitTwo),
          poly_limit_three_(kTypeVoltageSuperposition, obj_idn, kSubPolyLimitThree),
          phase_lead_time_(kTypeVoltageSuperposition, obj_idn, kSubPhaseLeadTime),
          phase_lead_angle_(kTypeVoltageSuperposition, obj_idn, kSubPhaseLeadAngle),
          phase_act_(kTypeVoltageSuperposition, obj_idn, kSubPhaseActual),
          amplitude_act_(kTypeVoltageSuperposition, obj_idn, kSubAmplitudeActual),
          sample_mechanical_zero_(kTypeVoltageSuperposition, obj_idn, kSubSampleMechanicalZero),
          propeller_torque_offset_angle_(kTypeVoltageSuperposition, obj_idn,
                                         kSubPropellerTorqueOffsetAngle){};

    // Client Entries
    ClientEntry<float> zero_angle_;
    ClientEntry<uint8_t> frequency_;
    ClientEntry<float> phase_;
    ClientEntry<float> amplitude_;
    ClientEntry<float> voltage_;
    ClientEntry<float> max_allowed_amplitude_;
    ClientEntry<float> velocity_cutoff_;
    ClientEntry<float> poly_limit_zero_;
    ClientEntry<float> poly_limit_one_;
    ClientEntry<float> poly_limit_two_;
    ClientEntry<float> poly_limit_three_;
    ClientEntry<float> phase_lead_time_;
    ClientEntry<float> phase_lead_angle_;
    ClientEntry<float> phase_act_;
    ClientEntry<float> amplitude_act_;
    ClientEntryVoid sample_mechanical_zero_;
    ClientEntry<float> propeller_torque_offset_angle_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) override {
        static const uint8_t kEntryLength              = kSubPropellerTorqueOffsetAngle + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &zero_angle_,                    // 0
            &frequency_,                     // 1
            &phase_,                         // 2
            &amplitude_,                     // 3
            &voltage_,                       // 4
            &max_allowed_amplitude_,         // 5
            &velocity_cutoff_,               // 6
            &poly_limit_zero_,               // 7
            &poly_limit_one_,                // 8
            &poly_limit_two_,                // 9
            &poly_limit_three_,              // 10
            &phase_lead_time_,               // 11
            &phase_lead_angle_,              // 12
            &phase_act_,                     // 13
            &amplitude_act_,                 // 14
            &sample_mechanical_zero_,        // 15
            &propeller_torque_offset_angle_  // 16

        };

        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubZeroAngle                  = 0;
    static const uint8_t kSubFrequency                  = 1;
    static const uint8_t kSubPhase                      = 2;
    static const uint8_t kSubAmplitude                  = 3;
    static const uint8_t kSubVoltage                    = 4;
    static const uint8_t kSubMaxAllowedAmplitude        = 5;
    static const uint8_t kSubVelocityCutoff             = 6;
    static const uint8_t kSubPolyLimitZero              = 7;
    static const uint8_t kSubPolyLimitOne               = 8;
    static const uint8_t kSubPolyLimitTwo               = 9;
    static const uint8_t kSubPolyLimitThree             = 10;
    static const uint8_t kSubPhaseLeadTime              = 11;
    static const uint8_t kSubPhaseLeadAngle             = 12;
    static const uint8_t kSubPhaseActual                = 13;
    static const uint8_t kSubAmplitudeActual            = 14;
    static const uint8_t kSubSampleMechanicalZero       = 15;
    static const uint8_t kSubPropellerTorqueOffsetAngle = 16;
};

#endif