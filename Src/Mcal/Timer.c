/**************************************************************************
*FILE DESCRIPTION
*  -----------------------------------------------------------------------*/
/**   \file FileName
*     \brief
*
*     \details
*
*
****************************************************************************/


/***************************************************************************
* INCLUDES
****************************************************************************/
#include "Timer.h"


/**************************************************************************
*LOCAL MACRO CONSTANT\FUNCTION
****************************************************************************/


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
void timerSystick_init(unsigned int time_sec)
{
	unsigned int* Systick_Ctrl_Add = (unsigned int*)(TIMER_SYSTICK_STCTRL_ADDRESS + TIMER_SYSTICK_STCTRL_OFFSET);
	unsigned int* Systick_Load_Add = (unsigned int*)(TIMER_SYSTICK_STRELOAD_ADDRESS+ TIMER_SYSTICK_STRELOAD_OFFSET);
	unsigned int* Systick_STCURRENT_Add = (unsigned int*)(TIMER_SYSTICK_STCURRENT_ADDRESS+ TIMER_SYSTICK_STCURRENT_OFFSET);

	unsigned int countsNo=0x00U;
	
	*Systick_Load_Add=*Systick_Load_Add &0x00UL;
	*Systick_STCURRENT_Add=  *Systick_STCURRENT_Add & 0xFF000000U; 
	*Systick_Ctrl_Add=*Systick_Ctrl_Add& 0x00U; 
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
	*Systick_Ctrl_Add=0x03; 
	
  //1000,000 Microseconds/0.25=4000000 ==> ctrl=0x03 clk 
	countsNo=4000000*time_sec;
	
	*Systick_Load_Add=countsNo-1 ; //1sec
	
}

/* the following functions are fOr future use, not completed yet. to be continued if needed in the comming projects*/

void timer0_init(unsigned int time_usec)
{
	unsigned int* Timer_RCGCTIMER_address = (unsigned int*)(TIMER_RCGCTIMER_ADDRESS+TIMER_RCGCTIMER_OFFSET);
  unsigned int* Timer_GPTMCTL_address   = (unsigned int*)(TIMER_GPTMCTL0_ADDRESS+TIMER_GPTMCTL_OFFSET);
	unsigned int* Timer_GPTMCFG_address   = (unsigned int*)(TIMER_GPTMCTL0_ADDRESS+TIMER_GPTMCFG_OFFSET); 
	unsigned int* Timer_GPTMTAMR_address = (unsigned int*)(TIMER_GPTMCTL0_ADDRESS+TIMER_GPTMTAMR_OFFSET); 
	unsigned int* Timer_GPTMTAILR_address = (unsigned int*)(TIMER_GPTMCTL0_ADDRESS+TIMER_GPTMTAILR_OFFSET); 
	//unsigned int* Timer_GPTMRIS_address = (unsigned int*)(TIMER_GPTMCTL0_ADDRESS+TIMER_GPTMRIS_OFFSET); 
	//unsigned int* Timer_GPTMICR_address = (unsigned int*)(TIMER_GPTMCTL0_ADDRESS+TIMER_GPTMICR_OFFSET); 
	
	
	*Timer_RCGCTIMER_address = (*Timer_RCGCTIMER_address ) | 0x01U; 
	*Timer_GPTMCTL_address  =  (* Timer_GPTMCTL_address) & (~(1<<0)); 
	*Timer_GPTMCFG_address = 0x00U; 
	*Timer_RCGCTIMER_address = *Timer_RCGCTIMER_address | (0x02);
	*Timer_GPTMTAILR_address = 0xFFFFF;
	*Timer_GPTMCTL_address   =  (* Timer_GPTMCTL_address) | (1<<0); 

	/*if((*Timer_GPTMRIS_address  & 0x00000001)==1)
	{
		*Timer_GPTMICR_address = *Timer_GPTMICR_address | (1<<0) ; 
	}*/
}

void timer1_init(unsigned int time_usec)
{
	unsigned int* Timer_RCGCTIMER_address = (unsigned int*)(TIMER_RCGCTIMER_ADDRESS+TIMER_RCGCTIMER_OFFSET); 
	unsigned int* Timer_GPTMCTL_address   = (unsigned int*)(TIMER_GPTMCTL1_ADDRESS+TIMER_GPTMCTL_OFFSET);
  unsigned int* Timer_GPTMCFG_address   = (unsigned int*)(TIMER_GPTMCTL1_ADDRESS+TIMER_GPTMCFG_OFFSET);
	unsigned int* Timer_GPTMTAMR_address   = (unsigned int*)(TIMER_GPTMCTL1_ADDRESS+TIMER_GPTMTAMR_OFFSET); 
	
	*Timer_RCGCTIMER_address = (*Timer_RCGCTIMER_address ) | 0x01U; 
	*Timer_GPTMCTL_address  =  (* Timer_GPTMCTL_address) & (~(1<<1)); 
	*Timer_GPTMCFG_address =0x00U; 
	*Timer_RCGCTIMER_address= *Timer_RCGCTIMER_address | (0x02);
}

