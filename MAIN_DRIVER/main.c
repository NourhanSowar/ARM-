

/**
 * main.c
 */
#include "clock_test.h"
#include "gpio_test.h"


//#include "reg_test.h"





int main(void)

{

    clock();


gpio_init(PORTF,AHB );
port_bus (PORTF , AHB);

gpio_mode (PORTF , 1, GPIOD_EN , GPIOAFSEL_GPIO );
gpio_mode (PORTF , 4, GPIOD_EN , GPIOAFSEL_GPIO );

gpio_direction (PORTF ,   1 ,  GPIODIR_OUT ); //led red

gpio_direction (PORTF ,   4,  GPIODIR_IN ); // switch
//pull_up(PORTF, 4);



//led red is on F1 F1 pin no 1
//SWITCH F0,F4

driver_strength (PORTF,1 ,GPIODR8R_8MA );



unsigned int mask_sw =   GPIORead(PORTF, 4 );

//REG GPIODATA = B(OFF_GPIODATA+36);

  //  unsigned char reading ;
    //reading =  *(GPIODATA);


 mask_sw = mask_sw >> 2;
set_pin( PORTF,1,mask_sw);

//set_pin( PORTF,1,8);

//int i,j;
//for(i=0 ; i <3180 ; i++){
//
//    for (j=0 ; j<i ;j++)
//    {
//
//    }
//
//}

//clear_pin( PORTF,1 ,8);


    return 0;


}
