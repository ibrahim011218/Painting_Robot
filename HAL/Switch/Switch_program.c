/*
 /****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  IBRAHIM MOHAMMED      ***************************/
/*************                LAYER :   HAL 			      ***************************/
/*************                SWC :     Switch		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 20-6-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"
#include "Switch_interface.h"




void Init_SwitchsPins(void)
{
	/*Initial INT0 for Switch1*/
	EXTI_INT0_INIT();
	/*Initial INT0 for Switch1*/
	EXTI_INT1_INIT();
	/*Initial Global Interrupt Enable */
	GIE_Enable();

	/* Define INT0 INPUT & PULLUP for Switch1*/
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);

	/*Define INT1 PIN AS INPUT & PULLUP for Switch2*/
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);

}


u8 Switch1_CallBackFunc( void(*Copy_SwitchCallBackFunc)(void) )
{
	u8 Local_u8ErrorStatus = OK;

	if(Copy_SwitchCallBackFunc != NULL){

		EXTI_INT0_CallBackFunc(Copy_SwitchCallBackFunc);
	}
	else{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}


u8 Switch2_CallBackFunc( void(*Copy_SwitchCallBackFunc)(void) )
{
	u8 Local_u8ErrorStatus = OK;

	if(Copy_SwitchCallBackFunc != NULL){
		EXTI_INT1_CallBackFunc(Copy_SwitchCallBackFunc);
	}
	else{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

