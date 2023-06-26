
 /****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  IBRAHIM MOHAMMED      ***************************/
/*************                LAYER :   HAL 			      ***************************/
/*************                SWC :     Switch		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 20-6-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef HAL_SWITCH_SWITCH_INTERFACE_H_
#define HAL_SWITCH_SWITCH_INTERFACE_H_


/*
 * Description : Initialization switches and EXTI0 ,ETI1 and GIE
 * Arguments   : NO Arguments (void)
 * Return      : NO Return (void)
 */
void Init_SwitchsPins(void);


/*
 * Description : Call Back Function to run ISR of Interrupt 0
 * Arguments   : Pointer to Function
 * Return      : u8 Error state if Function does not work
 */
u8 Switch1_CallBackFunc( void(*Copy_SwitchCallBackFunc)(void) );


/*
 * Description : Call Back Function to run ISR of Interrupt 1
 * Arguments   : Pointer to Function
 * Return      : u8 Error state if Function does not work
 */
u8 Switch2_CallBackFunc( void(*Copy_SwitchCallBackFunc)(void) );

#endif /* HAL_SWITCH_SWITCH_INTERFACE_H_ */
