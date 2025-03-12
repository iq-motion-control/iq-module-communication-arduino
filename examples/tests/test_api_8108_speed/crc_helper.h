/*
  Copyright 2019 IQinetics Technologies, Inc support@iq-control.com

  This file is part of the IQ C++ API.

  This code is licensed under the MIT license (see LICENSE or https://opensource.org/licenses/MIT for details)
*/

/*
  Name: crc_helper.h
  Last update: 3/7/2019 by Raphael Van Hoffelen
  Author: James Paulos
  Contributors: Matthew Piccoli, Raphael Van Hoffelen
*/

#ifndef CRC_HELPER_H
#define	CRC_HELPER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Compute CRC word for a byte string.
 */
uint16_t MakeCrc(const uint8_t *data, uint16_t count);

/* Update a CRC accumulation with one data byte.
 */
uint16_t ByteUpdateCrc(uint16_t crc, uint8_t data);

/* Update a CRC accumulation with several data bytes.
 */
uint16_t ArrayUpdateCrc(uint16_t crc, const uint8_t *data, uint16_t count);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif