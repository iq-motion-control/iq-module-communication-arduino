/*
  Copyright 2019 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: temperature_estimator_client.hpp
  Last update: 3/7/2019 by Raphael Van Hoffelen
  Author: Matthew Piccoli
  Contributors: Raphael Van Hoffelen
*/


#ifndef TEMPERATURE_ESTIMATOR_CLIENT_HPP_
#define TEMPERATURE_ESTIMATOR_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeTemperatureEstimatorClient = 77;

class TemperatureEstimatorClient: public ClientAbstract{
  public:
    TemperatureEstimatorClient(uint8_t obj_idn):
      ClientAbstract(       kTypeTemperatureEstimatorClient, obj_idn),
      temp_(                kTypeTemperatureEstimatorClient, obj_idn, kSubTemp),
      otw_(                 kTypeTemperatureEstimatorClient, obj_idn, kSubOtw),
      otlo_(                kTypeTemperatureEstimatorClient, obj_idn, kSubOtlo),
      thermal_resistance_(  kTypeTemperatureEstimatorClient, obj_idn, kSubThermalResistance),
      thermal_capacitance_( kTypeTemperatureEstimatorClient, obj_idn, kSubThermalCapacitance),
      derate_(              kTypeTemperatureEstimatorClient, obj_idn, kSubDerate)
      {};

    // Client Entries
    // Control commands
    ClientEntry<float>    temp_;
    ClientEntry<float>    otw_;
    ClientEntry<float>    otlo_;
    ClientEntry<float>    thermal_resistance_;
    ClientEntry<float>    thermal_capacitance_;
    ClientEntry<int32_t>  derate_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length)
    {
      static const uint8_t kEntryLength = kSubDerate+1;
      ClientEntryAbstract* entry_array[kEntryLength] = {
        &temp_,               // 0
        &otw_,                // 1
        &otlo_,               // 2
        &thermal_resistance_, // 3
        &thermal_capacitance_,// 4
        &derate_              // 5
      };

      ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

  private:
    static const uint8_t kSubTemp =               0;
    static const uint8_t kSubOtw =                1;
    static const uint8_t kSubOtlo =               2;
    static const uint8_t kSubThermalResistance =  3;
    static const uint8_t kSubThermalCapacitance = 4;
    static const uint8_t kSubDerate =             5;
};

#endif /* TEMPERATURE_ESTIMATOR_CLIENT_HPP_ */
