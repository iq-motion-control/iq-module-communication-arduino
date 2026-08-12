/*
    Copyright 2025 Vertiq, Inc support@vertiq.co

    This file is part of the IQ C++ API.

    This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
    Name: current_safeties_client.hpp
    Last update: 2025-03-11 by Ben Quan
    Author: Ben Quan
    Contributors:
*/

#ifndef CURRENT_SAFETIES_CLIENT_HPP_
#define CURRENT_SAFETIES_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeCurrentSafeties = 102;

class CurrentSafetiesClient : public ClientAbstract {
    public:
    CurrentSafetiesClient(uint8_t obj_idn)
        : ClientAbstract(kTypeCurrentSafeties, obj_idn),
            final_max_current_derate_(kTypeCurrentSafeties, obj_idn, kSubFinalMaxCurrentDerate),
            base_max_current_(kTypeCurrentSafeties, obj_idn, kSubBaseMaxCurrent),
            derated_max_current_(kTypeCurrentSafeties, obj_idn, kSubDeratedMaxCurrent),
            speed_redline_start_(kTypeCurrentSafeties, obj_idn, kSubSpeedRedlineStart),
            speed_redline_end_(kTypeCurrentSafeties, obj_idn, kSubSpeedRedlineEnd),
            supply_voltage_max_start_(kTypeCurrentSafeties, obj_idn, kSubSupplyVoltageMaxStart),
            supply_voltage_max_end_(kTypeCurrentSafeties, obj_idn, kSubSupplyVoltageMaxEnd),
            motoring_supply_current_limit_enable_(kTypeCurrentSafeties, obj_idn, kSubMotoringSupplyCurrentLimitEnable),
            regen_supply_current_limit_enable_(kTypeCurrentSafeties, obj_idn, kSubRegenSupplyCurrentLimitEnable),
            final_q_current_target_(kTypeCurrentSafeties, obj_idn, kSubFinalQCurrentTarget),
            final_d_current_target_(kTypeCurrentSafeties, obj_idn, kSubFinalDCurrentTarget),
            supply_current_filter_fc_(kTypeCurrentSafeties, obj_idn, kSubSupplyCurrentFilterFc),
            current_slew_rate_limit_(kTypeCurrentSafeties, obj_idn, kSubCurrentSlewRateLimit),
            current_slew_rate_enable_(kTypeCurrentSafeties, obj_idn, kSubCurrentSlewRateEnable),
            motoring_supply_current_limit_(kTypeCurrentSafeties, obj_idn, kSubMotoringSupplyCurrentLimit),
            motoring_supply_current_limit_p_(kTypeCurrentSafeties, obj_idn, kSubMotoringSupplyCurrentLimitP),
            motoring_supply_current_limit_i_(kTypeCurrentSafeties, obj_idn, kSubMotoringSupplyCurrentLimitI),
            motoring_supply_current_limit_d_(kTypeCurrentSafeties, obj_idn, kSubMotoringSupplyCurrentLimitD),
            motoring_supply_current_limit_max_adjust_(kTypeCurrentSafeties, obj_idn, kSubMotoringSupplyCurrentLimitMaxAdjust),
            regen_supply_current_limit_(kTypeCurrentSafeties, obj_idn, kSubRegenSupplyCurrentLimit),
            regen_supply_current_limit_p_(kTypeCurrentSafeties, obj_idn, kSubRegenSupplyCurrentLimitP),
            regen_supply_current_limit_i_(kTypeCurrentSafeties, obj_idn, kSubRegenSupplyCurrentLimitI),
            regen_supply_current_limit_d_(kTypeCurrentSafeties, obj_idn, kSubRegenSupplyCurrentLimitD),
            regen_supply_current_limit_max_adjust_(kTypeCurrentSafeties, obj_idn, kSubRegenSupplyCurrentLimitMaxAdjust)
            {};

