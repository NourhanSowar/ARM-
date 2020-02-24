/*
 * gpio_test.h
 *
 *  Created on: Feb 24, 2020
 *      Author: TARGET
 */

#ifndef GPIO_TEST_H_
#define GPIO_TEST_H_



typedef enum
   {
       PORTA,
       PORTB,
       PORTC,
       PORTD,
       PORTE,
       PORTF
   }port_select;




// *****************************************OFFSETS OF REGISTERS******************************//

#define     OFF_GPIODIR        0x400
#define     OFF_GPIOAFSEL      0x420
#define     OFF_GPIODR2R       0x500
#define     OFF_GPIODR4R       0x504
#define     OFF_GPIODR8R       0x508
#define     OFF_GPIODEN        0x51C
#define     OFF_GPIOPUR        0x510
#define     OFF_GPIODATA       0x000
#define     OFF_GPIOPCTL       0x52C   //used in conjunction with the GPIOAFSEL
#define     OFF_GPIOAMSEL      0x528   //GPIO Analog Mode Select
#define     OFF_GPIOSLR        0x518   //Slew Rate Control Select
#define     OFF_GPIOPDR        0x514
#define     OFF_GPIOODR        0x50C



////*********** ADDRESS OF  PORTS  BASE ADD+OFFSET******************//
//
////MACROS TO ADDRESS
//#define AB(offest) A_AHB_BASE+offest
//#define BB(offest) B_AHB_BASE+offest
//#define CB(offest) C_AHB_BASE+offest
//#define DB(offest) D_AHB_BASE+offest
//#define EB(offest) E_AHB_BASE+offest
//#define FB(offest) F_AHB_BASE+offest
//
////MACROS TO ADDRESS
//#define AB_APB(offest) A_APB_BASE+offest
//#define BB_APB(offest) B_APB_BASE+offest
//#define CB_APB(offest) C_APB_BASE+offest
//#define DB_APB(offest) D_APB_BASE+offest
//#define EB_APB(offest) E_APB_BASE+offest
//


#define     A_AHB_BASE        0x40058000
#define     B_AHB_BASE        0x40059000
#define     C_AHB_BASE        0x4005A000
#define     D_AHB_BASE        0x4005B000
#define     E_AHB_BASE        0x4005C000
#define     F_AHB_BASE        0x4005D000


#define     A_APB_BASE        0x40004000
#define     B_APB_BASE        0x40005000
#define     C_APB_BASE        0x40006000
#define     D_APB_BASE        0x40007000
#define     E_APB_BASE        0x40024000
#define     F_APB_BASE        0x40025000



 unsigned long int BASE;
#define B(offset) BASE+offset

//*********************GPIO High-Performance Bus Control********************//

//FIRST STEP IN GPIO TO DETERMINE THE BUS YOU USE:D

#define GPIOHBCTL_PORTA                 *GPIOHBCTL |= (1<<0)
#define GPIOHBCTL_PORTB                 *GPIOHBCTL |= (1<<1)
#define GPIOHBCTL_PORTC                 *GPIOHBCTL |= (1<<2)
#define GPIOHBCTL_PORTD                 *GPIOHBCTL |= (1<<3)
#define GPIOHBCTL_PORTE                 *GPIOHBCTL |= (1<<4)
#define GPIOHBCTL_PORTF                 *GPIOHBCTL |= (1<<5)


#define GPIOHBCTL_PORTA_APB                 *GPIOHBCTL &= ~(1<<0)
#define GPIOHBCTL_PORTB_APB                 *GPIOHBCTL &= ~(1<<1)
#define GPIOHBCTL_PORTC_APB                 *GPIOHBCTL &= ~(1<<2)
#define GPIOHBCTL_PORTD_APB                 *GPIOHBCTL &= ~(1<<3)
#define GPIOHBCTL_PORTE_APB                 *GPIOHBCTL &= ~(1<<4)
#define GPIOHBCTL_PORTF_APB                 *GPIOHBCTL &= ~(1<<5)



    typedef enum
    {
        AHB,
        APB

    }bus_select;






//**********************General-Purpose Input/Output Run Mode Clock Gating Control******//

//SECOND STEP IS TO ENABLE THE CLOCK OF PORT YOU USE

#define RCGCGPIO_PORTA                   *RCGCGPIO |= (1<<0)
#define RCGCGPIO_PORTB                   *RCGCGPIO |= (1<<1)
#define RCGCGPIO_PORTC                   *RCGCGPIO |= (1<<2)
#define RCGCGPIO_PORTD                   *RCGCGPIO |= (1<<3)
#define RCGCGPIO_PORTE                   *RCGCGPIO |= (1<<4)
#define RCGCGPIO_PORTF                   *RCGCGPIO |= (1<<5)




//*********************************************************************************//

    typedef enum
    {
        GPIODIR_IN,
        GPIODIR_OUT


    }pin_mode ;


    typedef enum
    {
        GPIOAFSEL_GPIO,
        GPIOAFSEL_ALT



    }mode_t;




    //**************************************************************


    typedef enum
    {
        GPIODR2R_2MA,
        GPIODR4R_4MA,
        GPIODR8R_8MA


    }output_rate;


    //***********************************************************
    typedef enum
    {
        GPIOD_EN,
        GPIO_DIS

    }gpio_digital ;

//*********************************************************************************//





    void gpio_init( port_select port , bus_select bus  );
    void gpio_mode (unsigned long int port,unsigned int  pin , gpio_digital enable , mode_t mode    ) ;

    void addresses_reg ( unsigned long int port );

    void port_bus (unsigned long int port  , bus_select bus);
    void pin_modes (unsigned long int port,unsigned int  pin ,pin_mode direction   ) ;
    void set_pin(   unsigned long int port,   unsigned char pin,   unsigned char mask );
    void clear_pin( unsigned long int port, unsigned char pin, unsigned char mask );
    void driver_strength (unsigned long int port,unsigned int  pin ,output_rate rate  );
    unsigned char GPIORead(unsigned long int port, unsigned char pins);
    void pull_up(unsigned long int port, unsigned char pins );
#endif /* GPIO_TEST_H_ */
