/*
 * gpio_tset.c
 *
 *  Created on: Feb 24, 2020
 *      Author: TARGET
 */

#include "reg_gpio.h"
#include "gpio_test.h"


//REGISTERS IN SYSTEM CONTROL
REG GPIOHBCTL =        0x400FE06C ;
REG RCGCGPIO  =        0x400FE608 ;


void port_bus (unsigned long int port  , bus_select bus)
{
    if (bus == AHB){

        if(port==PORTA)

            BASE=A_AHB_BASE;

        else if(port==PORTB)

            BASE=B_AHB_BASE;

        else if(port==PORTC)

            BASE=C_AHB_BASE;

        else if(port==PORTD)

            BASE=D_AHB_BASE;

        else if(port==PORTE)

            BASE=E_AHB_BASE;

        else if(port==PORTF)

            BASE=F_AHB_BASE;
        }
    else if (bus ==APB){

            if(port==PORTA)

                BASE=A_APB_BASE;


            else if(port==PORTB)

                BASE=B_APB_BASE;

            else if(port==PORTC)

                BASE=C_APB_BASE;

            else if(port==PORTD)

                BASE=D_APB_BASE;

            else if(port==PORTE)

                BASE=E_APB_BASE;

            else if(port==PORTF)

                BASE=F_APB_BASE;
    }
}


void gpio_init( port_select port , bus_select bus )
{
    if (bus == AHB)
    {

       *GPIOHBCTL |= (1<<port);

       *RCGCGPIO |= (1<<port);

    }

    else if (bus == APB )
    {
        *GPIOHBCTL &= ~(1<<port);
        *RCGCGPIO |= (1<<port);
    }
}


void gpio_mode (unsigned long int port,unsigned int  pin , gpio_digital  enable , mode_t mode    ) // alternative and digital

{

   if  (mode == GPIOAFSEL_GPIO)
    {
       REG GPIODEN = B(OFF_GPIODEN);
        if (enable == GPIOD_EN )

            *GPIODEN |= (1<<pin);

       else if( enable == GPIO_DIS )

            *GPIODEN &= ~(1<<pin);
    }
}


void gpio_direction (unsigned long int port,unsigned int  pin ,pin_mode direction   )  // in or out
{
    REG GPIODIR = B(OFF_GPIODIR);

    if (direction == GPIODIR_OUT)

               *GPIODIR |= (1<<pin);

    else if  (direction == GPIODIR_IN )

        *GPIODIR &= ~(1<<pin) ;
}

void set_pin( unsigned long int port,unsigned char pin , unsigned char mask )
{
//REG GPIODATA =  0x4005D008;
    REG GPIODATA = B(OFF_GPIODATA+mask);
    *GPIODATA = (1<<pin);

}


void clear_pin( unsigned long int port,unsigned char pin , unsigned char mask)
{
    REG GPIODATA = B(OFF_GPIODATA+mask);
//    REG GPIODATA =  0x4005D008;
    *GPIODATA &= ~(1<<pin);

}


void driver_strength (unsigned long int port,unsigned int  pin ,output_rate rate  )
{
    REG GPIODR8R = B(OFF_GPIODR8R);
    REG GPIODR4R = B(OFF_GPIODR4R);
    REG GPIODR2R = B(OFF_GPIODR2R);

    switch (rate)
     {
              case GPIODR2R_2MA :
                  *GPIODR2R |= (1<<pin);
                  break;
              case GPIODR4R_4MA :
                  *GPIODR4R |= (1<<pin);
                  break;
              case GPIODR8R_8MA :
                  *GPIODR8R |= (1<<pin);
                  break;
     }
}
unsigned char GPIORead(unsigned long int port, unsigned char pins )
{
    REG GPIODATA = B(OFF_GPIODATA+60);

    unsigned char reading ;
    reading =  *(GPIODATA);
//    return reading ;

}

void pull_up(unsigned long int port, unsigned char pin )
{
    REG GPIOPUR = B(OFF_GPIOPUR);

    *GPIOPUR |= (1<<pin);


}


