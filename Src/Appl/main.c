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
#include "Mcal_GPIO.h"
#include "Timer.h"
#include "TM4C123.h"
/**************************************************************************
*LOCAL MACRO CONSTANT\FUNCTION
****************************************************************************/

static unsigned int TimeONFLag = 0x01;
static unsigned int TimeOFF =0x00; 
static unsigned int TimeON=0x00;
/**************************************************************************
*LOCAL DATA
****************************************************************************/
void APP_LED_Blinking(unsigned int Time_on_sec,unsigned int Time_off_sec ); 

void APP_LED_Blinking(unsigned int Time_on_sec,unsigned int Time_off_sec )
{
 
	TimeOFF =Time_off_sec;
	TimeON =Time_on_sec;
	Mcal_GPIO_init(PORT_F, 1,GPIO_PIN_DIR_OUT ,GPIO_PIN_ALTERNATE_FUNC_DIS );
	timerSystick_init(Time_on_sec);
	
}
/**************************************************************************
*GLOBAL DATA
****************************************************************************/

int main(void)
{
	
	APP_LED_Blinking (3,1);
	while(1)
	{
		
	}
	

	return 0;
}

/*void SysTick_Handler(void)
{
	static unsigned int value= 0x00; 
  Mcal_GPIO_blinking_LED(PORT_F, 1,value);
	value=(~value); 
}
*/

void SysTick_Handler(void)
{
	if(TimeONFLag==0)
	{
		Mcal_GPIO_blinking_LED(PORT_F, 1,0);
		timerSystick_init(TimeON); 
		TimeONFLag=1; 
	}
	else
	{
		Mcal_GPIO_blinking_LED(PORT_F, 1,1);
		timerSystick_init(TimeOFF); 
		TimeONFLag=0;
	}
	
}

/* For Future use */
void TIMER0A_Handler(void)
{	
	
}

void TIMER0B_Handler(void)
{
	

}
/**************************************************************************
*LOCAL FUNCTION PROTOTYPES
****************************************************************************/

/**************************************************************************
*LOCAL FUNCTIONS
****************************************************************************/

/**************************************************************************
*GLOBAL FUNCTIONS
****************************************************************************/

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
 
