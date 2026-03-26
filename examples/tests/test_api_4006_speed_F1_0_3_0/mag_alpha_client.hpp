/*
  Copyright 2023 Vertiq support@vertiq.co

  This file is part of the Vertiq C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: mag_alpha_client.hpp
  Last update: 2023/06/29 by Ben Quan 
  Author: Ben Quan 
  Contributors: 
*/

#ifndef MAG_ALPHA_CLIENT_HPP
#define MAG_ALPHA_CLIENT_HPP

#include "client_communication.hpp"

const uint8_t kTypeMagAlpha = 75;

class MagAlphaClient: public ClientAbstract{
  public:
    MagAlphaClient(uint8_t obj_idn):
      ClientAbstract( kTypeMagAlpha, obj_idn),
        angle_raw_(kTypeMagAlpha, obj_idn, kSubAngleRaw),
        angle_rad_(kTypeMagAlpha, obj_idn, kSubAngleRad),
        alarm_(kTypeMagAlpha, obj_idn, kSubAlarm),
        mght_(kTypeMagAlpha, obj_idn, kSubMght),
        mglt_(kTypeMagAlpha, obj_idn, kSubMglt),
        reg_val_(kTypeMagAlpha, obj_idn, kSubRegVal),
        reg_adr_(kTypeMagAlpha, obj_idn, kSubRegAdr),
        reg_str_(kTypeMagAlpha, obj_idn, kSubRegStr)
    {};

    // Client Entries
    ClientEntry<uint32_t>    angle_raw_;
    ClientEntry<float>       angle_rad_;
    ClientEntry<uint8_t>     alarm_;
    ClientEntry<uint8_t>     mght_;
    ClientEntry<uint8_t>     mglt_;
    ClientEntry<uint16_t>    reg_val_;  
    ClientEntry<uint16_t>    reg_adr_;
    ClientEntryVoid          reg_str_;         

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length)
    {
      static const uint8_t kEntryLength = kSubRegStr+1;
      ClientEntryAbstract* entry_array[kEntryLength] = {
        &angle_raw_,    // 0
        &angle_rad_,    // 1
        &alarm_,        // 2
        &mght_,         // 3
        &mglt_,         // 4
        &reg_val_,      // 5
        &reg_adr_,      // 6
        &reg_str_       // 7
      };

      ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

  private:
    static const uint8_t kSubAngleRaw    = 0;
    static const uint8_t kSubAngleRad    = 1;
    static const uint8_t kSubAlarm       = 2;
    static const uint8_t kSubMght        = 3;
    static const uint8_t kSubMglt        = 4;
    static const uint8_t kSubRegVal      = 5;
    static const uint8_t kSubRegAdr      = 6;
    static const uint8_t kSubRegStr      = 7;
};

#endif // MAG_ALPHA_CLIENT_H