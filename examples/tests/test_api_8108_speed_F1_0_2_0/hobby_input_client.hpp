/*
  Copyright 2025 Vertiq, Inc support@vertiq.co

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: hobby_input_client.hpp
  Last update: 2025-08-26 by Ben Quan
  Author: Matthew Piccoli
  Contributors: Ben Quan, Raphael Van Hoffelen
*/

#ifndef HOBBY_INPUT_CLIENT_HPP_
#define HOBBY_INPUT_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeHobbyInput = 76;

class HobbyInputClient: public ClientAbstract{
  public:
    HobbyInputClient(uint8_t obj_idn):
      ClientAbstract(             kTypeHobbyInput, obj_idn),
      allowed_protocols_(         kTypeHobbyInput, obj_idn, kSubAllowedProtocols),
      protocol_(                  kTypeHobbyInput, obj_idn, kSubProtocol),
      calibrated_protocol_(       kTypeHobbyInput, obj_idn, kSubCalibratedProtocol),
      calibrated_high_ticks_us_(  kTypeHobbyInput, obj_idn, kSubCalibratedHighTicksUs),
      calibrated_low_ticks_us_(   kTypeHobbyInput, obj_idn, kSubCalibratedLowTicksUs),
      reset_calibration_(         kTypeHobbyInput, obj_idn, kSubResetCalibration),
      hobby_telemetry_frequency_(kTypeHobbyInput, obj_idn, kSubHobbyTelemetryFrequency),
      hobby_telemetry_speed_style_(kTypeHobbyInput, obj_idn, kSubHobbyTelemetrySpeedStyle),
      allow_dshot_disarming_message_(kTypeHobbyInput, obj_idn, kSubAllowDshotDisarmingMessage)
      {};

    // Client Entries
    // Control commands
    ClientEntry<uint8_t>    allowed_protocols_;
    ClientEntry<uint8_t>    protocol_;
    ClientEntry<uint8_t>    calibrated_protocol_;
    ClientEntry<uint32_t>   calibrated_high_ticks_us_;
    ClientEntry<uint32_t>   calibrated_low_ticks_us_;
    ClientEntryVoid         reset_calibration_;
    ClientEntry<uint16_t> hobby_telemetry_frequency_;
    ClientEntry<uint8_t> hobby_telemetry_speed_style_;
    ClientEntry<uint8_t> allow_dshot_disarming_message_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length)
    {
      static const uint8_t kEntryLength = kSubAllowDshotDisarmingMessage+1;
      ClientEntryAbstract* entry_array[kEntryLength] = {
        &allowed_protocols_,        // 0
        &protocol_,                 // 1
        &calibrated_protocol_,      // 2
        &calibrated_high_ticks_us_, // 3
        &calibrated_low_ticks_us_,  // 4
        &reset_calibration_,         // 5
        &hobby_telemetry_frequency_, // 6
        &hobby_telemetry_speed_style_, // 7
        &allow_dshot_disarming_message_ // 8
      };

      ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

  private:
    static const uint8_t kSubAllowedProtocols       =  0;
    static const uint8_t kSubProtocol               =  1;
    static const uint8_t kSubCalibratedProtocol     =  2;
    static const uint8_t kSubCalibratedHighTicksUs  =  3;
    static const uint8_t kSubCalibratedLowTicksUs   =  4;
    static const uint8_t kSubResetCalibration       =  5;    
    static const uint8_t kSubHobbyTelemetryFrequency = 6;
    static const uint8_t kSubHobbyTelemetrySpeedStyle = 7;
    static const uint8_t kSubAllowDshotDisarmingMessage = 8;
};

#endif /* HOBBY_INPUT_CLIENT_HPP_ */
