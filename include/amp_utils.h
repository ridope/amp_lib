/** @file amp_utils.h
 *  @brief Header file with utility fuctions for the AMP cores
 *
 *  @author Lucas Esteves <lucas.esteves-rocha@insa-rennes.fr>
 */

#ifndef AMP_UTILS_H
#define AMP_UTILS_H

#include <generated/csr.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void amp_millis_init(void);
uint32_t amp_millis(void);
int force_ccr_read_data(uint8_t *data_in, size_t len, int ccr_n);
int force_ccr_write_data(uint8_t *data_in, size_t len, int ccr_n);

#endif