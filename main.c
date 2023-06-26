
 /****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  IBRAHIM MOHAMMED      ***************************/
/*************                LAYER :   HAL 			      ***************************/
/*************                SWC :     Switch		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 20-6-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/GIE/GIE_interface.h"

#include "HAL/Switch/Switch_interface.h"
#include "HAL/Relay/relay_interface.h"

#include "util/delay.h"


/* Function to set the flag switch1 when motor move forward*/
void motorForward(void);

/* Function to set the flag switch2 when motor move reverse*/
void motorReverse(void);


volatile u8 Flag_Switch1=0;

volatile u8 Flag_Switch2=0;

void main (void)
{
	u8 Loop_Counter=0;

	relay_voidInitmotorhoz();
	relay_voidInitmotorver();

	Init_SwitchsPins();

	Switch2_CallBackFunc(&motorForward);
	Switch1_CallBackFunc(&motorReverse);


	while(1)
	{
		/* Set Motor Horizontal forward*/
		relay_u8setmotorhoz(forward);

		/* Delay for 11 second*/
		for(Loop_Counter=0; Loop_Counter<11;Loop_Counter++)
		{
			_delay_ms(1000);

			/* check if interrupt0 is happened*/
			if(Flag_Switch1 == 1)
			{
				/*Clear flag switch2*/
				Flag_Switch1=0;
				/*break from loop*/
				break;
			}
		}

		/* stop Motor Horizontal*/
		relay_VoidStopmotorhoz();

		/* Set Motor Vertical high*/
		relay_u8setmotorver(high);

		_delay_ms(5000);

		/* stop Motor vertical*/
		relay_VoidStopmotorver();

		/* Set Motor Horizontal Reverse*/
		relay_u8setmotorhoz(reverse);

		/* Delay for 45 second*/
		for(Loop_Counter=0; Loop_Counter<13;Loop_Counter++)
		{
			_delay_ms(1000);

			/* check if interrupt0 is happened*/
			if(Flag_Switch2 == 2)
			{
				/*Clear flag switch2*/
				Flag_Switch2=0;
				/*break from loop*/
				break;
			}
		}

		/* stop Motor Horizontal*/
		relay_VoidStopmotorhoz();

		/* Set Motor vertical high*/
		relay_u8setmotorver(high);

		_delay_ms(5000);

		/* stop Motor vertical*/
		relay_VoidStopmotorver();


	}
}




	void motorForward(void)
	{
		/*set the flag switch1 */
		Flag_Switch1=1;
	}

	void motorReverse(void)
	{
		/*set the flag switch2 */
		Flag_Switch2=2;
	}




