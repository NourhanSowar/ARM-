

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define BASE_INTERRUPT  0xE000E

#define ADD( offset)    BASE_INTERRUPT+offset



typedef enum
{
   GPIOPortA ,  GPIOPortB ,  GPIOPortC ,  GPIOPortD ,  GPIOPortE
 , Timer0_A=19 , Timer0_B, Timer1_A , Timer1_B , Timer2_A , Timer2_B
 , AnalogComparator0 , AnalogComparator1 , AnalogComparator_2 , GPIOPortF=30
 , Timer3_A=35, Timer3_B=36 , PWM0Generator3 =45, ADC1Sequence0 = 48, ADC1Sequence_1,
 ADC1Sequence_2, ADC1Sequence_3, Timer4SubtimerA=70, Timer4_SubtimerB, Timer5_A=92,Timer5_B,
 WideTimer0_A, WideTimer0_B, WideTimer1_A, WideTimer1_B, WideTimer2_A, WideTimer2_B, WideTimer3_A,
 WideTimer3_B, WideTimer4_A, WideTimer4_B, WideTimer5_A, WideTimer5_B
 , PWM1Generator_0=134, PWM1Generator_1, PWM1Generator_2, PWM1Generator_3, PWM1Fault
}Interruppt_ID;


void InDis(unsigned int ID);
void InEn(unsigned int  ID);


// ****************ISR*****************
void (*registered_interrupt_portA) (void);
void (*registered_interrupt_portB) (void);
void (*registered_interrupt_portC) (void);
void (*registered_interrupt_portD) (void);
void (*registered_interrupt_portE) (void);
void (*registered_interrupt_portF) (void);


void isr_portA(void);
void isr_portB(void);
void isr_portC(void);
void isr_portD(void);
void isr_portE(void);
void isr_portF(void);

void isr_timer0_A(void);
void isr_timer1_A(void);
void isr_timer2_A(void);
void isr_timer3_A(void);
void isr_timer4_A(void);
void isr_timer5_A(void);

void isr_timer0_B(void);
void isr_timer1_B(void);
void isr_timer2_B(void);
void isr_timer3_B(void);
void isr_timer4_B(void);
void isr_timer5_B(void);


void isr_timerWide0_B(void);
void isr_timerWide1_B(void);
void isr_timerWide2_B(void);
void isr_timerWide3_B(void);
void isr_timerWide4_B(void);
void isr_timerWide5_B(void);



void isr_timerWide0_A(void);
void isr_timerWide1_A(void);
void isr_timerWide2_A(void);
void isr_timerWide3_A(void);
void isr_timerWide4_A(void);
void isr_timerWide5_A(void);



#endif /* INTERRUPT_H_ */




