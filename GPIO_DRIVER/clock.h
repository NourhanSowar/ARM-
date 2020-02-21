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
#endif /* CLOCK_H_ */
