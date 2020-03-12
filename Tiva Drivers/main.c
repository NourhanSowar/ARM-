

/**
 * main.c
 */
#include "clock_test.h"
//
#include "timer.h"

int main(void)
{
    clock_timer1632 (Timer0 );

    TimerSelect (Timer0  , normally);

    SubTimerDis ( TimerA);

    ConfigrationTimer( concatenated_periodic);

    SubTimerAMode (periodic , up);

    InternalLoad (0XFFFFFF);

    SubTimerEn ( TimerA);

	return 0;
}
