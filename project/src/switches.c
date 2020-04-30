#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

char switch_state_changed; // // depending on the state, used to change the lights 
char tempo; // to customize tempo of individual songs 

char switch1_state_down, switch2_state_down, switch3_state_down, switch4_state_down;

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  //update switch interrupt to detect changes from current button
  P2IES |= (p2val & SWITCHES); // if switch up, sense down
  P2IES &= (p2val | ~SWITCHES); // if switch down, sense up
  return p2val;
}

void switch_init(){ //setup switch
  P2REN |= SWITCHES; //enables resistors for switches
  P2IE = SWITCHES; //enable interrupts from switches
  P2OUT |= SWITCHES; //pull-ups for switches
  P2DIR &= ~SWITCHES; //set switches' bits for input
  switch_update_interrupt_sense();
}

void switch_interrupt_handler(){ 
  char p2val = switch_update_interrupt_sense();

  switch1_state_down = (p2val & SW1) ? 1 : 0;
  switch2_state_down = (p2val & SW2) ? 1 : 0;
  switch3_state_down = (p2val & SW3) ? 1 : 0;
  switch4_state_down = (p2val & SW4) ? 1 : 0;
  
  buzzer_set_period(0);
  if (!(p2val  & switch1_state_down)) { // see state machine and led code for toggle red when button is pressed
    tempo = 30;
    song1();
    drawString5x7(20,20, "mario", COLOR_GREEN, COLOR_RED);
    switch_state_changed = 1;
  } else if (!(p2val & switch2_state_down)) { // see state machine assembly and led code for toggle green when button is pressed
    tempo = 30;
    song2();
    drawString5x7(20,20, "luigi", COLOR_GREEN, COLOR_RED);
    switch_state_changed = 2;
  } else if (!(p2val & switch3_state_down)) { // see state machine assembly and led code for toggle both when button is pressed
    tempo = 30;
    song3();
    drawString5x7(20,20, "peach", COLOR_GREEN, COLOR_RED);
    switch_state_changed = 3;
  } 
  else if (!(p2val & switch4_state_down)) { // see state machine assembly and led code for toggle both off when button is pressed
    tempo = 30;
    song4();
    drawString5x7(20,20, "bowser", COLOR_GREEN, COLOR_RED);
    switch_state_changed = 4;
  }
} 
