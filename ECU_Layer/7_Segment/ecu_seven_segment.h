/* 
 * File:   ecu_seven_segment.h
 * Author: Mohamed Ahmed
 * Created on September, 2023
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define ECU_SEVEN_SEGMENT_H

/* Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"  // Include GPIO HAL for pin configurations
#include "ecu_seven_segment_cfg.h"           // Include configuration file for seven-segment

/* Macro Definitions */
#define SEGMENT_PIN0     0   // Pin 0 of the seven-segment display
#define SEGMENT_PIN1     1   // Pin 1 of the seven-segment display
#define SEGMENT_PIN2     2   // Pin 2 of the seven-segment display
#define SEGMENT_PIN3     3   // Pin 3 of the seven-segment display

/* Data Types */

typedef enum {
    SEGMENT_COMMON_ANODE,    // Type: Common anode for the seven-segment display
    SEGMENT_COMMON_CATHODE   // Type: Common cathode for the seven-segment display
} segment_type_t;

typedef struct {
    pin_config_t segment_pins[4];   // Array to store pin configurations for the seven-segment display
    segment_type_t segment_type;    // Type of seven-segment display (common anode/cathode)
} segment_t;

/* Function Declarations */

/**
 * @brief Initializes the seven-segment display.
 * 
 * @param seg Pointer to a segment_t structure containing segment configuration.
 * @return Std_ReturnType indicating success or failure of initialization.
 */
Std_ReturnType seven_segement_intialize(const segment_t *seg);

/**
 * @brief Writes a number to the seven-segment display.
 * 
 * @param seg Pointer to a segment_t structure containing segment configuration.
 * @param number Number (0-9) to display on the seven-segment display.
 * @return Std_ReturnType indicating success or failure of write operation.
 */
Std_ReturnType seven_segement_write_number(const segment_t *seg, uint8 number);

#endif /* ECU_SEVEN_SEGMENT_H */
