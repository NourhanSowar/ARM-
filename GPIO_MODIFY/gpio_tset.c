/*
 * gpio_tset.c
 *
 *  Created on: Feb 24, 2020
 *      Author: TARGET
 */

#include "gpio_test.h"

#include "reg_test.h"


void gpio_init( port_select port , bus_select bus  )
{

    if (bus == AHB)
    {
    switch (port)
             {
                 case PORTA:
                     GPIOHBCTL_PORTA;
                     RCGCGPIO_PORTA;
                     break;



                 case PORTB:
                     GPIOHBCTL_PORTB;
                     RCGCGPIO_PORTB;
                      break;
//                     REGPORTB_INTI_AHB();


                 case PORTC:
                     GPIOHBCTL_PORTC;
                     RCGCGPIO_PORTC;
                     break;






                 case PORTD:
                     GPIOHBCTL_PORTD;
                     RCGCGPIO_PORTD;
                     break;






                 case PORTE:
                     GPIOHBCTL_PORTE;
                     RCGCGPIO_PORTE;
                     break;




                 case PORTF:
                     GPIOHBCTL_PORTF;
                     RCGCGPIO_PORTF;
                    // REG_PORTF_INTI_AHB();
                     break;






             }

    }


    else if (bus == APB ){

         switch (port)
         {
             case PORTA:
                 GPIOHBCTL_PORTA_APB;
                 RCGCGPIO_PORTA;

                 break;



             case PORTB:
                 GPIOHBCTL_PORTB_APB;
                 RCGCGPIO_PORTB;
                 break;

             case PORTC:
                 GPIOHBCTL_PORTC_APB;
                 RCGCGPIO_PORTC;

                    break;


             case PORTD:
                 GPIOHBCTL_PORTD_APB;
                 RCGCGPIO_PORTD;

                 break;


             case PORTE:
                 GPIOHBCTL_PORTE_APB;
                 RCGCGPIO_PORTE;

                 break;


             case PORTF:
                 GPIOHBCTL_PORTF_APB;
                 RCGCGPIO_PORTF;
                 break;

         }

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



void pin_modes (unsigned long int port,unsigned int  pin ,pin_mode direction   )  // in or out
{

    REG GPIODIR = B(OFF_GPIODIR);

    if (direction == GPIODIR_OUT)
           {

               *GPIODIR |= (1<<pin);
        //       GPIOWrite(  port,pin, data);
          //     driver_strength (port, pin , rate  );


           }

    else if  (direction == GPIODIR_IN )
        {

        *GPIODIR &= ~(1<<pin) ;
       // GPIORead(port, pin) ;


        }
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




unsigned char GPIORead(unsigned long int port, unsigned char pins ,, unsigned char mask)
{
    REG GPIODATA = B(OFF_GPIODATA +mask);
    unsigned char reading ;
    reading =  *(GPIODATA);
    return reading ;

}

void pull_up(unsigned long int port, unsigned char pin )
{
    REG GPIOPUR = B(OFF_GPIOPUR);

    *GPIOPUR |= (1<<pin);


}


