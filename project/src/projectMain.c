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
    drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);
    fillRectangle(30,30, 60, 60, COLOR_ORANGE);
    or_sr(0x18);    // CPU off, GIE on
}
