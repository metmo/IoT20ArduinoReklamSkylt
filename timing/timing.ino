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
<<<<<<< Updated upstream
=======
#include <arduino-timer.h>
auto timer = timer_create_default(); // create a timer with default settings

>>>>>>> Stashed changes

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arduino-timer.h>

<<<<<<< Updated upstream
auto timer = timer_create_default(); // create a timer with default settings

int customers = 3;

char harrysBilar()
{
  char kopBilReklam[][40] = {"Köp bil hos Harry", "Hederlige Harrys Bilar", "En god bilaffär (för Harry!)"};
  int randomNUm = random(0, 3);
  return Serial.print(randomNUm);
}

void FarmorAnkasPajerAB()
{
  char pajReklam[][40] = {"Köp paj hos Farmor Anka", "Skynda innan Mårten ätit alla pajer"};
}

void SvartePettersSvartbyggen()
{
  char svartByggeReklam[][40] = {"Låt Petter bygga åt dig", "Bygga svart? Ring Petter"};
}

bool print_message(void *)
{
  for (int i = 0 ; i < customers; i++)
  {
    Serial.print("print_message: Called at: ");
=======
char pajReklam[][40] = {"Köp paj hos Farmor Anka","Skynda innan Mårten ätit alla pajer"};
char svartByggeReklam[][40] = {"Låt Petter bygga åt dig","Bygga svart? Ring Petter"};
  

char customers[][100] = {pajReklam, svartByggeReklam};

bool print_message(void *)
{
  for (int i = 0 ; i < customers[random(0,2)]; i++)
  {
    
    Serial.print("print_message: %s  :Called at: ");
>>>>>>> Stashed changes
    Serial.println(millis());
    return true; // repeat? true
  }
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
<<<<<<< Updated upstream
void loop() {
=======
void loop() 
{
>>>>>>> Stashed changes
  timer.tick(); // tick the timer
}
