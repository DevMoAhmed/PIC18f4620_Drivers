/* 
 * File:   ecu_button.h
 * Author: Mohamed Ahmed
 * Created on August, 2023
 */
#ifndef ECU_BUTTON_H
#define ECU_BUTTON_H

/* Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"  // Include GPIO HAL for pin configurations
#include "ecu_button_cfg.h"                  // Include configuration file for buttons

/* Macro Declarations */
// No macros declared in this header file

/* Data Type Declarations */

typedef enum {
    BUTTON_PRESSED = 0,     // Button state: pressed
    BUTTON_RELEASED         // Button state: released
} button_state_t;

typedef enum {
    BUTTON_ACTIVE_HIGH,     // Button active state: active high
    BUTTON_ACTIVE_LOW       // Button active state: active low
} button_active_t;

typedef struct {
    pin_config_t button_pin;        // Pin configuration for the button
    button_state_t button_state;    // Current state of the button
    button_active_t button_connection;  // Connection type of the button (active high/low)
} button_t;

/* Function Declarations */

/**
 * @brief Initializes the button pin as an input.
 * 
 * @param btn Pointer to a button_t structure containing button configuration.
 * @return Std_ReturnType indicating success or failure of initialization.
 */
Std_ReturnType button_initialize(const button_t *btn);

/**
 * @brief Reads the state of the button.
 * 
 * @param btn Pointer to a button_t structure containing button configuration.
 * @param btn_state Pointer to store the button state (pressed/released).
 * @return Std_ReturnType indicating success or failure of read operation.
 */
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state);

#endif /* ECU_BUTTON_H */
