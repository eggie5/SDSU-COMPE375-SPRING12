// main.c
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

int count = 366;
int dummy;

#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void Timer_Overflow_ISR(void){
  if( count > 0) {
    count--;
  }else {
    count = 266;
    PORTB ^= 0x01;
  }
  dummy = TCNT; 
}
void main(void) {  
    EnableInterrupts;
  for(; {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}