/* 
 * File:   ecu_keypad.h
 * Author: Mohamed Ahmed
 * Created on October, 2023
 */

#ifndef ECU_KEYPAD_H
#define ECU_KEYPAD_H

/* Includes */
#include "ecu_keypad_cfg.h"         // Include configuration file for keypad
#include "../../MCAL_Layer/GPIO/hal_gpio.h"  // Include GPIO HAL for pin configurations

/* Macro Declarations */
#define ECU_KEYPAD_ROWS     4
#define ECU_KEYPAD_COLUMNS  4

/* Data Type Declarations */
typedef struct {
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROWS];       // Array of row pin configurations for keypad
    pin_config_t keypad_columns_pins[ECU_KEYPAD_COLUMNS]; // Array of column pin configurations for keypad
} keypad_t;

/* Software Interfaces Declarations */
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value);

#endif /* ECU_KEYPAD_H */
