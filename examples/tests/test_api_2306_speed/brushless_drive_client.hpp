/*
  Copyright 2023 Vertiq support@vertiq.co

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: brushless_drive_client.hpp
  Last update: 08/14/2023 by Ben Quan
  Author: Matthew Piccoli
  Contributors: Ben Quan, Raphael Van Hoffelen
*/

#ifndef BRUSHLESS_DRIVE_CLIENT_HPP_
#define BRUSHLESS_DRIVE_CLIENT_HPP_

#include "client_communication.hpp"

const uint8_t kTypeBrushlessDrive = 50;

class BrushlessDriveClient: public ClientAbstract{
  public:
    BrushlessDriveClient(uint8_t obj_idn):
      ClientAbstract(                   kTypeBrushlessDrive, obj_idn),
      drive_mode_(                      kTypeBrushlessDrive, obj_idn, kSubDriveMode),
      drive_phase_pwm_(                 kTypeBrushlessDrive, obj_idn, kSubDrivePhasePwm),
      drive_phase_volts_(               kTypeBrushlessDrive, obj_idn, kSubDrivePhaseVolts),
      drive_spin_pwm_(                  kTypeBrushlessDrive, obj_idn, kSubDriveSpinPwm),
      drive_spin_volts_(                kTypeBrushlessDrive, obj_idn, kSubDriveSpinVolts),
      drive_brake_(                     kTypeBrushlessDrive, obj_idn, kSubDriveBrake),
      drive_coast_(                     kTypeBrushlessDrive, obj_idn, kSubDriveCoast),
      drive_angle_offset_(              kTypeBrushlessDrive, obj_idn, kSubDriveAngleOffset),
      drive_pwm_(                       kTypeBrushlessDrive, obj_idn, kSubDrivePwm),
      drive_volts_(                     kTypeBrushlessDrive, obj_idn, kSubDriveVolts),
      mech_lead_angle_(                 kTypeBrushlessDrive, obj_idn, kSubMechLeadAngle),
      obs_supply_volts_(                kTypeBrushlessDrive, obj_idn, kSubObsSupplyVolts),
      obs_angle_(                       kTypeBrushlessDrive, obj_idn, kSubObsAngle),
      obs_velocity_(                    kTypeBrushlessDrive, obj_idn, kSubObsVelocity),
      motor_pole_pairs_(                kTypeBrushlessDrive, obj_idn, kSubMotorPolePairs),
      motor_emf_shape_(                 kTypeBrushlessDrive, obj_idn, kSubMotorEmfShape),
      permute_wires_(                   kTypeBrushlessDrive, obj_idn, kSubPermuteWires),
      calibration_angle_(               kTypeBrushlessDrive, obj_idn, kSubOCalibrationAngle),
      lead_time_(                       kTypeBrushlessDrive, obj_idn, kSubLeadTime),
      commutation_hz_(                  kTypeBrushlessDrive, obj_idn, kSubCommutationHz),
      phase_angle_(                     kTypeBrushlessDrive, obj_idn, kSubPhaseAngle),
      drive_volts_addition_(            kTypeBrushlessDrive, obj_idn, kSubDriveVoltsAddition),
      angle_adjust_enable_(             kTypeBrushlessDrive, obj_idn, kSubAngleAdjustEnable),
      motor_emf_calc_(                  kTypeBrushlessDrive, obj_idn, kSubMotorEmfCalc),
      angle_adjustment_(                kTypeBrushlessDrive, obj_idn, kSubAngleAdjustment), 
      angle_adjust_max_(                kTypeBrushlessDrive, obj_idn, kSubAngleAdjustMax),   
      angle_adjust_kp_(                 kTypeBrushlessDrive, obj_idn, kSubAngleAdjustKp),    
      angle_adjust_ki_(                 kTypeBrushlessDrive, obj_idn, kSubAngleAdjustKi),    
      v_max_start_(                     kTypeBrushlessDrive, obj_idn, kSubVMaxStart),    
      motor_Kv_(                        kTypeBrushlessDrive, obj_idn, kSubMotorKv),
      motor_R_ohm_(                     kTypeBrushlessDrive, obj_idn, kSubMotorROhm),
      motor_I_max_(                     kTypeBrushlessDrive, obj_idn, kSubMotorIMax),
      volts_limit_(                     kTypeBrushlessDrive, obj_idn, kSubVoltsLimit),
      est_motor_amps_(                  kTypeBrushlessDrive, obj_idn, kSubEstMotorAmps),
      est_motor_torque_(                kTypeBrushlessDrive, obj_idn, kSubEstMotorTorque),
      motor_redline_start_(             kTypeBrushlessDrive, obj_idn, kSubMotorRedlineStart),
      motor_redline_end_(               kTypeBrushlessDrive, obj_idn, kSubMotorRedlineEnd),
      motor_l_(                         kTypeBrushlessDrive, obj_idn, kSubMotorL),
      derate_(                          kTypeBrushlessDrive, obj_idn, kSubDerate),
      motor_i_soft_start_(              kTypeBrushlessDrive, obj_idn, kSubMotorISoftStart),            
      motor_i_soft_end_(                kTypeBrushlessDrive, obj_idn, kSubMotorISoftEnd),             
      emf_(                             kTypeBrushlessDrive, obj_idn, kSubEmf),                       
      volts_at_max_amps_(               kTypeBrushlessDrive, obj_idn, kSubVoltsAtMaxAmps),            
      slew_volts_per_second_(           kTypeBrushlessDrive, obj_idn, kSubSlewVoltsPerSecond),        
      slew_enable_(                     kTypeBrushlessDrive, obj_idn, kSubSlewEnable),                
      motoring_supply_current_limit_(   kTypeBrushlessDrive, obj_idn, kSubMotoringSupplyCurrentLimit),
      regen_supply_current_limit_(      kTypeBrushlessDrive, obj_idn, kSubRegenSupplyCurrentLimit),
      supply_current_limit_enable_(     kTypeBrushlessDrive, obj_idn, kSubSupplyCurrentLimitEnable),
      regen_limiting_(                  kTypeBrushlessDrive, obj_idn, kSubRegenLimiting),             
      regen_limit_adjust_(              kTypeBrushlessDrive, obj_idn, kSubRegenLimitAdjust),          
      motoring_limiting_(               kTypeBrushlessDrive, obj_idn, kSubMotoringLimiting),          
      motoring_limit_adjust_(           kTypeBrushlessDrive, obj_idn, kSubMotoringLimitAdjust),
      regen_limit_kp_(                  kTypeBrushlessDrive, obj_idn, kSubRegenLimitKp),
      regen_limit_ki_(                  kTypeBrushlessDrive, obj_idn, kSubRegenLimitKi),              
      regen_limit_max_(                 kTypeBrushlessDrive, obj_idn, kSubRegenLimitMax),             
      motoring_limit_kp_(               kTypeBrushlessDrive, obj_idn, kSubMotoringLimitKp),
      motoring_limit_ki_(               kTypeBrushlessDrive, obj_idn, kSubMotoringLimitKi),
      motoring_limit_max_(              kTypeBrushlessDrive, obj_idn, kSubMotoringLimitMax)
      {};

