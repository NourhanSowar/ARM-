/*
 * TEST.h
 *
 *  Created on: Mar 8, 2020
 *      Author: TARGET
 */

#ifndef TEST_H_
#define TEST_H_

void en(unsigned int ID) ;
void dis(unsigned int ID) ;


#define BASE_INTERRUPT  0xE000E

#define ADD( offset)    BASE_INTERRUPT+offset

#define INT_EN volatile unsigned long int *



void en(unsigned int ID)
{

    unsigned char offset_int ;

    offset_int =   100+( (ID/32)*4) ;  // EN0
     INT_EN  EN=   ADD( offset_int );
    * EN |= (1<< (ID % 32 ) );
}


void dis(unsigned int ID)
{

    unsigned char offset_int ;

    offset_int =   100+( (ID/32)*4) ;  // EN0
     INT_EN  EN=   ADD( offset_int );
    * EN &= ~(1<< (ID % 32 ) );
}


#endif /* TEST_H_ */
