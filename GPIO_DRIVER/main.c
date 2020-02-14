

#include "GPIO.h"
#include "clock.h"





#define REG volatile unsigned long int *



REG  GPIODIR =  FB(OFF_GPIODIR);
REG  GPIOAFSEL= FB(OFF_GPIOAFSEL);
REG  GPIODR8R = FB(OFF_GPIODR8R);
REG  GPIODEN=  FB(OFF_GPIODEN);
 REG GPIODATA  = 0x4005D008;

int main()
{
clock();

    GPIOHBCTL_PORTF;
    RCGCGPIO_PORTF;

    GPIODIR_OUT;
    GPIOAFSEL_GPIO;
    GPIODR8R_8MA;
    GPIOD_EN;
    *GPIODATA = (1<<1);


    return 0;
}