    // Client Entries
    ClientEntry<uint8_t>    drive_mode_;
    ClientEntry<float>      drive_phase_pwm_;
    ClientEntry<float>      drive_phase_volts_;
    ClientEntry<float>      drive_spin_pwm_;
    ClientEntry<float>      drive_spin_volts_;
    ClientEntryVoid         drive_brake_;
    ClientEntryVoid         drive_coast_;
    ClientEntry<float>      drive_angle_offset_;
    ClientEntry<float>      drive_pwm_;
    ClientEntry<float>      drive_volts_;
    ClientEntry<float>      mech_lead_angle_;
    ClientEntry<float>      obs_supply_volts_;
    ClientEntry<float>      obs_angle_;
    ClientEntry<float>      obs_velocity_;
    ClientEntry<uint16_t>   motor_pole_pairs_;
    ClientEntry<uint8_t>    motor_emf_shape_;
    ClientEntry<uint8_t>    permute_wires_;
    ClientEntry<float>      calibration_angle_;
    ClientEntry<float>      lead_time_;
    ClientEntry<uint32_t>   commutation_hz_;
    ClientEntry<float>      phase_angle_;
    ClientEntry<float>      drive_volts_addition_;
    ClientEntry<uint8_t>    angle_adjust_enable_; 
    ClientEntry<float>      motor_emf_calc_;      
    ClientEntry<float>      angle_adjustment_;    
    ClientEntry<float>      angle_adjust_max_;    
    ClientEntry<float>      angle_adjust_kp_;     
    ClientEntry<float>      angle_adjust_ki_;        
    ClientEntry<float>      v_max_start_;        
    ClientEntry<float>      motor_Kv_;
    ClientEntry<float>      motor_R_ohm_;
    ClientEntry<float>      motor_I_max_;
    ClientEntry<float>      volts_limit_;
    ClientEntry<float>      est_motor_amps_;
    ClientEntry<float>      est_motor_torque_;
    ClientEntry<float>      motor_redline_start_;
    ClientEntry<float>      motor_redline_end_;
    ClientEntry<float>      motor_l_;
    ClientEntry<int32_t>    derate_;
    ClientEntry<float>      motor_i_soft_start_;
    ClientEntry<float>      motor_i_soft_end_;
    ClientEntry<float>      emf_;
    ClientEntry<float>      volts_at_max_amps_;
    ClientEntry<float>      slew_volts_per_second_;
    ClientEntry<uint8_t>    slew_enable_;
    ClientEntry<float>      motoring_supply_current_limit_;
    ClientEntry<float>      regen_supply_current_limit_;
    ClientEntry<uint8_t>    supply_current_limit_enable_;
    ClientEntry<uint8_t>    regen_limiting_;
    ClientEntry<float>      regen_limit_adjust_;
    ClientEntry<uint8_t>    motoring_limiting_;
    ClientEntry<float>      motoring_limit_adjust_;
    ClientEntry<float>      regen_limit_kp_;
    ClientEntry<float>      regen_limit_ki_;
    ClientEntry<float>      regen_limit_max_;
    ClientEntry<float>      motoring_limit_kp_;
    ClientEntry<float>      motoring_limit_ki_;
    ClientEntry<float>      motoring_limit_max_;


