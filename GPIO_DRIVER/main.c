

#include "GPIO.h"
#include "clock.h"

#include "GPIO.c"





//#define REG volatile unsigned long int *
//
//
//
//REG  GPIODIR =  FB(OFF_GPIODIR);
//REG  GPIOAFSEL= FB(OFF_GPIOAFSEL);
//REG  GPIODR8R = FB(OFF_GPIODR8R);
//REG  GPIODEN=  FB(OFF_GPIODEN);
// REG GPIODATA  = 0x4005D008;
//
int main()
{
    clock();

    gpio_init( PORTF , AHB);

    gpio_mode (PORTF ,2, GPIOD_EN , GPIOAFSEL_GPIO   );

    pin_modes (PORTF,2 ,GPIODIR_OUT );

    driver_strength (PORTF,2 ,GPIODR8R_8MA );

    GPIOSET( PORTF ,2 , 1);
    int i;
    for (i=0 ; i<5000 ;i++)
    {
         //delay


    }

    GPIODIS( PORTF ,2 , 1);

////
////    GPIOHBCTL_PORTF;
////    RCGCGPIO_PORTF;
////
////    GPIODIR_OUT;
////    GPIOAFSEL_GPIO;
////    GPIODR8R_8MA;
////    GPIOD_EN;
////    *GPIODATA = (1<<1);
//
//


    return 0;
}
