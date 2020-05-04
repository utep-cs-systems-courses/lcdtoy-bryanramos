#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

void __interrupt_vec(PORT2_VECTOR) Port_2() {
    if (P2IFG & SWITCHES) {
        P2IFG &= ~SWITCHES;
        switch_interrupt_handler();
    }
}


void __interrupt_vec(WDT_VECTOR) WDT(){
      static char decisecond_count = 0;
  if(++decisecond_count == tempo){
    int repeat = 1;
    while(repeat <= 5){
      int cnt = 0;
      while(cnt < 20000){
	cnt++;
      }
      repeat++;
    }
    switch_interrupt_handler();
    decisecond_count = 0;
}
  state_advance();
  led_update();
  

}
