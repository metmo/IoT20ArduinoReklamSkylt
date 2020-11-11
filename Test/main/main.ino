//#include <LiquidCrystal.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_GrayOLED.h>
//#include <Adafruit_SPITFT.h>
//#include <Adafruit_SPITFT_Macros.h>
//#include <gfxfont.h>
//#include <Adafruit_SSD1306.h>
//#include <splash.h>
//#include <arduino-timer.h>

#define NUMBER_OF_CUSTOMERS 6 //10



#include <stdlib.h>
#include <Arduino.h>
#include <string.h>

#include "customer.h"
#include "display.h"
#include "timer.h"

int timer1 = 0;
bool newCustomer = 0;
int lastCustomerIndex = 0;
customerStruct customers[NUMBER_OF_CUSTOMERS];

void setup()
{
  Serial.begin(9600);
  delay(600);

  setupTimer();
  populateCustomerStruct(customers, NUMBER_OF_CUSTOMERS);

}
void loop()
{

  if (newCustomer) {
    int customerIndex;
    do {
      customerIndex = chooseCustomer(customers, NUMBER_OF_CUSTOMERS);
    } while (lastCustomerIndex == customerIndex);
    lastCustomerIndex = customerIndex;
    Serial.print("\n\nCustomer index:");
    Serial.print(customerIndex);
    displayCustomer(customers, customerIndex);
    newCustomer = 0;
  }
}
