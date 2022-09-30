#include "amp_utils.h"

/**
 * @brief Function to start and configure a 1ms Timer0
 * 
 */
void amp_millis_init(void)
{
    timer0_en_write(0);
    timer0_load_write(0);
    timer0_reload_write(0xFFFFFFFF);
    timer0_en_write(1);
    timer0_update_value_write(1);
}

/**
 * @brief Returns the actual value of counter of the timer
 * 
 * @return uint32_t  The counter value of the timer
 */
uint32_t amp_millis(void)
{
    timer0_update_value_write(1);
    return timer0_value_read();
}


/**
 * @brief 
 * 
 * @param data_out 
 * @param data_in 
 * @param len 
 * @param ccr_n 
 * @return int 
 */
int force_ccr_data(uint8_t *data_out, uint8_t *data_in, size_t len, int ccr_n)
{
    // Checking input parameters
    if (data_out == NULL) {
        return -1;
    }
    if (data_in == NULL && len > 0) {
        return -2;
    }
    for (int i = 0; i < ccr_n; i++) {
        int counter = 0;
        do {
            int size_to_receive;
            int bits_left = len - counter;

            if (bits_left > 128) {
                size_to_receive = 128;
            } else {
                size_to_receive = bits_left;
            }
            memcpy((void *) &data_out[counter], (void *) &data_in, size_to_receive);
            counter += size_to_receive;
        } while (counter < len);
    }
    return 0;
}
