/*
 * reg_test.h
 *
 *  Created on: Feb 24, 2020
 *      Author: TARGET
 */

#ifndef REG_TEST_H_
#define REG_TEST_H_

#define REG volatile unsigned long int *




//REGISTERS IN SYSTEM CONTROL
REG GPIOHBCTL =        0x400FE06C ;
REG RCGCGPIO  =        0x400FE608 ;


void port_bus (unsigned long int port  , bus_select bus)
{
    if (bus == AHB){
    if(port==PORTA)
    {
        BASE=A_AHB_BASE;
    }

    else if(port==PORTB)
    {
        BASE=B_AHB_BASE;
    }
    else if(port==PORTC)
    {
        BASE=C_AHB_BASE;
    }
    else if(port==PORTD)
    {
        BASE=D_AHB_BASE;
    }
    else if(port==PORTE)
    {
        BASE=E_AHB_BASE;
    }
    else if(port==PORTF)
    {
        BASE=F_AHB_BASE;
    }
    }
    else if (bus ==APB){

        if(port==PORTA)
            {
                BASE=A_APB_BASE;
            }

            else if(port==PORTB)
            {
                BASE=B_APB_BASE;
            }
            else if(port==PORTC)
            {
                BASE=C_APB_BASE;
            }
            else if(port==PORTD)
            {
                BASE=D_APB_BASE;
            }
            else if(port==PORTE)
            {
                BASE=E_APB_BASE;
            }
            else if(port==PORTF)
            {
                BASE=F_APB_BASE;
            }



    }
}



//

#endif /* REG_TEST_H_ */
