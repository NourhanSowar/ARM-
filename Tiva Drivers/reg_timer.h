/*
 * reg_timer.h
 *
 *  Created on: Mar 12, 2020
 *      Author: TARGET
 */


#ifndef REG_TIMER_H_
#define REG_TIMER_H_

#include "timer.h"

#define     OFF_GPTMCTL        0x00C  //ENABLE TIMER ITS THE FIRST STEP
#define     OFF_GPTMCFG        0x000
#define     OFF_GPTMTAMR       0x004  //  configrayion of tomer A
#define     OFF_GPTMTBMR       0x008  //      Configration of timerB
#define     OFF_GPTMTAILR      0x028
#define     OFF_GPTMTBILR      0x02C



#define     Timer0_base             0x40030000
#define     Timer1_base             0x40031000
#define     Timer2_base             0x40032000
#define     Timer3_base             0x40033000
#define     Timer4_base             0x40034000
#define     Timer5_base             0x40035000


#define     Timer0_wide_base          0x40036000
#define     Timer1_wide_base          0x40037000
#define     Timer2_wide_base          0x4004C000
#define     Timer3_wide_base          0x4004D000
#define     Timer4_wide_base          0x4004E000
#define     Timer5_wide_base          0x4004F000



unsigned long int BASE;
#define B(offset) BASE+offset


#endif /* REG_TIMER_H_ */
