
/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: coil_temperature_estimator_client.hpp
  Last update: 2023/04/12 by Ben Quan
  Author: Ben Quan
  Contributors:
*/

#ifndef COIL_TEMPERATURE_ESTIMATOR_CLIENT_HPP_
#define COIL_TEMPERATURE_ESTIMATOR_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeCoilTemperatureEstimator = 83;

class CoilTemperatureEstimatorClient : public ClientAbstract {
   public:
    CoilTemperatureEstimatorClient(uint8_t obj_idn)
        : ClientAbstract(kTypeCoilTemperatureEstimator, obj_idn),
          t_coil_(kTypeCoilTemperatureEstimator, obj_idn, kSubTCoil),
          t_alu_(kTypeCoilTemperatureEstimator, obj_idn, kSubTAlu),
          t_amb_(kTypeCoilTemperatureEstimator, obj_idn, kSubTAmb),
          h_coil_amb_free_conv_(kTypeCoilTemperatureEstimator, obj_idn, kSubHCoilAmbFreeConv),
          h_coil_stator_cond_(kTypeCoilTemperatureEstimator, obj_idn, kSubHCoilStatorCond),
          h_coil_amb_forced_conv_(kTypeCoilTemperatureEstimator, obj_idn, kSubHCoilAmbForcedConv),
          c_coil_(kTypeCoilTemperatureEstimator, obj_idn, kSubCCoil),
          h_coil_amb_forced_conv_coeff_(kTypeCoilTemperatureEstimator, obj_idn, kSubHCoilAmbForcedConvCoeff),
          otw_(kTypeCoilTemperatureEstimator, obj_idn, kSubOtw),
          otlo_(kTypeCoilTemperatureEstimator, obj_idn, kSubOtlo),
          derate_(kTypeCoilTemperatureEstimator, obj_idn, kSubDerate),
          q_coil_joule_(kTypeCoilTemperatureEstimator, obj_idn, kSubQCoilJoule),
          q_coil_amb_conv_(kTypeCoilTemperatureEstimator, obj_idn, kSubQCoilAmbConv),
          q_coil_stator_cond_(kTypeCoilTemperatureEstimator, obj_idn, kSubQCoilStatorCond),
          h_lam_alu_(kTypeCoilTemperatureEstimator, obj_idn, kSubHLamAlu),
          c_lam_(kTypeCoilTemperatureEstimator, obj_idn, kSubCLam),
          k_lam_hist_coeff_(kTypeCoilTemperatureEstimator, obj_idn, kSubKLamHistCoeff),
          q_lam_hist_(kTypeCoilTemperatureEstimator, obj_idn, kSubQLamHist),
          q_lam_alu_(kTypeCoilTemperatureEstimator, obj_idn, kSubQLamAlu),
          t_lam_(kTypeCoilTemperatureEstimator, obj_idn, kSubTLam){};

    // Client Entries
    ClientEntry<float> t_coil_;
    ClientEntry<float> t_alu_;
    ClientEntry<float> t_amb_;
    ClientEntry<float> h_coil_amb_free_conv_;
    ClientEntry<float> h_coil_stator_cond_;
    ClientEntry<float> h_coil_amb_forced_conv_;
    ClientEntry<float> c_coil_;
    ClientEntry<float> h_coil_amb_forced_conv_coeff_;
    ClientEntry<float> otw_;
    ClientEntry<float> otlo_;
    ClientEntry<float> derate_;
    ClientEntry<float> q_coil_joule_;
    ClientEntry<float> q_coil_amb_conv_;
    ClientEntry<float> q_coil_stator_cond_;
    ClientEntry<float> h_lam_alu_;
    ClientEntry<float> c_lam_;
    ClientEntry<float> k_lam_hist_coeff_;
    ClientEntry<float> q_lam_hist_;
    ClientEntry<float> q_lam_alu_;
    ClientEntry<float> t_lam_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length) {
        static const uint8_t kEntryLength              = kSubTLam + 1;
        ClientEntryAbstract* entry_array[kEntryLength] = {
            &t_coil_,                        // 0
            &t_alu_,                         // 1
            &t_amb_,                         // 2
            &h_coil_amb_free_conv_,          // 3
            &h_coil_stator_cond_,            // 4
            &h_coil_amb_forced_conv_,        // 5
            &c_coil_,                        // 6
            &h_coil_amb_forced_conv_coeff_,  // 7
            &otw_,                           // 8
            &otlo_,                          // 9
            &derate_,                        // 10
            &q_coil_joule_,                  // 11
            &q_coil_amb_conv_,               // 12
            &q_coil_stator_cond_,            // 13
            &h_lam_alu_,                     // 14
            &c_lam_,                         // 15
            &k_lam_hist_coeff_,              // 16
            &q_lam_hist_,                    // 17
            &q_lam_alu_,                     // 18
            &t_lam_                          // 19
        };
        ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

   private:
    static const uint8_t kSubTCoil                   = 0;
    static const uint8_t kSubTAlu                    = 1;
    static const uint8_t kSubTAmb                    = 2;
    static const uint8_t kSubHCoilAmbFreeConv        = 3;
    static const uint8_t kSubHCoilStatorCond         = 4;
    static const uint8_t kSubHCoilAmbForcedConv      = 5;
    static const uint8_t kSubCCoil                   = 6;
    static const uint8_t kSubHCoilAmbForcedConvCoeff = 7;
    static const uint8_t kSubOtw                     = 8;
    static const uint8_t kSubOtlo                    = 9;
    static const uint8_t kSubDerate                  = 10;
    static const uint8_t kSubQCoilJoule              = 11;
    static const uint8_t kSubQCoilAmbConv            = 12;
    static const uint8_t kSubQCoilStatorCond         = 13;
    static const uint8_t kSubHLamAlu                 = 14;
    static const uint8_t kSubCLam                    = 15;
    static const uint8_t kSubKLamHistCoeff           = 16;
    static const uint8_t kSubQLamHist                = 17;
    static const uint8_t kSubQLamAlu                 = 18;
    static const uint8_t kSubTLam                    = 19;
};

#endif /* COIL_TEMPERATURE_ESTIMATOR_CLIENT_HPP_ */