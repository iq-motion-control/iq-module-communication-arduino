/*
  Copyright 2019 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  IQ C++ API is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  IQ C++ API is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/*
  Name: iq_serial.hpp
  Last update: 4/12/2019 by Matthew Piccoli
  Author: Matthew Piccoli
*/

#include "client_communication.hpp"
#include "generic_interface.hpp"
#include "HardwareSerial.h"

class IqSerial{
  public:
    IqSerial(HardwareSerial &my_serial)
    {
      my_serial_ = &my_serial;
    }
    
    void begin(unsigned long baud)
    {
      my_serial_->begin(baud);
    }
    
    void begin()
    {
      begin(115200);
    }
    
    void set(ClientEntryVoid entry)
    {
      entry.set(com_);
      sendBytes();
    }
    
    template <typename T>
    void set(ClientEntry<T>& entry, T value)
    {
      entry.set(com_,value);
      sendBytes();
    }
    
    template <typename T>
    bool get(ClientEntry<T>& entry, T& value)
    {
      entry.get(com_);
      sendBytes();
      
      unsigned long start_time = millis();
      while((millis() < start_time + 10) && !getBytes(entry))
      {}
        
      if(entry.IsFresh())
      {
        value = entry.get_reply();
        return true;
      }
      return false;
    }
    
    template <typename T>
    void save(ClientEntry<T>& entry)
    {
      entry.save(com_);
      sendBytes();
    }
    
  private:
    GenericInterface com_;
    HardwareSerial* my_serial_;
    
    // This buffer is for passing around messages.
    uint8_t communication_buffer[64];
    // Stores length of message to send or receive
    uint8_t communication_length;
    
    void sendBytes()
    {
      // Grab outbound messages in the com queue, store into buffer
      // If it transferred something to communication_buffer...
      if(com_.GetTxBytes(communication_buffer,communication_length))
      {
        // Use Arduino serial hardware to send messages
        my_serial_->write(communication_buffer,communication_length);
      }
    } 

    int8_t getBytes(ClientEntryAbstract& entry)
    {
      int8_t ret = 0;
      
      // Reads however many bytes are currently available
      communication_length = my_serial_->readBytes(communication_buffer, my_serial_->available());
      
      // Puts the recently read bytes into com’s receive queue
      com_.SetRxBytes(communication_buffer,communication_length);
      uint8_t *rx_data; // temporary pointer to received type+data bytes
      uint8_t rx_length; // number of received type+data bytes
      // if we have a message packet to parse
      if(com_.PeekPacket(&rx_data,&rx_length))
      {
        ret = ParseMsg(rx_data,rx_length, entry);
        // Once we’re done with the message packet, drop it
        com_.DropPacket();
      }
      return ret;
    }
};