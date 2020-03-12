/*
 * clock.h
 *
 *  Created on: Feb 12, 2020
 *      Author: TARGET
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "timer.h"

void clcok();
void clock_timer1632 (timer_select  timer_number );
void clock_timer3264 (timer_select  timer_number );



volatile unsigned long int * RCC = 0x400FE060;

// intilalize clock for timers
volatile unsigned long int * RCGCTIMER = 0x400FE604; //for 16/32
volatile unsigned long int * RCGCWTIMER = 0x400FE65C; //for 32/64

void clcok()
{

    *RCC |= (1<<11);
    *RCC &= ~(1<<22);
    *RCC |= (1<<4);
    *RCC &= ~(1<<5);
    *RCC |= (1<<13);


}
/*-----------------------------------------------------------------------------------------*/
// enable clock for timers
void clock_timer1632 (timer_select  timer_number )
{
            *RCGCTIMER |= (1<<timer_number);
}



void clock_timer3264 (timer_select  timer_number )
{
            *RCGCWTIMER |= (1<<timer_number);

}
#endif /* CLOCK_H_ */
