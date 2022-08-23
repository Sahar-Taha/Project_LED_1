/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
*********************************************************************************************************************/

#include "Mcal_GPIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

unsigned int Mcal_GPIO_init(unsigned int port, unsigned int pin, unsigned int dir, unsigned int pin_alternate_func)
{

	unsigned int* GPIO_Dir_address = 0x00;
	unsigned int* GPIO_DEN_address = 0x00;
	unsigned int* GPIO_clock_enable_address= (unsigned int* )(RCGCGPIO_ADDRESS+RCGCGPIO_OFFSET);

	
	switch(port)
	{
		case PORT_A:
			GPIO_Dir_address =(unsigned int* )(GPIODATA_PORTA_ADDRESS +GPIOPDIR_OFFSET);
			GPIO_DEN_address =(unsigned int* )(GPIODATA_PORTA_ADDRESS +GPIODEN_OFFSET);
			*GPIO_clock_enable_address = 0x00000001;
		break; 
		
		case PORT_B:
			GPIO_Dir_address =(unsigned int* )(GPIODATA_PORTB_ADDRESS +GPIOPDIR_OFFSET);
			GPIO_DEN_address =(unsigned int* )(GPIODATA_PORTB_ADDRESS +GPIODEN_OFFSET);
			*GPIO_clock_enable_address = 0x00000002;
		break;
		
		case PORT_C:
			GPIO_Dir_address =(unsigned int* )(GPIODATA_PORTC_ADDRESS +GPIOPDIR_OFFSET);
			GPIO_DEN_address =(unsigned int* )(GPIODATA_PORTC_ADDRESS +GPIODEN_OFFSET);
			*GPIO_clock_enable_address = 0x00000004;
			
		break;
		
		case PORT_D:
			GPIO_Dir_address =(unsigned int* )(GPIODATA_PORTD_ADDRESS +GPIOPDIR_OFFSET);
			GPIO_DEN_address =(unsigned int* )(GPIODATA_PORTD_ADDRESS +GPIODEN_OFFSET);
			*GPIO_clock_enable_address = 0x00000008;
		break; 
		
		case PORT_E:
			GPIO_Dir_address =(unsigned int* )(GPIODATA_PORTE_ADDRESS +GPIOPDIR_OFFSET);
			GPIO_DEN_address =(unsigned int* )(GPIODATA_PORTE_ADDRESS +GPIODEN_OFFSET);
			*GPIO_clock_enable_address = 0x00000010;
		break;
		
		case PORT_F:
			GPIO_Dir_address =(unsigned int* )(GPIODATA_PORTF_ADDRESS +GPIOPDIR_OFFSET);
			GPIO_DEN_address =(unsigned int* )(GPIODATA_PORTF_ADDRESS +GPIODEN_OFFSET);
			*GPIO_clock_enable_address = 0x00000020U;
		break;
		
		default:
			return NOK;
		break;
	}
	
	*GPIO_Dir_address=(*GPIO_Dir_address)& (~(1<<pin));
	*GPIO_DEN_address=(*GPIO_DEN_address)& (~(1<<pin));
	
	*GPIO_Dir_address= (*GPIO_Dir_address)| (dir<<pin);
	*GPIO_DEN_address=(*GPIO_DEN_address) | (pin_alternate_func<<pin);

	
	 return OK;
	
}

void Mcal_GPIO_blinking_LED(unsigned int port, unsigned int pin, unsigned int Value)
{
	unsigned int* GPIO_Data_address = 0x00;

	switch(port)
	{
		case PORT_A:
			GPIO_Data_address=(unsigned int* )(GPIODATA_PORTA_ADDRESS+GPIO_BitMASKING) ;
			
		break; 
		
		case PORT_B:
			GPIO_Data_address=(unsigned int* )(GPIODATA_PORTB_ADDRESS +GPIO_BitMASKING);
			
		break;
		
		case PORT_C:
			GPIO_Data_address=(unsigned int* )(GPIODATA_PORTC_ADDRESS+GPIO_BitMASKING) ;
			
		break;
		
		case PORT_D:
			GPIO_Data_address=(unsigned int* )(GPIODATA_PORTD_ADDRESS +GPIO_BitMASKING);
			
		break; 
		
		case PORT_E:
			GPIO_Data_address=(unsigned int* )(GPIODATA_PORTE_ADDRESS +GPIO_BitMASKING);
		
		break;
		
		case PORT_F:
			GPIO_Data_address=(unsigned int* )(GPIODATA_PORTF_ADDRESS+GPIO_BitMASKING) ;
		
		break;
		
		default:
			
		break;
	}
	
	*GPIO_Data_address =(*GPIO_Data_address)& (~(1<<pin));
	*GPIO_Data_address= (*GPIO_Data_address)| (Value<<pin);
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
*********************************************************************************************************************/






