/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcal_GPIO.h
 *       Module:  MCAL_GPIO
 *
 *  Description:  GPIO driver
 *  
 *********************************************************************************************************************/
#ifndef MCAL_TIMER
#define MCAL_TIMER

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*
configure 4MHZ systick timer 
register: STCTRL offset 0x010
bit 0==> enable systick counter
bit 1==> enable interrupt for the timer
bit 2==>CLK_SRC [0==> internal osc divided by 4, 1 system clock]
SysTick->CTRL
SysTick Reload Value Register (STRELOAD)
Base 0xE000.E000
Offset 0x014
*/

#define TIMER_SYSTICK_STCTRL_ADDRESS 0xE000E000U 
#define TIMER_SYSTICK_STCTRL_OFFSET  0x010U

#define TIMER_SYSTICK_STRELOAD_ADDRESS 0xE000E000U
#define TIMER_SYSTICK_STRELOAD_OFFSET  0x014U

#define TIMER_SYSTICK_STCURRENT_ADDRESS 0xE000E000U
#define TIMER_SYSTICK_STCURRENT_OFFSET  0x018U



/* Configurations for GPT timers for future use*/
// initialize & configure to use GPTM, the appropriate bit must be set
//RCGCTIMER, Base 0x400F.E000, Offset 0x604
//1Enable and provide a clock to 16/32-bit general-purpose timer
//module 1 in Run mode.
#define TIMER_RCGCTIMER_ADDRESS  0x400FE000U
#define TIMER_RCGCTIMER_OFFSET   0x604U


//GPTMCTL
//GPTM Control (GPTMCTL)

#define TIMER_GPTMCTL0_ADDRESS  0x40030000U
#define TIMER_GPTMCTL1_ADDRESS  0x40031000U
#define TIMER_GPTMCTL2_ADDRESS  0x40032000U
#define TIMER_GPTMCTL3_ADDRESS  0x40033000U
#define TIMER_GPTMCTL4_ADDRESS  0x40034000U
#define TIMER_GPTMCTL5_ADDRESS  0x40035000U

/*GPTM Control*/
#define TIMER_GPTMCTL_OFFSET     0x00CU

/* GPTM Configuration*/
#define TIMER_GPTMCFG_OFFSET     0x00U

/* GPTM Timer A Mode*/
#define TIMER_GPTMTAMR_OFFSET    0x004U

/*GPTM Timer A Interval Load*/
#define TIMER_GPTMTAILR_OFFSET   0x028U

/*GPTM Timer B Interval Load*/
#define TIMER_GPTMTBILR_OFFSET   0x02CU

/* GPTM Raw Interrupt Status*/
#define TIMER_GPTMRIS_OFFSET     0x01CU

/* GPTM Interrupt Clear*/
#define TIMER_GPTMICR_OFFSET     0x024U

#define TIMER_GPTMCFG0_ADDRESS  0x40030000U

/**************************************************************************
*LOCAL DATA
****************************************************************************/

/**************************************************************************
*GLOBAL DATA
****************************************************************************/

/**************************************************************************
*LOCAL FUNCTION PROTOTYPES
****************************************************************************/

/**************************************************************************
*LOCAL FUNCTIONS
****************************************************************************/

/**************************************************************************
*GLOBAL FUNCTIONS
****************************************************************************/
void timerSystick_init(unsigned int time_sec);


/* the following functions are fOr future use, not completed yet. to be continued if needed in the comming projects*/
void timer0_init(unsigned int time_usec);
void timer1_init(unsigned int time_usec);
void timer2_init(unsigned int time_usec);
void timer3_init(unsigned int time_usec);
void timer4_init(unsigned int time_usec);

/***************************************************************************
* \Syntax          : std_ReturnType FUnction
* \Description     :
*
*\Sync\Async       :
*\Reentrancy       :
*\Parameters (in)  :
*\Parameters (Out) :
*\Retrurn Value    :
* 
*****************************************************************************/



#endif
/*****************************************************************************
* END of FILE
******************************************************************************/
 
