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


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



/*
 * Description : Initialization the External Interrupt 0
 * Arguments   : NO Arguments (void)
 * Return      : NO Return (void)
 */
void EXTI_INT0_INIT(void);

/*
 * Description : Initialization the External Interrupt 1
 * Arguments   : NO Arguments (void)
 * Return      : NO Return (void)
 */
void EXTI_INT1_INIT(void);


/*
 * Description : Call Back Function to run ISR of Interrupt 0
 * Arguments   : Pointer to Function
 * Return      : u8 Error state if Function does not work
 */
u8 EXTI_INT0_CallBackFunc(void(*Copy_INTCallBackFunc)(void));

/*
 * Description : Call Back Function to run ISR of Interrupt 1
 * Arguments   : Pointer to Function
 * Return      : u8 Error state if Function does not work
 */
u8 EXTI_INT1_CallBackFunc(void(*Copy_INTCallBackFunc)(void));

#endif /* EXTI_INTERFACE_H_ */
