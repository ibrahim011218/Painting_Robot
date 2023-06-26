/*
 /****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  IBRAHIM MOHAMMED      ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     DIO		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 20-6-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define DIO_u8PIN_OUTPUT		1
#define DIO_u8PIN_INPUT			0

#define DIO_u8PIN_HIGH			1
#define DIO_u8PIN_LOW			0

#define DIO_u8PORT_OUTPUT		0xFF
#define DIO_u8PORT_INPUT		0

#define DIO_u8PORT_HIGH 		0xFF
#define DIO_u8PORT_LOW  		0

#define DIO_u8PORTA				0
#define DIO_u8PORTB				1
#define DIO_u8PORTC				2
#define DIO_u8PORTD				3

#define DIO_u8PIN0				0
#define DIO_u8PIN1				1
#define DIO_u8PIN2				2
#define DIO_u8PIN3				3
#define DIO_u8PIN4				4
#define DIO_u8PIN5				5
#define DIO_u8PIN6				6
#define DIO_u8PIN7				7

//#define OK     0
#define NOK    0


/*
 * Description : Set Direction For Pin
 * Arguments   : Port Number , Pin Number , Pin Direction
 * Return      : u8 Error state if Function does not work
 */
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/*
 * Description : Set Direction For Port
 * Arguments   : Port Number , Pin Direction
 * Return      : u8 Error state if Function does not work
 */
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

/*
 * Description : Set Value For Pin
 * Arguments   : Port Number , Pin Number , The Value
 * Return      : u8 Error state if Function does not work
 */
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/*
 * Description : Set Value For Port
 * Arguments   : Port Number , The Value
 * Return      : u8 Error state if Function does not work
 */
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

/*
 * Description : Get Value From Pin
 * Arguments   : Port Number , Pin Number , The Return Value
 * Return      : u8 Error state if Function does not work
 */
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin, u8* Copy_pu8Value);


#endif
