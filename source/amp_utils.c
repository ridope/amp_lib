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
 * @brief Function to perform multiple reads in a given memory address
 * 
 * @param data_in   The pointr to the data that will be read
 * @param len       Size to be read
 * @param ccr_n     How many times to perform the read
 * @return int      Returns < 0 if an error ocurred, 0 if success
 */
int force_ccr_read_data(uint8_t *data_in, size_t len, int ccr_n)
{
    // Checking input parameters

    if (data_in == NULL && len > 0) {
        return -1;
    }
    
    volatile uint8_t temp;

    for (int i = 0; i < ccr_n; i++) {
        for(int j = 0; j < len; j++){
            temp = data_in[j];
        } 
    }
    
    return 0;
}

/**
 * @brief Function to perform multiple writes in a given memory address
 * 
 * @param data_in   The pointr to the data that will be written
 * @param len       Size to be written
 * @param ccr_n     How many times to perform the write
 * @return int      Returns < 0 if an error ocurred, 0 if success
 */
int force_ccr_write_data(uint8_t *data_in, size_t len, int ccr_n)
{
    // Checking input parameters

    if (data_in == NULL && len > 0) {
        return -1;
    }

    uint8_t * data_temp = malloc(len);
    
    if(data_temp == NULL)
    {
        return -2;
    }

    /* Copying data */
    for(int j = 0; j < len; j++){
        data_temp[j] = data_in[j];
    } 

    /* Performing ccr write */
    for (int i = 0; i < ccr_n; i++) {
        for(int j = 0; j < len; j++){
            data_in[j] = data_temp[j];
        } 
    }
    
    return 0;

}
