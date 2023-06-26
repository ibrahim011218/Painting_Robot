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

#ifndef HAL_RELAY_RELAY_INTERFACE_H_
#define HAL_RELAY_RELAY_INTERFACE_H_

/*
 * Description : Initialization the horizontal Relay
 * Arguments   : NO Arguments (void)
 * Return      : NO Return (void)
 */
void relay_voidInitmotorhoz(void);

/*
 * Description : Initialization the Vertical Relay
 * Arguments   : NO Arguments (void)
 * Return      : NO Return (void)
 */
void relay_voidInitmotorver(void);

/*
 * Description : Set the horizontal Relay
 * Arguments   : Direction
 * Return      : u8 Error state if Function does not work
 */
u8 relay_u8setmotorhoz(u8 copy_u8direction);

/*
 * Description : Set the Vertical Relay
 * Arguments   : Direction
 * Return      : u8 Error state if Function does not work
 */
u8 relay_u8setmotorver(u8 copy_u8direction);

/*
 * Description : Stop the Vertical Relay
 * Arguments   : NO Arguments (void)
 * Return      : NO Return (void)
 */
void relay_VoidStopmotorver(void);

/*
 * Description : Stop the horizontal Relay
 * Arguments   : NO Arguments (void)
 * Return      : NO Return (void)
 */
void relay_VoidStopmotorhoz(void);

#define forward 1
#define reverse 0

#define high    1
#define low     0

#endif /* HAL_RELAY_RELAY_INTERFACE_H_ */















