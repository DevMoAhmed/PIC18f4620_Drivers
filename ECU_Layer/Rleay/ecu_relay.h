/* 
 * File:   ecu_relay.h
 * Author: Mohamed Ahmed
 * Created on July, 2023
 */
#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* ----------------- Includes -----------------*/
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* ----------------- Macro Declarations -----------------*/
#define REALY_ON_STATUS  0x01U
#define REALY_OFF_STATUS 0x00U


/* ----------------- Data Type Declarations -----------------*/
typedef struct{
    uint8 relay_port : 4;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
}relay_t;

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType relay_initialize(const relay_t *_relay);
Std_ReturnType relay_turn_on(const relay_t *_relay);
Std_ReturnType relay_turn_off(const relay_t *_relay);

#endif	/* ECU_RELAY_H */

