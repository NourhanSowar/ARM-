
#ifndef GPIO_H_
#define GPIO_H_

#define REG volatile unsigned long int *


//REGISTERS IN SYSTEM CONTROL
REG GPIOHBCTL =        0x400FE06C ;
REG RCGCGPIO  =        0x400FE608 ;



//*****************PORT names**********************.//
#define PORTA               GPIOA
#define PORTB               GPIOB
#define PORTC               GPIOC
#define PORTD               GPIOD
#define PORTE               GPIOE
#define PORTF               GPIOF

//*********** ADDRESS OF  PORTS  BASE ADD+OFFSET******************//

#define A_AHB_BASE        0x40058000
#define B_AHB_BASE        0x40059000
#define C_AHB_BASE        0x4005A000
#define D_AHB_BASE        0x4005B000
#define E_AHB_BASE        0x4005C000
#define F_AHB_BASE        0x4005D000



// OFFSETS OF REGISTERS

#define OFF_GPIODIR        0x400
#define OFF_GPIOAFSEL      0x420
#define OFF_GPIODR2R       0x500
#define OFF_GPIODR4R       0x504
#define OFF_GPIODR8R       0x508
#define OFF_GPIODEN        0x51C
#define OFF_GPIOPUR        0x510

//MACROS TO ADDRESS
#define AB(offest) A_AHB_BASE+offest
#define BB(offest) B_AHB_BASE+offest
#define CB(offest) C_AHB_BASE+offest
#define DB(offest) D_AHB_BASE+offest
#define EB(offest) E_AHB_BASE+offest
#define FB(offest) F_AHB_BASE+offest




//*********************GPIO High-Performance Bus Control********************//

//FIRST STEP IN GPIO TO DETERMINE THE BUS YOU USE:D

#define GPIOHBCTL_PORTA                 *GPIOHBCTL |= (1<<0)
#define GPIOHBCTL_PORTB                 *GPIOHBCTL |= (1<<1)
#define GPIOHBCTL_PORTC                 *GPIOHBCTL |= (1<<2)
#define GPIOHBCTL_PORTD                 *GPIOHBCTL |= (1<<3)
#define GPIOHBCTL_PORTE                 *GPIOHBCTL |= (1<<4)
#define GPIOHBCTL_PORTF                 *GPIOHBCTL |= (1<<5)


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

#define GPIODIR_IN(PIN)                     *GPIODIR &= ~(1<<PIN)
#define GPIODIR_OUT(PIN)                    *GPIODIR |= (1<<PIN)

//*****************************************************

//ALTERNATE FUNCTION CONTROL

#define GPIOAFSEL_GPIO                   *GPIOAFSEL &= ~(1<<1)
#define GPIOAFSEL_ALT                    *GPIOAFSEL |=  (1<<1)


//**************************************************************

#define GPIODR2R_2MA                     *GPIODR2R |= (1<<1)
#define GPIODR4R_4MA                     *GPIODR4R |= (1<<1)
#define GPIODR8R_8MA                     *GPIODR8R |= (1<<1)



//***********************************************************

//DIGITAL ENABLE
#define GPIOD_EN                         *GPIODEN |= (1<<1)
#define GPIO_DIS                         *GPIODEN &= ~(1<<1)

//****************************DATA REGISTER************************

//*****************************GPIO Pull-Up Select (GPIOPUR)**************

#define GPIO_PUR_EN(PIN)                     *GPIOPUR |=(1<<PIN)
#define GPIO_PUR_DIS(PIN)                    *GPIOPUR &=~(1<<PIN)



//*******************PROTOTYPES**********************************
void PORTF_COFIG_OUT (PIN_NUM);
void PORTE_COFIG_OUT (PIN_NUM);
void PORTA_COFIG_OUT (PIN_NUM);
void PORTB_COFIG_OUT (PIN_NUM);
void PORTC_COFIG_OUT (PIN_NUM);
void PORTD_COFIG_OUT (PIN_NUM);

void PORTF_COFIG_IN (PIN_NUM);
void PORTA_COFIG_IN (PIN_NUM);
void PORTB_COFIG_IN (PIN_NUM);
void PORTC_COFIG_IN (PIN_NUM);
void PORTD_COFIG_IN (PIN_NUM);
void PORTE_COFIG_IN (PIN_NUM);






#endif /* GPIO_H_ */
