//#include <LiquidCrystal.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_GrayOLED.h>
//#include <Adafruit_SPITFT.h>
//#include <Adafruit_SPITFT_Macros.h>
//#include <gfxfont.h>
//#include <Adafruit_SSD1306.h>
//#include <splash.h>
//#include <arduino-timer.h>


#define NUMBER_OF_CUSTOMERS 10 //10

#include <stdlib.h>
#include <Arduino.h>
#include <string.h>


#include "customer.h"
#include "display.h"
#include "timer.h"

void setup()
{

  Serial.begin(9600);
  delay(600);
  
  customerStruct customers[NUMBER_OF_CUSTOMERS];
  
  messageStruct message[3];

  strcpy(message[0].text,"hej hej hej");
  message[0].textAttributes = BLINK_ATTR;
   
  strcpy(message[1].text,"hopp hopp hopp");
  message[1].textAttributes = BLINK_ATTR;

  customers[0] = addCustomer(SWITCH_RANDOM, 2, 3000, message);

  Serial.print(customers[0].messages[0].text);
  Serial.print(customers[0].messages[1].text);

 // populateCustomerStruct(customers, NUMBER_OF_CUSTOMERS);

}
void loop()
{


}
