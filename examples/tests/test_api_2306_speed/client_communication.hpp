/*
  Copyright 2019 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: client_communication.hpp
  Last update: 4/12/2019 by Matthew Piccoli
  Author: Matthew Piccoli
  Contributors: Raphael Van Hoffelen
*/

#ifndef CLIENT_COMMUNICATION_H
#define CLIENT_COMMUNICATION_H

#include <string.h> // for memcpy
#include "communication_interface.h"

enum Access {kGet=0, kSet=1, kSave=2, kReply=3};

class ClientEntryAbstract {
  public:
    ClientEntryAbstract(uint8_t type_idn, uint8_t obj_idn, uint8_t sub_idn):
      type_idn_(type_idn),
      obj_idn_(obj_idn),
      sub_idn_(sub_idn) {};

    virtual ~ClientEntryAbstract(){};

    virtual void Reply(const uint8_t* data, uint8_t len) = 0;

    const uint8_t type_idn_;
    const uint8_t obj_idn_;
    const uint8_t sub_idn_;
};

class ClientEntryVoid: public ClientEntryAbstract {
  public:
    ClientEntryVoid(uint8_t type_idn, uint8_t obj_idn, uint8_t sub_idn):
      ClientEntryAbstract(type_idn, obj_idn, sub_idn),
      is_fresh_(false)
      {};

    void get(CommunicationInterface &com) {
      uint8_t tx_msg[2];
      tx_msg[0] = sub_idn_;
      tx_msg[1] = (obj_idn_<<2) | kGet; // high six | low two
      com.SendPacket(type_idn_, tx_msg, 2);
    };

    void set(CommunicationInterface &com) {
      uint8_t tx_msg[2]; // must fit outgoing message
      tx_msg[0] = sub_idn_;
      tx_msg[1] = (obj_idn_<<2) | kSet; // high six | low two
      com.SendPacket(type_idn_, tx_msg, 2);
    }

    void save(CommunicationInterface &com) {
      uint8_t tx_msg[2];
      tx_msg[0] = sub_idn_;
      tx_msg[1] = (obj_idn_<<2) | kSave; // high six | low two
      com.SendPacket(type_idn_, tx_msg, 2);
    }

    void Reply(const uint8_t* data, uint8_t len) {
      (void)data;
      if(len == 0) {
        is_fresh_ = true;
      }
    };

    bool IsFresh() {return is_fresh_;};

  private:
    bool is_fresh_;
};

template <typename T>
class ClientEntry: public ClientEntryAbstract {
  public:
    ClientEntry(uint8_t type_idn, uint8_t obj_idn, uint8_t sub_idn):
      ClientEntryAbstract(type_idn, obj_idn, sub_idn),
      is_fresh_(false),
      value_()
      {};

    void get(CommunicationInterface &com) {
      uint8_t tx_msg[2];
      tx_msg[0] = sub_idn_;
      tx_msg[1] = (obj_idn_<<2) | kGet; // high six | low two
      com.SendPacket(type_idn_, tx_msg, 2);
    };

    void set(CommunicationInterface &com, T value) {
      uint8_t tx_msg[2+sizeof(T)]; // must fit outgoing message
      tx_msg[0] = sub_idn_;
      tx_msg[1] = (obj_idn_<<2) | kSet; // high six | low two
      memcpy(&tx_msg[2], &value, sizeof(T));
      com.SendPacket(type_idn_, tx_msg, 2+sizeof(T));
    }

    void save(CommunicationInterface &com) {
      uint8_t tx_msg[2];
      tx_msg[0] = sub_idn_;
      tx_msg[1] = (obj_idn_<<2) | kSave; // high six | low two
      com.SendPacket(type_idn_, tx_msg, 2);
    }

    void Reply(const uint8_t* data, uint8_t len) {
      if(len == sizeof(T)) {
        memcpy(&value_, data, sizeof(T));
        is_fresh_ = true;
      }
    };

    T get_reply() {
      is_fresh_ = false;
      return value_;
    };

    bool IsFresh() {return is_fresh_;};

  private:
    bool is_fresh_;
    T value_;
};

class ClientAbstract{
  public:
    ClientAbstract(uint8_t type_idn, uint8_t obj_idn):
      type_idn_(type_idn),
      obj_idn_(obj_idn) {};

    virtual ~ClientAbstract(){};

    virtual void ReadMsg(uint8_t* rx_data, uint8_t rx_length) = 0;

    const uint8_t type_idn_;
    const uint8_t obj_idn_;
};

int8_t ParseMsg(uint8_t* rx_data, uint8_t rx_length,
  ClientEntryAbstract** entry_array, uint8_t entry_length);

int8_t ParseMsg(uint8_t* rx_data, uint8_t rx_length,
  ClientEntryAbstract& entry);

#endif // CLIENT_COMMUNICATION_H
