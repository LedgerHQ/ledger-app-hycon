/******************************************************************************
*   HYCON Wallet for Ledger Nano S
*   (c) 2018 Dulguun Batmunkh
*   (c) 2018 Hycon
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
******************************************************************************/

#ifndef HYCON_API_H
#define HYCON_API_H

#include "hycon_types.h"

#ifdef UNIT_TEST
#define os_memmove memmove
#define os_memcpy memcpy
#define os_memset memset
#endif	// UNIT_TEST

/* ------------------------------------------------------------------------- */
/* ---                            APDU functions                         --- */
/* ------------------------------------------------------------------------- */

#ifndef UNIT_TEST
void handle_apdu(volatile unsigned int *flags, volatile unsigned int *tx);
void handle_sign(uint8_t p1, uint8_t p2, uint8_t *data_buffer,
                uint8_t data_length, volatile unsigned int *flags,
                volatile unsigned int *tx);
void handle_get_public_key(uint8_t p1, uint8_t p2, uint8_t *data_buffer,
                        uint8_t data_length, volatile unsigned int *flags,
                        volatile unsigned int *tx);
void handle_get_app_config(uint8_t p1, uint8_t p2, uint8_t *data_buffer,
                        uint8_t data_length, volatile unsigned int *flags,
                        volatile unsigned int *tx);
#endif	// UNIT_TEST

/* ------------------------------------------------------------------------- */
/* ---                            Cryptography                           --- */
/* ------------------------------------------------------------------------- */

void get_compressed_public_key_value(const unsigned char *in, unsigned char *out);

#ifndef UNIT_TEST
void get_address_string_from_key(const cx_ecfp_public_key_t publicKey,
                                 uint8_t *out);
uint32_t set_result_public_key();
#endif	// UNIT_TEST

/* ------------------------------------------------------------------------- */
/* ---                            Others                                 --- */
/* ------------------------------------------------------------------------- */

bool decode_tx(const uint8_t *data, uint8_t data_len, hycon_tx *tx_content);
uint8_t bin_addr_to_hycon_address(const uint8_t addr[21], char* out);
void coin_amount_to_displayable_chars(uint64_t number, char *out);

uint64_t decode_varint(const uint8_t *buf, uint8_t *skip_bytes, uint8_t max_len);
uint8_t base58_encode(char *out, const void *data, uint8_t data_len);
uint8_t check_sum(char *out, const void *data, uint8_t data_len);
uint8_t min(uint8_t a, uint8_t b);

#endif 	// HYCON_API_H
