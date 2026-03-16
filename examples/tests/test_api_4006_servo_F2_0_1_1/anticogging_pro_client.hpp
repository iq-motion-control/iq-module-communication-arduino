/*
  Copyright 2023 Vertiq support@vertiq.co

  This file is part of the Vertiq C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: anticogging_pro_client.hpp
  Last update: 2023/06/29 by Ben Quan 
  Author: Ben Quan 
  Contributors: 
*/

#ifndef ANTICOGGING_PRO_CLIENT_HPP
#define ANTICOGGING_PRO_CLIENT_HPP

#include "client_communication.hpp"

const uint8_t kTypeAnticoggingPro = 79;

class AnticoggingProClient: public ClientAbstract{
  public:
    AnticoggingProClient(uint8_t obj_idn):
      ClientAbstract( kTypeAnticoggingPro, obj_idn),
      enabled_(kTypeAnticoggingPro, obj_idn, kSubEnabled),
      tau_(kTypeAnticoggingPro, obj_idn, kSubTau),
      num_harmonics_(kTypeAnticoggingPro, obj_idn, kSubNumHarmonics),
      voltage_(kTypeAnticoggingPro, obj_idn, kSubVoltage),
      index_(kTypeAnticoggingPro, obj_idn, kSubIndex),
      harmonic_(kTypeAnticoggingPro, obj_idn, kSubHarmonic),
      a_(kTypeAnticoggingPro, obj_idn, kSubA),
      phase_(kTypeAnticoggingPro, obj_idn, kSubPhase),
      phase_total_(kTypeAnticoggingPro, obj_idn, kSubPhaseTotal),
      amplitude_(kTypeAnticoggingPro, obj_idn, kSubAmplitude),
      max_harmonics_(kTypeAnticoggingPro, obj_idn, kSubMaxHarmonics)
      {};

    // Client Entries
    ClientEntry<uint8_t>  enabled_;      
    ClientEntry<float>    tau_;          
    ClientEntry<uint8_t>  num_harmonics_;
    ClientEntry<float>    voltage_;      
    ClientEntry<uint8_t>  index_;        
    ClientEntry<uint8_t>  harmonic_;     
    ClientEntry<float>    a_;            
    ClientEntry<float>    phase_;        
    ClientEntry<float>    phase_total_;  
    ClientEntry<float>    amplitude_;    
    ClientEntry<uint8_t>  max_harmonics_;

    void ReadMsg(uint8_t* rx_data, uint8_t rx_length)
    {
      static const uint8_t kEntryLength = kSubMaxHarmonics+1;
      ClientEntryAbstract* entry_array[kEntryLength] = {
        &enabled_,           // 0
        &tau_,               // 1
        &num_harmonics_,     // 2
        &voltage_,           // 3
        &index_,             // 4
        &harmonic_,          // 5
        &a_,                 // 6
        &phase_,             // 7
        &phase_total_,       // 8
        &amplitude_,         // 9
        &max_harmonics_      // 10
      };

      ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

  private:
    static const uint8_t kSubEnabled       = 0;
    static const uint8_t kSubTau           = 1;
    static const uint8_t kSubNumHarmonics  = 2;
    static const uint8_t kSubVoltage       = 3;
    static const uint8_t kSubIndex         = 4;
    static const uint8_t kSubHarmonic      = 5;
    static const uint8_t kSubA             = 6;
    static const uint8_t kSubPhase         = 7;
    static const uint8_t kSubPhaseTotal    = 8;
    static const uint8_t kSubAmplitude     = 9;
    static const uint8_t kSubMaxHarmonics  = 10;
};

#endif // ANTICOGGING_PRO_CLIENT_H
