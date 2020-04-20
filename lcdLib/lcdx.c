/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);
  
  int j;
  
  // generate a triangle
  for (j = 0; j < 15; j++) {
      drawPixel(0, j, COLOR_GREEN);
      drawPixel(j, j, COLOR_GREEN);
      drawPixel(j, 15, COLOR_GREEN);
  }
}
 
