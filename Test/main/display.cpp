#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"
#include "display.h"
#include "timer.h"
#include "lcd.h"
#include <avr/pgmspace.h>
#include <LiquidCrystal.h>

extern LiquidCrystal lcd;

void showText(messageStruct message) {

  switch (message.textAttributes) {
    case SCROLL_ATTR: {
        Serial.print("\nScrolling: ");
        Serial.print(message.text);
        lcd.setCursor(0,0);
        lcd.print(message.text);

        break;
      }
    case STATIC_ATTR: {
        Serial.print("\nStatic: ");
        Serial.print(message.text);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(message.text);
        break;
      }
    case BLINK_ATTR: {
        Serial.print("\nBlinking: ");
        lcd.clear();
        Serial.print(message.text);
        break;
      }
    case FLARE_ATTR: {
        Serial.print("\nFlashy: ");
        Serial.print(message.text);
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
