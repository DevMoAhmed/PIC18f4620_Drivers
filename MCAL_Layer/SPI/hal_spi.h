/* 
 * File:   hal_spi.h
 * Author: Mohamed Ahmed
 * Created on November, 2023
 */
#ifndef HAL_SPI_H
#define	HAL_SPI_H

/* Includes */
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Macro Declarations */

/* Master Synchronous Serial Port Mode Select */
#define SPI_MASTER_FOSC_DIV4   0 /* SPI Master mode, clock = FOSC/4 */
#define SPI_MASTER_FOSC_DIV16  1 /* SPI Master mode, clock = FOSC/16 */
#define SPI_MASTER_FOSC_DIV64  2 /* SPI Master mode, clock = FOSC/64 */
#define SPI_MASTER_FOSC_TMR2   3 /* SPI Master mode, clock = TMR2 output/2 */
#define SPI_SLAVE_SS_ENABLE    4 /* SPI Slave mode, clock = SCK pin, SS pin control enabled */
#define SPI_SLAVE_SS_DISABLE   5 /* SPI Slave mode, clock = SCK pin, SS pin control disabled */

/* Clock Polarity Select */
#define SPI_IDLE_STATE_HIGH_LEVEL   1 /* Clock idle state is high level */
#define SPI_IDLE_STATE_LOW_LEVEL    0 /* Clock idle state is low level */

/* SPI Sample Select */
#define SPI_DATA_SAMPLE_MIDDLE      0 /* Input data sampled at middle of data output time */
#define SPI_DATA_SAMPLE_END         1 /* Input data sampled at end of data output time */

/* SPI Clock Select */
#define SPI_TRANSMIT_ACTIVE_TO_IDLE 1 /* Transmit occurs on transition from active to idle clock state */
#define SPI_TRANSMIT_IDLE_TO_ACTIVE 0 /* Transmit occurs on transition from idle to active clock state */

/* Receive Overflow Indicator */
#define SPI_SLAVE_RECEIVE_OVERFLOW_DETECTED      1 /* Overflow detected during receive */
#define SPI_SLAVE_RECEIVE_OVERFLOW_NOT_DETECTED  0 /* No overflow detected during receive */

/* Write Collision Detect */
#define SPI_WRITE_COLLISION_DETECTED             1 /* Write collision detected */
#define SPI_WRITE_COLLISION_NOT_DETECTED         0 /* No write collision detected */

/* Buffer Full Status bit (Receive mode only) */ 
#define SPI_BUFFER_FULL_RECEIVE_COMPLETE         1 /* Buffer full with received data */
#define SPI_BUFFER_FULL_RECEIVE_NOT_COMPLETE     0 /* Buffer not full with received data */

/* Macro Functions Declarations */

/* Master Synchronous Serial Port Enable */
#define SPI_ENABLE_MODULE()    (SSPCON1bits.SSPEN = 1) /* Enable SPI module */
#define SPI_DISABLE_MODULE()   (SSPCON1bits.SSPEN = 0) /* Disable SPI module */

/* Data Type Declarations */

typedef struct {
    uint8 ClockPolarity : 2; /* Clock polarity selection */
    uint8 SampleSelect : 2;  /* SPI data sample select */
    uint8 ClockSelect : 2;   /* SPI clock select */
    uint8 Reserved : 2;      /* Reserved bits */
} SPI_Control_Config;

typedef struct {
#if MSSP_SPI_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (*MSSP_SPI_InterruptHandler)(void); /* Pointer to SPI interrupt handler */
    interrupt_priority_cfg priority;         /* Interrupt priority configuration */
#endif
    uint8 spi_mode;          /* SPI mode configuration */
    SPI_Control_Config spi_config; /* SPI control configuration */
} SPI_Config;

/* Software Interfaces Declarations */

Std_ReturnType SPI_Init(const SPI_Config *Config); /* Initialize SPI module */
Std_ReturnType SPI_DeInit(const SPI_Config *Config); /* Deinitialize SPI module */
Std_ReturnType SPI_Send_Byte(const SPI_Config *Config, const uint8 _data); /* Send data via SPI */
Std_ReturnType SPI_Read_Byte(const SPI_Config *Config, uint8 *_data); /* Read data via SPI */
Std_ReturnType SPI_Send_Byte_NonBlocking(const SPI_Config *Config, const uint8 _data); /* Non-blocking send via SPI */
Std_ReturnType SPI_Read_Byte_NonBlocking(const SPI_Config *Config, uint8 *_data); /* Non-blocking read via SPI */

#endif	/* HAL_SPI_H */
