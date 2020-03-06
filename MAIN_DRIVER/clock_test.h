/*
 * clock.h
 *
 *  Created on: Feb 12, 2020
 *      Author: TARGET
 */

#ifndef CLOCK_H_
#define CLOCK_H_
void clcok();
volatile unsigned long int * RCC = 0x400FE060;
volatile unsigned long int * RCGCTIMER = 0x400FE604; //for 16/32
volatile unsigned long int * RCGCWTIMER = 0x400FE65C; //for 16/32


//#define REG volatile unsigned long int *

//int main ()
//{

//return 0;
//}

void clcok()
{

    *RCC |= (1<<11);
    *RCC &= ~(1<<22);
    *RCC |= (1<<4);
    *RCC &= ~(1<<5);
    *RCC |= (1<<13);


}
// enable clock for timers
void clock_timer1632 (unsigned char number )
{
    if ( number == 5)
            *RCGCTIMER |= (1<5);
    else if ( number == 4)
            *RCGCTIMER |= (1<4);
    else if ( number == 3)
            *RCGCTIMER |= (1<3);
    else if ( number == 2)
            *RCGCTIMER |= (1<2);
    else if ( number == 1)
            *RCGCTIMER |= (1<1);
    else if ( number == 0)
            *RCGCTIMER |= (1<0);

}


// enable clock for timers
void clock_timer3264 (unsigned char number )
{
    if ( number == 5)
            *RCGCWTIMER |= (1<5);
    else if ( number == 4)
            *RCGCWTIMER |= (1<4);
    else if ( number == 3)
            *RCGCWTIMER |= (1<3);
    else if ( number == 2)
            *RCGCWTIMER |= (1<2);
    else if ( number == 1)
            *RCGCWTIMER |= (1<1);
    else if ( number == 0)
            *RCGCWTIMER |= (1<0);

}
#endif /* CLOCK_H_ */
