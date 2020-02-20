/*
 * GPIO.c
 *
 *  Created on: Feb 10, 2020
 *      Author: TARGET
 */


#include "GPIO.h"

void gpio_init( port_select port , bus_select bus  )
{


    switch (port)
             {
                 case PORTA:
                     GPIOHBCTL_PORTA;
                     RCGCGPIO_PORTA;

                 case PORTB:
                     GPIOHBCTL_PORTB;
                     RCGCGPIO_PORTB;

                 case PORTC:
                     GPIOHBCTL_PORTC;
                     RCGCGPIO_PORTC;


                 case PORTD:
                     GPIOHBCTL_PORTD;
                     RCGCGPIO_PORTD;


                 case PORTE:
                     GPIOHBCTL_PORTE;
                     RCGCGPIO_PORTE;


                 case PORTF:
                     GPIOHBCTL_PORTF;
                     RCGCGPIO_PORTE;


             }



    if (bus == APB ){

         switch (port)
         {
             case PORTA:
                 GPIOHBCTL_PORTA_APB;
                 RCGCGPIO_PORTA;


             case PORTB:
                 GPIOHBCTL_PORTB_APB;
                 RCGCGPIO_PORTB;


             case PORTC:
                 GPIOHBCTL_PORTC_APB;
                 RCGCGPIO_PORTC;


             case PORTD:
                 GPIOHBCTL_PORTD_APB;
                 RCGCGPIO_PORTD;


             case PORTE:
                 GPIOHBCTL_PORTE_APB;
                 RCGCGPIO_PORTE;


             case PORTF:
                 GPIOHBCTL_PORTF_APB;
                 RCGCGPIO_PORTF;

         }

       }


    }

void gpio_mode (unsigned int  pin , gpio_digital enable , mode_t mode    )

{
    while  (mode == GPIOAFSEL_GPIO)
    {

        if (enable == GPIOD_EN )
            *GPIODEN |= (1<<pin);

        else ( enable == GPIO_DIS )
                *GPIODEN &= ~(1<<pin);


    }
}

void driver_strength (unsigned int  pin ,pin_mode direction , output_rate rate  )
{

    if (directoin == GPIODIR_OUT)
           {
               *GPIODIR |= (1<<pin);

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
}





//
//void PORTA_CONFIG_OUT (PIN_NUM , output_rate rate ,  )
//{
//
//
//    REG  GPIODIR =  AB(OFF_GPIODIR);
//    REG  GPIOAFSEL= AB(OFF_GPIOAFSEL);
//    REG  GPIODR8R = AB(OFF_GPIODR8R);
//    REG  GPIODEN=   AB(OFF_GPIODEN);
//    REG GPIOPUR =  AB(OFF_GPIOPUR);
//
//
//    GPIOHBCTL_PORTA;
//    RCGCGPIO_PORTA;
//    GPIODIR_OUT(PIN_NUM);
//    GPIOAFSEL_GPIO;
//    GPIOD_EN;
//    GPIO_PUR_DIS(PIN_NUM) ;
//
//}

