

#include "GPIO.h"
#include "clock.h"

#define REG volatile unsigned long int *

REG  GPIODIR =  FB(OFF_GPIODIR);
REG  GPIOAFSEL= FB(OFF_GPIOAFSEL);
REG  GPIODR8R = FB(OFF_GPIODR8R);
REG  GPIODEN=  FB(OFF_GPIODEN);
REG GPIOPUR = FB(OFF_GPIOPUR);


REG GPIODATA  = 0x4005DFF8;


int main(void)
{

    clock();

    GPIOHBCTL_PORTF;
    RCGCGPIO_PORTF;


    //DETERMINE DIRECTION
#define  PIN1      2 //LED GREEN OUTPUT F3
#define  PIN2      3 // SW1 INPUT F4

   // *GPIODIR &= ~(1<<PIN2);
    GPIODIR_IN(PIN2);
    //*GPIODIR |= (1<<PIN1);
    GPIODIR_OUT(PIN1);
    //********************

    GPIOAFSEL_GPIO;

    GPIODR8R_8MA;

    GPIOD_EN;
    GPIO_PUR_EN (PIN2); //ENABLE PULL UP FOR SWITCH

    unsigned int value ;

    value =  *(GPIODATA);
    value = ~value; /* switch is low active; LED is high active */
    value = value >> 1; /* shift it right to display on green LED */
    *GPIODATA = value; /* put it on the green LED */




	return 0;
}