    void ReadMsg(uint8_t* rx_data, uint8_t rx_length)
    {
      static const uint8_t kEntryLength = kSubMotoringLimitMax+1;
      ClientEntryAbstract* entry_array[kEntryLength] = {
        &drive_mode_,                       // 0
        &drive_phase_pwm_,                  // 1
        &drive_phase_volts_,                // 2
        &drive_spin_pwm_,                   // 3
        &drive_spin_volts_,                 // 4
        &drive_brake_,                      // 5
        &drive_coast_,                      // 6
        &drive_angle_offset_,               // 7
        &drive_pwm_,                        // 8
        &drive_volts_,                      // 9
        &mech_lead_angle_,                  // 10
        &obs_supply_volts_,                 // 11
        &obs_angle_,                        // 12
        &obs_velocity_,                     // 13
        &motor_pole_pairs_,                 // 14
        &motor_emf_shape_,                  // 15
        &permute_wires_,                    // 16
        &calibration_angle_,                // 17
        &lead_time_,                        // 18
        &commutation_hz_,                   // 19
        &phase_angle_,                      // 20
        &drive_volts_addition_,             // 21
        &angle_adjust_enable_,              // 22
        &motor_emf_calc_,                   // 23
        &angle_adjustment_,                 // 24
        &angle_adjust_max_,                 // 25
        &angle_adjust_kp_,                  // 26
        &angle_adjust_ki_,                  // 27
        nullptr,                            // 28
        &v_max_start_,                      // 29
        nullptr,                            // 30
        nullptr,                            // 31
        &motor_Kv_,                         // 32
        &motor_R_ohm_,                      // 33
        &motor_I_max_,                      // 34
        &volts_limit_,                      // 35
        &est_motor_amps_,                   // 36
        &est_motor_torque_,                 // 37
        &motor_redline_start_,              // 38
        &motor_redline_end_,                // 39
        &motor_l_,                          // 40
        &derate_,                           // 41
        &motor_i_soft_start_,               // 42 
        &motor_i_soft_end_,                 // 43 
        &emf_,                              // 44 
        &volts_at_max_amps_,                // 45   
        &slew_volts_per_second_,            // 46 
        &slew_enable_,                      // 47 
        &motoring_supply_current_limit_,    // 48
        &regen_supply_current_limit_,       // 49
        &supply_current_limit_enable_,      // 50
        &regen_limiting_,                   // 51
        &regen_limit_adjust_,               // 52
        &motoring_limiting_,                // 53
        &motoring_limit_adjust_,            // 54
        &regen_limit_kp_,                   // 55
        &regen_limit_ki_,                   // 56
        &regen_limit_max_,                  // 57
        &motoring_limit_kp_,                // 58
        &motoring_limit_ki_,                // 59
        &motoring_limit_max_                // 60
      };

      ParseMsg(rx_data, rx_length, entry_array, kEntryLength);
    }

