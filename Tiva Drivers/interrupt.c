


#include <interrupt.h>


#define INT_REG volatile unsigned long int *
unsigned char offset_int ;


void INT_Enable(unsigned int ID)
{

      offset_int =   100+( (ID/32)*4) ;  // EN0
      INT_REG  EN =   ADD( offset_int );
      *EN |= (1<< (ID%32 ) );

}
void INT_Disable(unsigned int ID)
{
    offset_int =   180+( (ID/32)*4) ;
    INT_REG  DIS=   ADD( offset_int );
    *DIS &= ~(1<< (ID%32 ) );
}
void Set_Pending(unsigned int ID)
{
    offset_int =   200+( (ID/32)*4) ;
    INT_REG  SET=   ADD( offset_int );
    *SET &= ~(1<< (ID%32 ) );
}
void Clr_Pending(unsigned int ID)
{
    offset_int =   280+( (ID/32)*4) ;
    INT_REG  CLR=   ADD( offset_int );
    *CLR &= ~(1<< (ID%32 ) );
}
void ActiveState(unsigned int ID)
{
    offset_int =   300+( (ID/32)*4) ;
    INT_REG  ACT=   ADD( offset_int );
    *ACT &= ~(1<< (ID%32 ) );
}

void SetPriority(unsigned int ID)
{
    offset_int =   400+( (ID/4)*4 );
    INT_REG  PRI=   ADD( offset_int );
    *PRI &= ~(1<< (((ID%4 )*8)+5) );
}



 //****************** ISR functions ************************//
void isr_portA(void)
{
    registered_interrupt_portA;
}


void isr_portB(void)
{
  registered_interrupt_portB;
}

void isr_portC(void)
{
   registered_interrupt_portC;
}

void isr_portD(void)
{
   registered_interrupt_portD;
}

void isr_portE(void)
{
   registered_interrupt_portE;
}
void isr_portF(void)
{
   registered_interrupt_portF; // pointer to function
}

//****************


void Int_Reg(int interrupt_ID, void (*interrupt_to_register)(void))
{
    if (interrupt_ID == 30)
        registered_interrupt_portF = interrupt_to_register;
}
