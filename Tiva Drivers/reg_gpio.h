
#ifndef REG_GPIO_H_
#define REG_GPIO_H_

#include "gpio_test.h"
#define REG volatile unsigned long int *


unsigned long int BASE;
#define B(offset) BASE+offset


// *****************************************OFFSETS OF REGISTERS******************************//

#define     OFF_GPIODIR           0x400
#define     OFF_GPIOAFSEL         0x420
#define     OFF_GPIODR2R          0x500
#define     OFF_GPIODR4R          0x504
#define     OFF_GPIODR8R          0x508
#define     OFF_GPIODEN           0x51C
#define     OFF_GPIOPUR           0x510
#define     OFF_GPIODATA          0x000
#define     OFF_GPIOPCTL          0x52C   //used in conjunction with the GPIOAFSEL
#define     OFF_GPIOAMSEL         0x528   //GPIO Analog Mode Select
#define     OFF_GPIOSLR           0x518   //Slew Rate Control Select
#define     OFF_GPIOPDR           0x514
#define     OFF_GPIOODR           0x50C

//*******************interuupt registers *********** //
#define     OFF_GPIOIS            0x404
#define     OFF_GPIOIBE           0x408
#define     OFF_GPIOIEV           0x40C
#define     OFF_GPIOIM            0x410
#define     OFF_GPIORIS           0x414



#define     A_AHB_BASE            0x40058000
#define     B_AHB_BASE            0x40059000
#define     C_AHB_BASE            0x4005A000
#define     D_AHB_BASE            0x4005B000
#define     E_AHB_BASE            0x4005C000
#define     F_AHB_BASE            0x4005D000

#define     A_APB_BASE            0x40004000
#define     B_APB_BASE            0x40005000
#define     C_APB_BASE            0x40006000
#define     D_APB_BASE            0x40007000
#define     E_APB_BASE            0x40024000
#define     F_APB_BASE            0x40025000




//***************************************************************************************************************************




#endif /* REG_GPIO_H_ */
