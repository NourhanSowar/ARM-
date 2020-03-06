/*
 * interrupt.h
 *
 *  Created on: Feb 25, 2020
 *      Author: TARGET
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

//****************enable interrupts********88
#define EN0_ADD         0xE000E100
#define EN1_ADD         0xE000E104
#define EN2_ADD         0xE000E108
#define EN3_ADD         0xE000E10C
#define EN4_ADD         0xE000E110

//***************888clear enable ******************

#define DIS0_ADD        0xE000E180
#define DIS1_ADD        0xE000E184
#define DIS2_ADD        0xE000E188
#define DIS3_ADD        0xE000E18C
#define DIS4_ADD        0xE000E190

//************************set pending *****************

#define PEND0_ADD       0xE000E200
#define PEND1_ADD       0xE000E204
#define PEND2_ADD       0xE000E208
#define PEND3_ADD       0xE000E20C
#define PEND4_ADD       0xE000E210

//**********************clear pending **************

#define UNPEND0_ADD     0xE000E280
#define UNPEND1_ADD     0xE000E284
#define UNPEND2_ADD     0xE000E288
#define UNPEND3_ADD     0xE000E28C
#define UNPEND4_ADD     0xE000E290

//***********************active bit *************
#define ACTIVE0_ADD     0xE000E300
#define ACTIVE1_ADD     0xE000E304
#define ACTIVE2_ADD     0xE000E308
#define ACTIVE3_ADD     0xE000E30C
#define ACTIVE4_ADD     0xE000E310
//*******************Software Trigger Interrupt*******
#define SWTRIG_ADD     0xE000EF00


#endif /* INTERRUPT_H_ */
