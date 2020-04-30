#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

int main() {
    configureClocks();
    switch_init();
    buzzer_init();
    led_init();
    enableWDTInterrupts();
    
    lcd_init();
    u_char width = screenWidth, height = screenHeight;
    clearScreen(COLOR_BLUE);
    
    or_sr(0x18);    // CPU off, GIE on
}
