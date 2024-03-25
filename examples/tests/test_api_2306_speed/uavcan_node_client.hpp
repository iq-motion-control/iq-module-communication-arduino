
/*
  Copyright 2019 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: uavcan_node_client.hpp
  Last update: 2023/04/11 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef UAVCAN_NODE_CLIENT_HPP_
#define UAVCAN_NODE_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeUavcanNode = 80;

class UavcanNodeClient : public ClientAbstract {
   public:
    UavcanNodeClient(uint8_t obj_idn)
        : ClientAbstract(kTypeUavcanNode, obj_idn),
          uavcan_node_id_(kTypeUavcanNode, obj_idn, kSubUavcanNodeId),
          uavcan_esc_index_(kTypeUavcanNode, obj_idn, kSubUavcanEscIndex),
          zero_behavior_(kTypeUavcanNode, obj_idn, kSubZeroBehavior),
          last_error_code_(kTypeUavcanNode, obj_idn, kSubLastErrorCode),
          receive_error_counter_(kTypeUavcanNode, obj_idn, kSubReceiveErrorCounter),
          transmit_error_counter_(kTypeUavcanNode, obj_idn, kSubTransmitErrorCounter),
          bus_off_flag_(kTypeUavcanNode, obj_idn, kSubBusOffFlag),
          error_passive_flag_(kTypeUavcanNode, obj_idn, kSubErrorPassiveFlag),
          error_warning_flag_(kTypeUavcanNode, obj_idn, kSubErrorWarningFlag),
          telemetry_frequency_(kTypeUavcanNode, obj_idn, kSubTelemetryFrequency),
          bit_rate_(kTypeUavcanNode, obj_idn, kSubBitRate),
          bypass_arming_(kTypeUavcanNode, obj_idn, kSubBypassArming){};

    // Client Entries
    ClientEntry<uint32_t> uavcan_node_id_;
    ClientEntry<uint32_t> uavcan_esc_index_;
    ClientEntry<uint32_t> zero_behavior_;
    ClientEntry<uint8_t> last_error_code_;
    ClientEntry<uint8_t> receive_error_counter_;
    ClientEntry<uint8_t> transmit_error_counter_;
    ClientEntry<uint8_t> bus_off_flag_;
    ClientEntry<uint8_t> error_passive_flag_;
    ClientEntry<uint8_t> error_warning_flag_;
    ClientEntry<uint32_t> telemetry_frequency_;
    ClientEntry<uint32_t> bit_rate_;
    ClientEntry<uint8_t> bypass_arming_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubBypassArming + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &uavcan_node_id_,          // 0
            &uavcan_esc_index_,        // 1
            &zero_behavior_,           // 2
            &last_error_code_,         // 3
            &receive_error_counter_,   // 4
            &transmit_error_counter_,  // 5
            &bus_off_flag_,            // 6
            &error_passive_flag_,      // 7
            &error_warning_flag_,      // 8
            &telemetry_frequency_,     // 9
            &bit_rate_,                // 10
            &bypass_arming_            // 11
        };

        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubUavcanNodeId         = 0;
    static const uint8_t kSubUavcanEscIndex       = 1;
    static const uint8_t kSubZeroBehavior         = 2;
    static const uint8_t kSubLastErrorCode        = 3;
    static const uint8_t kSubReceiveErrorCounter  = 4;
    static const uint8_t kSubTransmitErrorCounter = 5;
    static const uint8_t kSubBusOffFlag           = 6;
    static const uint8_t kSubErrorPassiveFlag     = 7;
    static const uint8_t kSubErrorWarningFlag     = 8;
    static const uint8_t kSubTelemetryFrequency   = 9;
    static const uint8_t kSubBitRate              = 10;
    static const uint8_t kSubBypassArming         = 11;
};

#endif /* UAVCAN_NODE_CLIENT_HPP_ */