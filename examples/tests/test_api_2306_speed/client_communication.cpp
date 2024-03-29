/*
  Copyright 2019 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: client_communication.cpp
  Last update: 4/12/2019 by Matthew Piccoli
  Author: Matthew Piccoli
  Contributors: Raphael Van Hoffelen
*/

#include "client_communication.hpp"

int8_t ParseMsg(uint8_t* rx_data, uint8_t rx_length,
  ClientEntryAbstract** entry_array, uint8_t entry_length)
{
  uint8_t type_idn = rx_data[0];
  uint8_t sub_idn = rx_data[1];
  uint8_t obj_idn = rx_data[2] >> 2; // high 6 bits are obj_idn
  Access dir = static_cast<Access>(rx_data[2] & 0b00000011); // low two bits

  // if we have a reply (we only parse replies here)
  if(dir == kReply)
  {
    // if sub_idn is within array range (safe to access array at this location)
    if(sub_idn < entry_length)
    {
      // if there is a ClientEntry object at this sub_idn
      if(entry_array[sub_idn] != nullptr)
      {
        // if the type and obj identifiers match
        if(entry_array[sub_idn]->type_idn_ == type_idn &&
        entry_array[sub_idn]->obj_idn_ == obj_idn)
        {
          // ... then we have a valid message
          entry_array[sub_idn]->Reply(&rx_data[3],rx_length-3);
          return 1; // I parsed something
        }
      }
    }
  }
  return 0; // I didn't parse anything
}

int8_t ParseMsg(uint8_t* rx_data, uint8_t rx_length,
  ClientEntryAbstract& entry)
{
  uint8_t type_idn = rx_data[0];
  uint8_t sub_idn = rx_data[1];
  uint8_t obj_idn = rx_data[2] >> 2; // high 6 bits are obj_idn
  Access dir = static_cast<Access>(rx_data[2] & 0b00000011); // low two bits

  // if we have a reply (we only parse replies here)
  if(dir == kReply)
  {
    // if the type and obj identifiers match
    if(entry.type_idn_ == type_idn &&
    entry.obj_idn_ == obj_idn && entry.sub_idn_ == sub_idn)
    {
      // ... then we have a valid message
      entry.Reply(&rx_data[3],rx_length-3);
      return 1; // I parsed something
    }
  }
  return 0; // I didn't parse anything
}