  private:
    static const uint8_t kSubDriveMode                  = 0;
    static const uint8_t kSubDrivePhasePwm              = 1;
    static const uint8_t kSubDrivePhaseVolts            = 2;
    static const uint8_t kSubDriveSpinPwm               = 3;
    static const uint8_t kSubDriveSpinVolts             = 4;
    static const uint8_t kSubDriveBrake                 = 5;
    static const uint8_t kSubDriveCoast                 = 6;
    static const uint8_t kSubDriveAngleOffset           = 7;
    static const uint8_t kSubDrivePwm                   = 8;
    static const uint8_t kSubDriveVolts                 = 9;
    static const uint8_t kSubMechLeadAngle              = 10;
    static const uint8_t kSubObsSupplyVolts             = 11;
    static const uint8_t kSubObsAngle                   = 12;
    static const uint8_t kSubObsVelocity                = 13;
    static const uint8_t kSubMotorPolePairs             = 14;
    static const uint8_t kSubMotorEmfShape              = 15;
    static const uint8_t kSubPermuteWires               = 16;
    static const uint8_t kSubOCalibrationAngle          = 17;
    static const uint8_t kSubLeadTime                   = 18;
    static const uint8_t kSubCommutationHz              = 19;
    static const uint8_t kSubPhaseAngle                 = 20;
    static const uint8_t kSubDriveVoltsAddition         = 21;
    static const uint8_t kSubAngleAdjustEnable          = 22;
    static const uint8_t kSubMotorEmfCalc               = 23;
    static const uint8_t kSubAngleAdjustment            = 24;
    static const uint8_t kSubAngleAdjustMax             = 25;
    static const uint8_t kSubAngleAdjustKp              = 26;
    static const uint8_t kSubAngleAdjustKi              = 27;
    static const uint8_t kSubVMaxStart                  = 29;
    static const uint8_t kSubMotorKv                    = 32;
    static const uint8_t kSubMotorROhm                  = 33;
    static const uint8_t kSubMotorIMax                  = 34;
    static const uint8_t kSubVoltsLimit                 = 35;
    static const uint8_t kSubEstMotorAmps               = 36;
    static const uint8_t kSubEstMotorTorque             = 37;
    static const uint8_t kSubMotorRedlineStart          = 38;
    static const uint8_t kSubMotorRedlineEnd            = 39;
    static const uint8_t kSubMotorL                     = 40;
    static const uint8_t kSubDerate                     = 41;
    static const uint8_t kSubMotorISoftStart            = 42;
    static const uint8_t kSubMotorISoftEnd              = 43;
    static const uint8_t kSubEmf                        = 44;
    static const uint8_t kSubVoltsAtMaxAmps             = 45;
    static const uint8_t kSubSlewVoltsPerSecond         = 46;
    static const uint8_t kSubSlewEnable                 = 47;
    static const uint8_t kSubMotoringSupplyCurrentLimit = 48;
    static const uint8_t kSubRegenSupplyCurrentLimit    = 49;
    static const uint8_t kSubSupplyCurrentLimitEnable   = 50;
    static const uint8_t kSubRegenLimiting              = 51;
    static const uint8_t kSubRegenLimitAdjust           = 52;
    static const uint8_t kSubMotoringLimiting           = 53;
    static const uint8_t kSubMotoringLimitAdjust        = 54;
    static const uint8_t kSubRegenLimitKp               = 55;
    static const uint8_t kSubRegenLimitKi               = 56;
    static const uint8_t kSubRegenLimitMax              = 57;
    static const uint8_t kSubMotoringLimitKp            = 58;
    static const uint8_t kSubMotoringLimitKi            = 59;
    static const uint8_t kSubMotoringLimitMax           = 60;
};

#endif /* BRUSHLESS_DRIVE_CLIENT_HPP_ */
