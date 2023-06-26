/*
 /****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  IBRAHIM MOHAMMED      ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     EXTI		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 20-6-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"EXTI_config.h"
#include"EXTI_register.h"
#include"EXTI_interface.h"



static void(*INT0_CallBackFunc)(void)=NULL;

static void(*INT1_CallBackFunc)(void)=NULL;



void EXTI_INT0_INIT(void)
{

	/* set sense control for INT0 to falling edge*/
	SET_BIT( MCUCR , MCUCR_ISC01 );
	CLR_BIT( MCUCR , MCUCR_ISC00 );

	/* Peripheral interrupt enable for INT0 */
	SET_BIT( GICR , GICR_INT0 );

}

void EXTI_INT1_INIT(void)
{

	/* Set Interrupt Sense To Falling Edge*/
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
	/*Enable EXTI 1*/
	SET_BIT( GICR, GICR_INT1);
	/*Check Triggering MODE*/

}




u8 EXTI_INT0_CallBackFunc( void(*Copy_INTCallBackFunc)(void) )
{
	u8 Local_u8ErrorStatus = OK;

	if(Copy_INTCallBackFunc != NULL){
		INT0_CallBackFunc = Copy_INTCallBackFunc;
	}
	else{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}



void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(INT0_CallBackFunc != NULL)
	{
		INT0_CallBackFunc();
	}
}



u8 EXTI_INT1_CallBackFunc( void(*Copy_INTCallBackFunc)(void) )
{
	u8 Local_u8ErrorStatus = OK;

	if(Copy_INTCallBackFunc != NULL){
		INT1_CallBackFunc = Copy_INTCallBackFunc;
	}
	else{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}



void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(INT1_CallBackFunc != NULL)
	{
		INT1_CallBackFunc();
	}
}






/*INT0 */
/*
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{

}
*/


/*INT1 */
/*
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{

}
*/