    // Client Entries
    ClientEntry<float> final_max_current_derate_;
    ClientEntry<float> base_max_current_;
    ClientEntry<float> derated_max_current_;
    ClientEntry<float> speed_redline_start_;
    ClientEntry<float> speed_redline_end_;
    ClientEntry<float> supply_voltage_max_start_;
    ClientEntry<float> supply_voltage_max_end_;
    ClientEntry<uint8_t> motoring_supply_current_limit_enable_;
    ClientEntry<uint8_t> regen_supply_current_limit_enable_;
    ClientEntry<float> final_q_current_target_;
    ClientEntry<float> final_d_current_target_;
    ClientEntry<uint32_t> supply_current_filter_fc_;
    ClientEntry<float> current_slew_rate_limit_;
    ClientEntry<uint8_t> current_slew_rate_enable_;
    ClientEntry<float> motoring_supply_current_limit_;
    ClientEntry<float> motoring_supply_current_limit_p_;
    ClientEntry<float> motoring_supply_current_limit_i_;
    ClientEntry<float> motoring_supply_current_limit_d_;
    ClientEntry<float> motoring_supply_current_limit_max_adjust_;
    ClientEntry<float> regen_supply_current_limit_;
    ClientEntry<float> regen_supply_current_limit_p_;
    ClientEntry<float> regen_supply_current_limit_i_;
    ClientEntry<float> regen_supply_current_limit_d_;
    ClientEntry<float> regen_supply_current_limit_max_adjust_;
    
    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength = kSubRegenSupplyCurrentLimitMaxAdjust + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &final_max_current_derate_, // 0
            &base_max_current_, // 1
            &derated_max_current_, // 2
            &speed_redline_start_, // 3
            &speed_redline_end_, // 4
            &supply_voltage_max_start_, // 5
            &supply_voltage_max_end_, // 6
            &motoring_supply_current_limit_enable_, // 7
            nullptr, // 8
            nullptr, // 9
            &regen_supply_current_limit_enable_, // 10
            nullptr, // 11
            nullptr, // 12
            &final_q_current_target_, // 13
            &final_d_current_target_, // 14
            &supply_current_filter_fc_, // 15
            &current_slew_rate_limit_, // 16
            &current_slew_rate_enable_, // 17
            &motoring_supply_current_limit_, // 18
            &motoring_supply_current_limit_p_, // 19
            &motoring_supply_current_limit_i_, // 20
            &motoring_supply_current_limit_d_, // 21
            &motoring_supply_current_limit_max_adjust_, // 22
            &regen_supply_current_limit_, // 23
            &regen_supply_current_limit_p_, // 24
            &regen_supply_current_limit_i_, // 25
            &regen_supply_current_limit_d_, // 26
            &regen_supply_current_limit_max_adjust_, // 27
            };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

    private:
    static const uint8_t kSubFinalMaxCurrentDerate = 0;
    static const uint8_t kSubBaseMaxCurrent = 1;
    static const uint8_t kSubDeratedMaxCurrent = 2;
    static const uint8_t kSubSpeedRedlineStart = 3;
    static const uint8_t kSubSpeedRedlineEnd = 4;
    static const uint8_t kSubSupplyVoltageMaxStart = 5;
    static const uint8_t kSubSupplyVoltageMaxEnd = 6;
    static const uint8_t kSubMotoringSupplyCurrentLimitEnable = 7;
    static const uint8_t kSubRegenSupplyCurrentLimitEnable = 10;
    static const uint8_t kSubFinalQCurrentTarget = 13;
    static const uint8_t kSubFinalDCurrentTarget = 14;
    static const uint8_t kSubSupplyCurrentFilterFc = 15;
    static const uint8_t kSubCurrentSlewRateLimit = 16;
    static const uint8_t kSubCurrentSlewRateEnable = 17;
    static const uint8_t kSubMotoringSupplyCurrentLimit = 18;
    static const uint8_t kSubMotoringSupplyCurrentLimitP = 19;
    static const uint8_t kSubMotoringSupplyCurrentLimitI = 20;
    static const uint8_t kSubMotoringSupplyCurrentLimitD = 21;
    static const uint8_t kSubMotoringSupplyCurrentLimitMaxAdjust = 22;
    static const uint8_t kSubRegenSupplyCurrentLimit = 23;
    static const uint8_t kSubRegenSupplyCurrentLimitP = 24;
    static const uint8_t kSubRegenSupplyCurrentLimitI = 25;
    static const uint8_t kSubRegenSupplyCurrentLimitD = 26;
    static const uint8_t kSubRegenSupplyCurrentLimitMaxAdjust = 27;
    
};

#endif /* CURRENT_SAFETIES_CLIENT_HPP_ */