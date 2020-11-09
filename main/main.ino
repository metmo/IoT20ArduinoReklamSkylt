
#include <LiquidCrystal.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <stdlib.h>

#include "customer.h"


customerStruct customers[NUMBER_OF_CUSTOMERS];


void setup() {
  populateCustomerStruct(customers, NUMBER_OF_CUSTOMERS);

  Serial.begin(9600);
  delay(1);

}

void loop() {
  
  Serial.println(customers[0].messages[0].text);
  Serial.println(customers[0].messages[1].text);
  Serial.println(customers[0].messages[2].text);

}
