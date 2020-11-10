#include <LiquidCrystal.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <stdlib.h>
#include <arduino-timer.h>
#include <string.h>

auto timer = timer_create_default(); // create a timer with default settings
#include "customer.h"

int previousRand;

customerStruct customers[NUMBER_OF_CUSTOMERS];


int nonConsRandom()
{
  int newRand = random(0,2);
  while (previousRand == newRand);
  {
    newRand = random(0,3);
  }
  previousRand = newRand;
  return newRand;
}

bool printaReklamen( void* ,int newRandom)
{
  char buffer[40];
  int currentCustomer = chooseCustomer(customers, NUMBER_OF_CUSTOMERS);
  
  
  
  // Serial.println(chooseCustomer(customers,NUMBER_OF_CUSTOMERS));
  Serial.println(customers[currentCustomer].messages[newRandom].text);
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
  timer.every(5000, printaReklamen);
}
//*****************************************************************/
//                           LOOP CRAP
//*****************************************************************/
void loop()
{
  timer.tick(); // tick the timer
  int newRandom = nonConsRandom();
  
  //Serial.println(chooseCustomer(customers,NUMBER_OF_CUSTOMERS));
  //delay(1);
}
