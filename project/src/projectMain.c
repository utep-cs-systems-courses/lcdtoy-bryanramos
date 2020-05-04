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
    clearScreen(COLOR_BLACK);
    drawString5x7(10,30, "MENU", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(10,40, "S1. MARIO", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(10,50, "S2. LUIGI", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(10,60, "S3. PEACH", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(10,70, "S4. BOWSER", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(10,130, "ARCH 1 IS AWESOME", COLOR_WHITE, COLOR_BLACK);
    drawString5x7(80,140, ":) <3", COLOR_RED, COLOR_BLACK);    
    
    or_sr(0x18);    // CPU off, GIE on
}
