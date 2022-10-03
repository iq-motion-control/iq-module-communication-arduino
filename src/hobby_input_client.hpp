/*
  Copyright 2019 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: hobby_input_client.hpp
  Last update: 09/16/2022 by Ben Quan
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
      reset_calibration_(         kTypeHobbyInput, obj_idn, kSubResetCalibration)
      {};

    // Client Entries
    // Control commands
    ClientEntry<uint8_t>    allowed_protocols_;
    ClientEntry<uint8_t>    protocol_;
    ClientEntry<uint8_t>    calibrated_protocol_;
    ClientEntry<uint32_t>   calibrated_high_ticks_us_;
    ClientEntry<uint32_t>   calibrated_low_ticks_us_;
    ClientEntryVoid         reset_calibration_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length)
    {
      static const uint8_t kEntryLength = kSubResetCalibration+1;
      ClientEntryAbstract* entry_array[kEntryLength] = {
        &allowed_protocols_,        // 0
        &protocol_,                 // 1
        &calibrated_protocol_,      // 2
        &calibrated_high_ticks_us_, // 3
        &calibrated_low_ticks_us_,  // 4
        &reset_calibration_         // 5
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
};

#endif /* HOBBY_INPUT_CLIENT_HPP_ */
