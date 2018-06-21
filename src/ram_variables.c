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

#include "ram_variables.h"

/* ------------------------------------------------------------------------- */
/* ---                           UI VARIABLES                            --- */
/* ------------------------------------------------------------------------- */

#ifndef UNIT_TEST
ux_state_t ux;
#endif

unsigned int ux_step;
unsigned int ux_step_count;
enum UI_STATE G_ui_state;

unsigned char G_public_key_value[65];

/* ------------------------------------------------------------------------- */
/* ---                     CRYPTOGRAPHY VARIABLES                        --- */
/* ------------------------------------------------------------------------- */

#ifndef UNIT_TEST
/** IO buffer to communicate with the outside world. */
unsigned char G_io_seproxyhal_spi_buffer[IO_SEPROXYHAL_BUFFER_SIZE_B];
#endif

blake2b_state G_blake2b_state;
hycon_hash_t G_tx_hash;
uint8_t G_bip32_path_length;
uint32_t G_bip32_path[MAX_BIP32_PATH];

/* ------------------------------------------------------------------------- */
/* ---                              OTHERS                               --- */
/* ------------------------------------------------------------------------- */

ram G_ram;
