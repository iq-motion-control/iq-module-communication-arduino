/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: iquart_flight_controller_interface_client.hpp
  Last update: 2023/04/19 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef IQUART_FLIGHT_CONTROLLER_INTERFACE_CLIENT_HPP_
#define IQUART_FLIGHT_CONTROLLER_INTERFACE_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeIQUartFlightControllerInterface = 88;

struct IFCITelemetryData {
    int16_t mcu_temp;  // TODO add units
    int16_t coil_temp;
    int16_t voltage;
    int16_t current;
    int16_t consumption;
    int16_t speed;
    uint32_t uptime;
};

class IQUartFlightControllerInterfaceClient : public ClientAbstract {
   public:
    IQUartFlightControllerInterfaceClient(uint8_t obj_idn)
        : ClientAbstract(kTypeIQUartFlightControllerInterface, obj_idn),
          telemetry_(kTypeIQUartFlightControllerInterface, obj_idn, kSubTelemetry),
          throttle_cvi_(kTypeIQUartFlightControllerInterface, obj_idn, kSubThrottleCvi),
          x_cvi_(kTypeIQUartFlightControllerInterface, obj_idn, kSubXCvi),
          y_cvi_(kTypeIQUartFlightControllerInterface, obj_idn, kSubYCvi){};

    // Client Entries
    ClientEntry<IFCITelemetryData> telemetry_;
    ClientEntry<uint8_t> throttle_cvi_;
    ClientEntry<uint8_t> x_cvi_;
    ClientEntry<uint8_t> y_cvi_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubYCvi + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            nullptr,         // 0
            &telemetry_,     // 1
            &throttle_cvi_,  // 2
            &x_cvi_,         // 3
            &y_cvi_          // 4
        };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubTelemetry   = 1;
    static const uint8_t kSubThrottleCvi = 2;
    static const uint8_t kSubXCvi        = 3;
    static const uint8_t kSubYCvi        = 4;
};

#endif /* IQUART_FLIGHT_CONTROLLER_INTERFACE_CLIENT_HPP_ */