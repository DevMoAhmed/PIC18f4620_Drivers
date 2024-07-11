/* 
 * File:   motor.h
 * Author: Mohamed Ahmed
 *
 * Created on August 7, 2023, 12:41 PM
 */

#ifndef MOTOR_H
#define	MOTOR_H

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*---------------*/
#define DC_MOTOR_ON_STATUS  0x01U
#define DC_MOTOR_OFF_STATUS 0x00U

#define DC_MOTOR_PIN1 0x00U
#define DC_MOTOR_PIN2 0x01U
/*---------------*/
typedef struct{
    pin_config_t motpin[2];
 }mot;
 
 
 
 Std_ReturnType mot_init(const mot* motr);
 Std_ReturnType mot_R(const mot* motr);
 Std_ReturnType mot_L(const mot* motr);
 Std_ReturnType mot_stop(const mot* motr);

  
   
   
#endif	/* MOTOR_H */

