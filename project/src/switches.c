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
  
 if (!(p2val & switch1_state_down)) { // see state machine and led code for toggle red when button is pressed
    tempo = 15;
    song1();
    clearScreen(COLOR_RED);
    fillRectangle(30, 60, screenWidth/2, screenWidth/2, COLOR_WHITE);
    drawString5x7((screenWidth/3)+5,20, "MARIO", COLOR_WHITE, COLOR_RED);
    drawString5x7(25,30, "IS A PLUMBER", COLOR_WHITE, COLOR_RED);
    drawString5x7(15,40, "WHO LOVES PIZZA", COLOR_WHITE, COLOR_RED);
    switch_state_changed = 1;
  } else if (!(p2val & switch2_state_down)) { // see state machine assembly and led code for toggle green when button is pressed
    tempo = 30;
    song2();
    clearScreen(COLOR_GREEN);
    drawDiamondInsideSquare(50, 90, 30, COLOR_WHITE);
    drawString5x7(20,20, "LUIGI", COLOR_WHITE, COLOR_GREEN);
    drawString5x7(20,30, "IS MARIO'S", COLOR_WHITE, COLOR_GREEN);
    drawString5x7(20,40, "BROTHER", COLOR_WHITE, COLOR_GREEN);
    switch_state_changed = 2;
  } else if (!(p2val & switch3_state_down)) { // see state machine assembly and led code for toggle both when button is pressed
    tempo = 30;
    song3();
    clearScreen(COLOR_PINK);
    drawTriangle(90, COLOR_WHITE);
    drawString5x7(20,10, "PRINCESS", COLOR_WHITE, COLOR_PINK);
    drawString5x7(20,20, "PEACH", COLOR_WHITE, COLOR_PINK);
    drawString5x7(20,30, "IS THE", COLOR_WHITE, COLOR_PINK);
    drawString5x7(20,40, "PRINCESS", COLOR_WHITE, COLOR_PINK);
    drawString5x7(20,50, "OF MUSHROOM", COLOR_WHITE, COLOR_PINK);
    drawString5x7(20,60, "KINGDOM", COLOR_WHITE, COLOR_PINK);
    switch_state_changed = 3;
  } 
  else if (!(p2val & switch4_state_down)) { // see state machine assembly and led code for toggle both off when button is pressed
    tempo = 30;
    song4();
    clearScreen(COLOR_PURPLE);
    trapezoid(20, 90, COLOR_WHITE);
    drawString5x7(20,20, "BOWSER IS", COLOR_WHITE, COLOR_PURPLE);
    drawString5x7(20,30, "KING OF", COLOR_WHITE, COLOR_PURPLE);
    drawString5x7(20,40, "KOOPAS", COLOR_WHITE, COLOR_PURPLE);
    switch_state_changed = 4;
  } 
} 
