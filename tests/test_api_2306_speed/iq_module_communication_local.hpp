/*
  Copyright 2023 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: iq_module_communication.hpp
  Last update: 2023/07/14 by Fred Kummer
  Author: Ben Quan, Matthew Piccoli
*/

#include "adc_interface_client.hpp"
#include "anticogging_client.hpp"
#include "anticogging_pro_client.hpp"
#include "arming_handler_client.hpp"
#include "brushless_drive_client.hpp"
#include "buzzer_control_client.hpp"
#include "coil_temperature_estimator_client.hpp"
#include "esc_propeller_input_parser_client.hpp"
#include "gpio_controller_client.hpp"
#include "hobby_input_client.hpp"
#include "iq_serial.hpp"
#include "iquart_flight_controller_interface_client.hpp"
#include "mag_alpha_client.hpp"
#include "multi_turn_angle_control_client.hpp"
#include "persistent_memory_client.hpp"
#include "power_monitor_client.hpp"
#include "power_safety_client.hpp"
#include "propeller_motor_control_client.hpp"
#include "pulsing_rectangular_input_parser_client.hpp"
#include "pwm_interface_client.hpp"
#include "serial_interface_client.hpp"
#include "servo_input_parser_client.hpp"
#include "step_direction_input_client.hpp"
#include "stopping_handler_client.hpp"
#include "stow_user_interface_client.hpp"
#include "system_control_client.hpp"
#include "temperature_estimator_client.hpp"
#include "temperature_monitor_uc_client.hpp"
#include "uavcan_node_client.hpp"
#include "voltage_superposition_client.hpp"
