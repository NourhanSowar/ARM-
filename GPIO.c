/*
 * GPIO.c
 *
 *  Created on: Feb 10, 2020
 *      Author: TARGET
 */


#include "GPIO.h"
#include "REGMAP.h"


    REG  GPIODIR =  AB(OFF_GPIODIR);
    REG  GPIOAFSEL= AB(OFF_GPIOAFSEL);
    REG  GPIODR8R = AB(OFF_GPIODR8R);
    REG  GPIODR4R = AB(OFF_GPIODR4R);
    REG  GPIODR2R = AB(OFF_GPIODR2R);

    REG  GPIODEN=   AB(OFF_GPIODEN);
    REG GPIOPUR =   AB(OFF_GPIOPUR);
    REG GPIODATA =  AB(OFF_GPIODATA);
    REG GPIOPCTL =  AB(OFF_GPIOPCTL);
    REG GPIOAMSEL = AB(OFF_GPIOAMSEL);
    REG GPIOSLR  =  AB(OFF_GPIOSLR);
    REG GPIOPDR  =  AB(OFF_GPIOPDR);
    REG GPIOODR  =  AB(OFF_GPIOODR);

void gpio_init( port_select port , bus_select bus  )
{


    switch (port)
             {
                 case PORTA:
                     GPIOHBCTL_PORTA;
                     RCGCGPIO_PORTA;

                     REG_PORTA_INTI_AHB();



                 case PORTB:
                     GPIOHBCTL_PORTB;
                     RCGCGPIO_PORTB;

                     REG_PORTB_INTI_AHB();


                 case PORTC:
                     GPIOHBCTL_PORTC;
                     RCGCGPIO_PORTC;

                     REG_PORTC_INTI_AHB();





                 case PORTD:
                     GPIOHBCTL_PORTD;
                     RCGCGPIO_PORTD;
                     REG_PORTD_INTI_AHB();







                 case PORTE:
                     GPIOHBCTL_PORTE;
                     RCGCGPIO_PORTE;
                     REG_PORTE_INTI_AHB();




                 case PORTF:
                     GPIOHBCTL_PORTF;
                     RCGCGPIO_PORTE;
                     REG_PORTF_INTI_AHB();





             }



    if (bus == APB ){

         switch (port)
         {
             case PORTA:
                 GPIOHBCTL_PORTA_APB;
                 RCGCGPIO_PORTA;
                 REG_PORTA_INTI_APB();




             case PORTB:
                 GPIOHBCTL_PORTB_APB;
                 RCGCGPIO_PORTB;
                 REG_PORTB_INTI_APB();


             case PORTC:
                 GPIOHBCTL_PORTC_APB;
                 RCGCGPIO_PORTC;
                 REG_PORTC_INTI_APB();






             case PORTD:
                 GPIOHBCTL_PORTD_APB;
                 RCGCGPIO_PORTD;
                 REG_PORTD_INTI_APB();



             case PORTE:
                 GPIOHBCTL_PORTE_APB;
                 RCGCGPIO_PORTE;
                 REG_PORTE_INTI_APB();






             case PORTF:
                 GPIOHBCTL_PORTF_APB;
                 RCGCGPIO_PORTF;
                 REG_PORTF_INTI_APB();


         }

       }


    }

void gpio_mode (unsigned int  pin , gpio_digital enable , mode_t mode    ) // alternative and digital

{
    while  (mode == GPIOAFSEL_GPIO)
    {

        if (enable == GPIOD_EN )
            *GPIODEN |= (1<<pin);

        else if ( enable == GPIO_DIS )
             *GPIODEN &= ~(1<<pin);


    }
}

void pin_modes (unsigned int  pin ,pin_mode direction , output_rate rate  )  // in or out
{
    unsigned char data;
    unsigned long int port;

    if (direction == GPIODIR_OUT)
           {
               *GPIODIR |= (1<<pin);
               GPIOWrite( pin, data);
               driver_strength (  pin , rate  );


           }

    else if  (direction == GPIODIR_IN )
        {

        *GPIODIR &= ~(1<<pin) ;
        GPIORead(port, pin) ;


        }
}

void driver_strength (unsigned int  pin ,output_rate rate  )
{
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




unsigned char GPIORead(unsigned long int port, unsigned char pins)
{

    unsigned int reading ;
    reading =  *(GPIODATA);
    return reading ;

}

void GPIOWrite( unsigned char pin, unsigned char data)
{

    *GPIODATA = (data<<pin);

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