void timer2_init(unsigned int time_usec)
{
	unsigned int* Timer_RCGCTIMER_address = (unsigned int*)(TIMER_RCGCTIMER_ADDRESS+TIMER_RCGCTIMER_OFFSET); 
	unsigned int* Timer_GPTMCTL_address   = (unsigned int*)(TIMER_GPTMCTL2_ADDRESS+TIMER_GPTMCTL_OFFSET); 
	unsigned int* Timer_GPTMCFG_address   = (unsigned int*)(TIMER_GPTMCTL2_ADDRESS+TIMER_GPTMCFG_OFFSET);
	unsigned int* Timer_GPTMTAMR_address   = (unsigned int*)(TIMER_GPTMCTL2_ADDRESS+TIMER_GPTMTAMR_OFFSET); 
	
	
	*Timer_RCGCTIMER_address = (*Timer_RCGCTIMER_address ) | 0x02U; 
	*Timer_GPTMCTL_address  =  (* Timer_GPTMCTL_address) & (~(1<<2));
	*Timer_GPTMCFG_address =0x00U; 	
	*Timer_RCGCTIMER_address= *Timer_RCGCTIMER_address | (0x02);
}

void timer3_init(unsigned int time_usec)
{
	unsigned int* Timer_GPTMCTL_address   = (unsigned int*)(TIMER_GPTMCTL3_ADDRESS+TIMER_GPTMCTL_OFFSET); 
	unsigned int* Timer_RCGCTIMER_address = (unsigned int*)(TIMER_RCGCTIMER_ADDRESS+TIMER_RCGCTIMER_OFFSET); 
	unsigned int* Timer_GPTMCFG_address   = (unsigned int*)(TIMER_GPTMCTL3_ADDRESS+TIMER_GPTMCFG_OFFSET);
	unsigned int* Timer_GPTMTAMR_address   = (unsigned int*)(TIMER_GPTMCTL3_ADDRESS+TIMER_GPTMTAMR_OFFSET); 
		unsigned int* Timer_GPTMRIS_address = (unsigned int*)(TIMER_GPTMCTL0_ADDRESS+TIMER_GPTMRIS_OFFSET); 
	unsigned int* Timer_GPTMICR_address = (unsigned int*)(TIMER_GPTMCTL0_ADDRESS+TIMER_GPTMICR_OFFSET); 

	
	*Timer_RCGCTIMER_address = (*Timer_RCGCTIMER_address ) | 0x04U; 
	*Timer_GPTMCTL_address  =  (* Timer_GPTMCTL_address) & (~(1<<3)); 
	*Timer_GPTMCFG_address =0x00U;
  *Timer_RCGCTIMER_address= *Timer_RCGCTIMER_address | (0x02);	
	
	if((*Timer_GPTMRIS_address  & 0x00000001)==1)
	{
		*Timer_GPTMICR_address = *Timer_GPTMICR_address | (1<<0) ; 
	}
	
}

void timer4_init(unsigned int time_usec)
{
	unsigned int* Timer_RCGCTIMER_address = (unsigned int*)(TIMER_RCGCTIMER_ADDRESS+TIMER_RCGCTIMER_OFFSET); 
	unsigned int* Timer_GPTMCTL_address   = (unsigned int*)(TIMER_GPTMCTL4_ADDRESS+TIMER_GPTMCTL_OFFSET);
	unsigned int* Timer_GPTMCFG_address   = (unsigned int*)(TIMER_GPTMCTL4_ADDRESS+TIMER_GPTMCFG_OFFSET);
	unsigned int* Timer_GPTMTAMR_address   = (unsigned int*)(TIMER_GPTMCTL4_ADDRESS+TIMER_GPTMTAMR_OFFSET); 
	
	
	*Timer_RCGCTIMER_address = (*Timer_RCGCTIMER_address ) | 0x08U; 
	*Timer_GPTMCTL_address  =  (* Timer_GPTMCTL_address) & (~(1<<4));
	*Timer_GPTMCFG_address =0x00U; 
	*Timer_RCGCTIMER_address= *Timer_RCGCTIMER_address | (0x02);
	
}


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




/*****************************************************************************
* END of FILE
******************************************************************************/
 
