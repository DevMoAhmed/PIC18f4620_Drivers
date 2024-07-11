/* 
 * File:   mcal_external_interrupt.h
 * Author: Mohamed Ahmed
 * Created on October, 2023
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* Includes */
#include "mcal_interrupt_config.h"

/* Macro Functions Declarations */

#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* Disable interrupt for external interrupt INT0 */
#define EXT_INT0_InterruptDisable()         (INTCONbits.INT0IE = 0)
/* Enable interrupt for external interrupt INT0 */
#define EXT_INT0_InterruptEnable()          (INTCONbits.INT0IE = 1)
/* Clear interrupt flag for external interrupt INT0 */
#define EXT_INT0_InterruptFlagClear()       (INTCONbits.INT0IF = 0)
/* Set edge detection for external interrupt INT0 to rising edge */
#define EXT_INT0_RisingEdgeSet()            (INTCON2bits.INTEDG0 = 1)
/* Set edge detection for external interrupt INT0 to falling edge */
#define EXT_INT0_FallingEdgeSet()           (INTCON2bits.INTEDG0 = 0)

/* Disable interrupt for external interrupt INT1 */
#define EXT_INT1_InterruptDisable()         (INTCON3bits.INT1IE = 0)
/* Enable interrupt for external interrupt INT1 */
#define EXT_INT1_InterruptEnable()          (INTCON3bits.INT1IE = 1)
/* Clear interrupt flag for external interrupt INT1 */
#define EXT_INT1_InterruptFlagClear()       (INTCON3bits.INT1IF = 0)
/* Set edge detection for external interrupt INT1 to rising edge */
#define EXT_INT1_RisingEdgeSet()            (INTCON2bits.INTEDG1 = 1)
/* Set edge detection for external interrupt INT1 to falling edge */
#define EXT_INT1_FallingEdgeSet()           (INTCON2bits.INTEDG1 = 0)

/* Disable interrupt for external interrupt INT2 */
#define EXT_INT2_InterruptDisable()         (INTCON3bits.INT2IE = 0)
/* Enable interrupt for external interrupt INT2 */
#define EXT_INT2_InterruptEnable()          (INTCON3bits.INT2IE = 1)
/* Clear interrupt flag for external interrupt INT2 */
#define EXT_INT2_InterruptFlagClear()       (INTCON3bits.INT2IF = 0)
/* Set edge detection for external interrupt INT2 to rising edge */
#define EXT_INT2_RisingEdgeSet()            (INTCON2bits.INTEDG2 = 1)
/* Set edge detection for external interrupt INT2 to falling edge */
#define EXT_INT2_FallingEdgeSet()           (INTCON2bits.INTEDG2 = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* Set high priority for external interrupt INT1 */
#define EXT_INT1_HighPrioritySet()           (INTCON3bits.INT1IP = 1)
/* Set low priority for external interrupt INT1 */
#define EXT_INT1_LowPrioritySet()            (INTCON3bits.INT1IP = 0)
/* Set high priority for external interrupt INT2 */
#define EXT_INT2_HighPrioritySet()           (INTCON3bits.INT2IP = 1)
/* Set low priority for external interrupt INT2 */
#define EXT_INT2_LowPrioritySet()            (INTCON3bits.INT2IP = 0)
#endif

#endif

#if EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/* Disable interrupt for external interrupt on RBx */
#define EXT_RBx_InterruptDisable()         (INTCONbits.RBIE = 0)
/* Enable interrupt for external interrupt on RBx */
#define EXT_RBx_InterruptEnable()          (INTCONbits.RBIE = 1)
/* Clear interrupt flag for external interrupt on RBx */
#define EXT_RBx_InterruptFlagClear()       (INTCONbits.RBIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/* Set high priority for external interrupt on RBx */
#define EXT_RBx_Priority_High()            (INTCON2bits.RBIP = 1)
/* Set low priority for external interrupt on RBx */
#define EXT_RBx_Priority_Low()             (INTCON2bits.RBIP = 0)
#endif

#endif

/* Data Type Declarations */

typedef void (*InterruptHandler)(void);

typedef enum {
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
} interrupt_INTx_edge;

typedef enum {
    INTERRUPT_EXTERNAL_INT0 =  0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2        
} interrupt_INTx_src;

typedef struct {
    void (*EXT_InterruptHandler)(void);
    pin_config_t mcu_pin;
    interrupt_INTx_edge edge;
    interrupt_INTx_src source;
    interrupt_priority_cfg priority;
} interrupt_INTx_t;

typedef struct {
    void (*EXT_InterruptHandler_HIGH)(void);
    void (*EXT_InterruptHandler_LOW)(void);
    pin_config_t mcu_pin;
    interrupt_priority_cfg priority;
} interrupt_RBx_t;

/* Software Interfaces Declarations */

/**
 * Initialize external interrupt INTx.
 * @param int_obj Pointer to interrupt_INTx_t object.
 * @return Std_ReturnType status.
 */
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj);

/**
 * Deinitialize external interrupt INTx.
 * @param int_obj Pointer to interrupt_INTx_t object.
 * @return Std_ReturnType status.
 */
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj);

/**
 * Initialize external interrupt on RBx.
 * @param int_obj Pointer to interrupt_RBx_t object.
 * @return Std_ReturnType status.
 */
Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_obj);

/**
 * Deinitialize external interrupt on RBx.
 * @param int_obj Pointer to interrupt_RBx_t object.
 * @return Std_ReturnType status.
 */
Std_ReturnType Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */
