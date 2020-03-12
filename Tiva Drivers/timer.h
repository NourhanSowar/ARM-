
#ifndef TIMER_H_
#define TIMER_H_

#include "reg_timer.h"

#define REG volatile unsigned long int *


typedef enum { Timer0 , Timer1 , Timer2 , Timer3 , Timer4 , Timer5 } timer_select ;
typedef enum { TimerA , TimerB } subtimer_select ;
typedef enum { normally , wide  }  timer_size;
typedef enum { concatenated_periodic , concatenated_rtc , individual } timer_config ;
typedef enum { oneshot , periodic , capture_mode }subtimer_mode ;
typedef enum {up , dowm} timer_dircetion ;


void TimerSelect (timer_select timer  , timer_size size);
void SubTimerDis ( subtimer_select sub_timer );
void SubTimerEn ( subtimer_select sub_timer );
void ConfigrationTimer( timer_config config_select);
void SubTimerAMode (subtimer_mode mode , timer_dircetion direction_select );
void SubTimerBMode (subtimer_mode mode  , timer_dircetion direction_select );
void InternalLoad (unsigned char start_value);
void InternalLoadB (unsigned char start_value);



#endif /* TIMER_H_ */
