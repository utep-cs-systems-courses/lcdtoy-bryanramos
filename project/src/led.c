#include <msp430.h>
#include "led.h"
#include "switches.h"

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_changed = 1;
  led_update();
}

void led_update(){
  if(led_changed){
    char ledFlags = 0; //by default, no LEDs on

    ledFlags = redVal[red_on] | greenVal[green_on];
    
    P1OUT &= (0xff ^ LEDS) | ledFlags; //clear bits for off leds
    P1OUT |= ledFlags; //set bits for on leds
    led_changed = 0;
  }
}

void switch_lights() {
    if (green_on != green_on2 || red_on != red_on2) {
        red_on = red_on2;
        green_on = green_on2;
        led_changed = 1;
    }
    if (green_on == green_on2 && red_on == red_on2) {
        red_on = red_on2;
        green_on = green_on2;
        led_changed = 1;
    }
}

void toggle_red() {
    green_on2 = 0;
    red_on2 = 1;
    switch_lights();
}

void toggle_green() {
    green_on2 = 1;
    red_on2 = 0;
    switch_lights();
}

void toggle_both() {
    green_on2 = 1;
    red_on2 = 1;
    switch_lights();
}

void toggle_both_off() {
    green_on2 = 0;
    red_on2 = 0;
    switch_lights();
}
