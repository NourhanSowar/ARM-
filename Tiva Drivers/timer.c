
#include "timer.h"

#include "reg_timer.h"



void TimerSelect (timer_select timer  , timer_size size)
{
    if (size == normally ){

        if(timer ==Timer0)

            BASE=Timer0_base;

        else if(timer ==Timer1)

            BASE=Timer1_base;

        else if(timer ==Timer2)

            BASE=Timer2_base;

        else if(timer ==Timer3)

            BASE=Timer3_base;

        else if(timer ==Timer4)

            BASE=Timer4_base;

        else if(timer ==Timer5)

            BASE=Timer5_base;
        }
    else if (size == wide){

        if(timer ==Timer0)

            BASE=Timer0_wide_base;

        else if(timer ==Timer1)

            BASE=Timer1_wide_base;

       else if(timer ==Timer2)

            BASE=Timer2_wide_base;

       else if(timer ==Timer3)

            BASE=Timer3_wide_base;

       else if(timer ==Timer4)

            BASE=Timer4_wide_base;

       else if(timer ==Timer5)

           BASE=Timer5_wide_base;
    }
}


void SubTimerDis ( subtimer_select sub_timer )
{
    REG GPTMCTL = B(OFF_GPTMCTL);

    if (sub_timer == TimerA )

        *GPTMCTL &=~(1<<0 );

    else if (sub_timer == TimerB )

        *GPTMCTL &=~(1<<8 );
}

void SubTimerEn ( subtimer_select sub_timer )
{
    REG GPTMCTL = B(OFF_GPTMCTL);

    if (sub_timer == TimerA )

        *GPTMCTL |=(1<<0 );

    else if (sub_timer == TimerB )

        *GPTMCTL |=(1<<8 );
}

void ConfigrationTimer( timer_config config_select)
{
    REG GPTMCFG = B(OFF_GPTMCFG);

    if ( config_select == concatenated_periodic)

            *GPTMCFG  &= ~(1<<0) | ~(1<<1) | ~(1<<2);      //for concatenated mode

    else if ( config_select == concatenated_rtc)
    {
            *GPTMCFG  &= ~(1<<0)  | ~(1<<2);      //for real time clock
            *GPTMCFG |= (1<<1);
    }
    else if ( config_select == individual)
    {
            *GPTMCFG  &= ~(1<<0)  | ~(1<<1);      //for individual mode
            *GPTMCFG |= (1<<2);
    }
}

void SubTimerAMode (subtimer_mode mode , timer_dircetion direction_select )
{
    REG GPTMTAMR = B(OFF_GPTMTAMR);

    switch (mode)
    {
    case oneshot :
        *GPTMTAMR |=(1<< 0 );  //one shot mode
        *GPTMTAMR &=~(1<<1  );
        break;

    case periodic:
        *GPTMTAMR &=~(1<< 0 );  //one periodic mode
        *GPTMTAMR |=(1<<1  );
        break;

    case capture_mode :
        *GPTMTAMR |=(1<< 0 );  //capture mode
        *GPTMTAMR |=(1<<1 );
        break ;
    }
    if (direction_select == up)
        *GPTMTAMR |=(1<<4 );
    else if (direction_select == dowm)
            *GPTMTAMR &=~(1<<4 );
}
void SubTimerBMode (subtimer_mode mode  , timer_dircetion direction_select )
{
    REG GPTMTBMR = B(OFF_GPTMTBMR);

    switch (mode){
    case oneshot :
        *GPTMTBMR |=(1<< 0 );  //one shot mode
        *GPTMTBMR &=~(1<<1  );
        break;

    case periodic:
        *GPTMTBMR &=~(1<< 0 );  //one periodic mode
        *GPTMTBMR |=(1<<1  );
        break;

    case capture_mode :
        *GPTMTBMR |=(1<< 0 );  //capture mode
        *GPTMTBMR |=(1<<1 );
        break ;
    }
    if (direction_select == up)
           *GPTMTBMR |=(1<<4 );
    else if (direction_select == dowm)
           *GPTMTBMR &=~(1<<4 );
}
void InternalLoadA (unsigned char start_value)
{
    REG GPTMTAILR = B(OFF_GPTMTAILR);
    *GPTMTAILR = start_value ;
}
void InternalLoadB (unsigned char start_value)
{
    REG GPTMTBILR = B(OFF_GPTMTBILR);
    *GPTMTBILR = start_value ;
}


