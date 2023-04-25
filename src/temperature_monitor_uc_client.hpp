/*
  Copyright 2019 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: temperature_monitor_uc_client.hpp
  Last update: 3/7/2019 by Raphael Van Hoffelen
  Author: Matthew Piccoli
  Contributors: Raphael Van Hoffelen
*/

#ifndef TEMPERATURE_MONITOR_UC_CLIENT_HPP_
#define TEMPERATURE_MONITOR_UC_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeTemperatureMonitorUcClient = 73;

class TemperatureMonitorUcClient: public ClientAbstract{
  public:
    TemperatureMonitorUcClient(uint8_t obj_idn):
      ClientAbstract( kTypeTemperatureMonitorUcClient, obj_idn),
      uc_temp_(       kTypeTemperatureMonitorUcClient, obj_idn, kSubUcTemp),
      filter_fs_(     kTypeTemperatureMonitorUcClient, obj_idn, kSubFilterFs),
      filter_fc_(     kTypeTemperatureMonitorUcClient, obj_idn, kSubFilterFc),
      otw_(           kTypeTemperatureMonitorUcClient, obj_idn, kSubOtw),
      otlo_(          kTypeTemperatureMonitorUcClient, obj_idn, kSubOtlo),
      derate_(        kTypeTemperatureMonitorUcClient, obj_idn, kSubDerate)
      {};

    // Client Entries
    // Control commands
    ClientEntry<float>    uc_temp_;
    ClientEntry<uint32_t> filter_fs_;
    ClientEntry<uint32_t> filter_fc_;
    ClientEntry<float>    otw_;
    ClientEntry<float>    otlo_;
    ClientEntry<float>    derate_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length)
    {
      static const uint8_t kEntryLength = kSubDerate+1;
      ClientEntryAbstract* entry_array[kEntryLength] = {
        &uc_temp_,    // 0
        &filter_fs_,  // 1
        &filter_fc_,  // 2
        &otw_,        // 3
        &otlo_,       // 4
        &derate_      // 5
      };

      ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

  private:
    static const uint8_t kSubUcTemp =   0;
    static const uint8_t kSubFilterFs = 1;
    static const uint8_t kSubFilterFc = 2;
    static const uint8_t kSubOtw =      3;
    static const uint8_t kSubOtlo =     4;
    static const uint8_t kSubDerate =   5;
};

#endif /* TEMPERATURE_MONITOR_UC_CLIENT_HPP_ */
