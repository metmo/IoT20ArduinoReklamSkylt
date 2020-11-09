//*****************************************************************/
//                       DISPLAY SSD1306
//*****************************************************************/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


//*****************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arduino-timer.h>

auto timer = timer_create_default(); // create a timer with default settings


bool print_message(void *) {
  Serial.print("print_message: Called at: ");
  Serial.println(millis());
  return true; // repeat? true
}
//*****************************************************************/
//                      SETUP INITIALIZATION
//*****************************************************************/
void setup() {
  Serial.begin(9600);

  // call the print_message function every 20000 millis (20 second)
  timer.every(20000, print_message);
}
//*****************************************************************/
//                           LOOP CRAP
//*****************************************************************/
void loop() {
  timer.tick(); // tick the timer
}
