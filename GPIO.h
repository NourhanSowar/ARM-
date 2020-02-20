
#ifndef GPIO_H_
#define GPIO_H_

#include " REGMAP  "



//*****************PORTS**********************.//
#define PORTA               GPIOA
#define PORTB               GPIOB
#define PORTC               GPIOC
#define PORTD               GPIOD
#define PORTE               GPIOE
#define PORTF               GPIOF




 typedef enum
    {
        PORTA,
        PORTB,
        PORTC,
        PORTD,
        PORTE,
        PORTF
    }port_select;



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

//THIRD, DETERMINE THE DIRECTION IN OR OUT
#define PIN  // USER DETERMINE WHICH THE PIN IS USED

#define GPIODIR_IN                   //*GPIODIR &= ~(1<<PIN)
#define GPIODIR_OUT                   // *GPIODIR |= (1<<PIN)

typedef enum
{
    GPIODIR_IN,
    GPIODIR_OUT,


}pin_mode ;




//*****************************************************

//ALTERNATE FUNCTION CONTROL

#define GPIOAFSEL_GPIO                   //*GPIOAFSEL &= ~(1<<1)
#define GPIOAFSEL_ALT                    //*GPIOAFSEL |=  (1<<1)


typedef enum
{
    GPIOAFSEL_GPIO,
    GPIOAFSEL_ALT,



}mode_t;




//**************************************************************

#define GPIODR2R_2MA                     //*GPIODR2R |= (1<<PIN)
#define GPIODR4R_4MA                     //*GPIODR4R |= (1<<PIN)
#define GPIODR8R_8MA                    //*GPIODR8R |= (1<<PIN)


typedef enum
{
    GPIODR2R_2MA,
    GPIODR4R_4MA,
    GPIODR8R_8MA


}output_rate;


//***********************************************************

//DIGITAL ENABLE
#define GPIOD_EN                         //*GPIODEN |= (1<<PIN)
#define GPIO_DIS                         //*GPIODEN &= ~(1<<PIN)

typedef enum
{
    GPIOD_EN;
    GPIO_DIS;

}gpio_digital ;

//****************************DATA REGISTER************************

//*****************************GPIO Pull-Up Select (GPIOPUR)**************

#define GPIO_PUR_EN(PIN)                     *GPIOPUR |=(1<<PIN)
#define GPIO_PUR_DIS(PIN)                    *GPIOPUR &=~(1<<PIN)



//*******************PROTOTYPES**********************************



#endif /* GPIO_H_ */
