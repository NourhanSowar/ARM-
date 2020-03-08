/*
 * timer.h
 *
 *  Created on: Mar 8, 2020
 *      Author: TARGET
 */

#ifndef TIMER_H_
#define TIMER_H_


#define     OFF_GPTMCTL        0x00C  //ENABLE TIMER ITS THE FIRST STEP
#define     OFF_GPTMCFG        0x000
#define     OFF_GPTMTAMR       0x004  //  configrayion of tomer A
#define     OFF_GPTMTBMR       0x008  //      Configration of timerB
#define     OFF_GPTMTAILR      0x028
#define     OFF_GPTMTBILR      0x02C



#define     Timer0_1632         0x40030000
#define     Timer1_1632         0x40031000
#define     Timer2_1632         0x40032000
#define     Timer3_1632         0x40033000
#define     Timer4_1632         0x40034000
#define     Timer5_1632         0x40035000


#define     Timer0_3264         0x40036000
#define     Timer1_3264         0x40037000
#define     Timer2_3264         0x4004C000
#define     Timer3_3264         0x4004D000
#define     Timer4_3264         0x4004E000
#define     Timer5_3264         0x4004F000





#endif /* TIMER_H_ */
