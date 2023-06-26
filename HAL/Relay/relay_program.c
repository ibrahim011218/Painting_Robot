
/*
 /****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  IBRAHIM MOHAMMED      ***************************/
/*************                LAYER :   HAL 			      ***************************/
/*************                SWC :     Relay		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 20-6-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/


#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "relay_interface.h"
#include "relay_config.h"


void relay_voidInitmotorhoz(void)
{
	DIO_u8SetPinDirection( relay1_port , relay1_pin1 , DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection( relay1_port , relay1_pin2 , DIO_u8PIN_OUTPUT);
}

void relay_voidInitmotorver(void)
{
	DIO_u8SetPinDirection( relay2_port , relay2_pin1 , DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection( relay2_port , relay2_pin2 , DIO_u8PIN_OUTPUT);
}


u8 relay_u8setmotorhoz(u8 copy_u8direction)
{
	u8 Local_u8ErrorState= OK;
	if(copy_u8direction == forward)
	{
		DIO_u8SetPinValue(relay1_port,relay1_pin1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(relay1_port,relay1_pin2,DIO_u8PIN_LOW);

	}
	else if (copy_u8direction == reverse)
	{
		DIO_u8SetPinValue(relay1_port,relay1_pin1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(relay1_port,relay1_pin2,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState= NOK;
	}
	return Local_u8ErrorState;
}


u8 relay_u8setmotorver(u8 copy_u8direction)
{
	u8 Local_u8ErrorState= OK;
	if(copy_u8direction == high)
	{
		DIO_u8SetPinValue(relay2_port,relay2_pin1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(relay2_port,relay2_pin2,DIO_u8PIN_LOW);

	}
	else if (copy_u8direction == low)
	{
		DIO_u8SetPinValue(relay2_port,relay2_pin1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(relay2_port,relay2_pin2,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState= NOK;
	}
	return Local_u8ErrorState;
}


void relay_VoidStopmotorver(void)
{
	DIO_u8SetPinValue(relay2_port,relay2_pin1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(relay2_port,relay2_pin2,DIO_u8PIN_LOW);
}



void relay_VoidStopmotorhoz(void)
{
	DIO_u8SetPinValue(relay1_port,relay1_pin1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(relay1_port,relay1_pin2,DIO_u8PIN_LOW);
}




