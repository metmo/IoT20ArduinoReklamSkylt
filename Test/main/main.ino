//#include <LiquidCrystal.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_GrayOLED.h>
//#include <Adafruit_SPITFT.h>
//#include <Adafruit_SPITFT_Macros.h>
//#include <gfxfont.h>
//#include <Adafruit_SSD1306.h>
//#include <splash.h>
//#include <arduino-timer.h>


#include <stdlib.h>
#include <string.h>

auto timer = timer_create_default(); // create a timer with default settings
#include "customer.h"
#include "display.h"


customerStruct customers[NUMBER_OF_CUSTOMERS];

bool printaReklamen( void* )
{
char buffer[40];
  
 
    
 // Serial.println(chooseCustomer(customers,NUMBER_OF_CUSTOMERS));
  Serial.println(customers[chooseCustomer(customers,NUMBER_OF_CUSTOMERS)].messages[random(0,2)].text);
  return true;
}

//*****************************************************************/
//                      SETUP INITIALIZATION
//*****************************************************************/
void setup() 
{

  Serial.begin(9600);
  
  populateCustomerStruct(customers, NUMBER_OF_CUSTOMERS);

  
  
  randomSeed(analogRead(0));
  // call the_message function every 5000 millis
  timer.every(200, printaReklamen);
}
//*****************************************************************/
//                           LOOP CRAP
//*****************************************************************/
void loop() 
{
  timer.tick(); // tick the timer
  //Serial.println(chooseCustomer(customers,NUMBER_OF_CUSTOMERS));
//delay(1);
}
