#include <stdlib.h>
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "customer.h"
#include "display.h"
#include "timer.h"
#include "lcd.h"
#include <avr/pgmspace.h>

extern LiquidCrystal lcd;
extern enum TEXT_ATTRIBUTES activeAttr;
extern char text[50];


void showText(messageStruct message) {
  
   strcpy(text, message.text);
  
  switch (message.textAttributes) {
    case SCROLL_ATTR: {
        activeAttr = SCROLL_ATTR;
        lcd.clear();
        lcdPrint(text);
        break;
      }
    case STATIC_ATTR: {
        activeAttr = STATIC_ATTR;
        lcd.clear();
        lcdPrint(text);
        break;
      }
    case BLINK_ATTR: {
        activeAttr = BLINK_ATTR;
        lcd.clear();
        lcdPrint(text);
        break;
      }
    case FLARE_ATTR: {
        activeAttr = FLARE_ATTR;
        lcd.clear();
        lcdPrint(text);
        break;
      }
  }
}


void displayCustomer(customerStruct customers[], int customerIndex) {

  switch (customers[customerIndex].switchMethod) {

    case SWITCH_RANDOM: {
        Serial.print("\nRANDOM ");
        unsigned char rnd = random(0, customers[customerIndex].numberOfMessages);
        Serial.print(rnd);
        showText(customers[customerIndex].messages[rnd]);
        break;
      }

    case SWITCH_ODD_EVEN_MINUTES: {
        Serial.print("\nODD/EVEN:");

        showText(customers[customerIndex].messages[0]);
        showText(customers[customerIndex].messages[1]);
        break;
      }
    case SWITCH_DAY_NIGHT: {
        Serial.print("\nDAY/NIGHT:");
        showText(customers[customerIndex].messages[0]);
        showText(customers[customerIndex].messages[1]);

        break;
      }
    case SWITCH_BITMAP: {
        Serial.print("\nBITMAP:");
        showText(customers[customerIndex].messages[0]);
        break;
      }
  }
  return;
}
