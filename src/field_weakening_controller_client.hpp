/*
    Copyright 2026 Vertiq, Inc support@vertiq.co

    This file is part of the IQ C++ API.

    This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

#ifndef FIELD_WEAKENING_CONTROLLER_CLIENT_HPP_
#define FIELD_WEAKENING_CONTROLLER_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeFieldWeakeningController = 105;

class FieldWeakeningControllerClient : public ClientAbstract {
    public:
    FieldWeakeningControllerClient(uint8_t obj_idn)
        : ClientAbstract(kTypeFieldWeakeningController, obj_idn),
            regulation_mode_(kTypeFieldWeakeningController, obj_idn, kSubRegulationMode),
            field_weakened_q_current_(kTypeFieldWeakeningController, obj_idn, kSubFieldWeakenedQCurrent),
            field_weakened_d_current_(kTypeFieldWeakeningController, obj_idn, kSubFieldWeakenedDCurrent),
            current_limit_regulated_q_current_(kTypeFieldWeakeningController, obj_idn, kSubCurrentLimitRegulatedQCurrent),
            current_limit_regulated_d_current_(kTypeFieldWeakeningController, obj_idn, kSubCurrentLimitRegulatedDCurrent)
            {};

    // Client Entries
    ClientEntry<uint8_t> regulation_mode_;
    ClientEntry<float> field_weakened_q_current_;
    ClientEntry<float> field_weakened_d_current_;
    ClientEntry<float> current_limit_regulated_q_current_;
    ClientEntry<float> current_limit_regulated_d_current_;
    
    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength = kSubCurrentLimitRegulatedDCurrent + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &regulation_mode_, // 0
            &field_weakened_q_current_, // 1
            &field_weakened_d_current_, // 2
            &current_limit_regulated_q_current_, // 3
            &current_limit_regulated_d_current_, // 4
            };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

    private:
    static const uint8_t kSubRegulationMode = 0;
    static const uint8_t kSubFieldWeakenedQCurrent = 1;
    static const uint8_t kSubFieldWeakenedDCurrent = 2;
    static const uint8_t kSubCurrentLimitRegulatedQCurrent = 3;
    static const uint8_t kSubCurrentLimitRegulatedDCurrent = 4;
    
};

#endif /* FIELD_WEAKENING_CONTROLLER_CLIENT_HPP_ */