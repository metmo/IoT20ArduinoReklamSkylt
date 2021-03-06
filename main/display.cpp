#include <Arduino.h>
#include <TimeLib.h>
#include "customer.h"
#include "display.h"
#include "timer.h"
#include <LiquidCrystal.h>
#include "lcd.h"

extern LiquidCrystal lcd;
extern enum TEXT_ATTRIBUTES activeAttr;
extern enum TEXT_ATTRIBUTES doEvent;
extern char text[50];
extern time_t t;
extern bool blinkState;

void eventCheck() {
  switch (doEvent) {
    case SCROLL_ATTR: {
        lcd.scrollDisplayRight();
        doEvent = NO_ATTR;
        break;
      }
    case STATIC_ATTR: {
        doEvent = NO_ATTR;
        break;
      }
    case BLINK_ATTR: {
        if (blinkState) {
          lcd.clear();
          lcdPrint(text);
        } else {
          lcd.clear();
        }
        doEvent = NO_ATTR;
        break;
      }
    case FLARE_ATTR: {

      // Do Flare event, set global variables etc
      // Switch even to Scroll or other.
      activeAttr = SCROLL_ATTR;
      doEvent = SCROLL_ATTR;
      
    //    doEvent = NO_ATTR;
        break;

    }  case NO_ATTR: {
        break;
      }
  }
}


void showText(messageStruct message) {
  strcpy(text, message.text);
  lcd.clear();
  activeAttr = message.textAttributes;
  doEvent = message.textAttributes;
  lcdPrint(text);
}


void displayCustomer(customerStruct customers[], int customerIndex) {
  Serial.print("\nCustomer id: ");
  Serial.print(customerIndex);

  switch (customers[customerIndex].switchMethod) {

    case SWITCH_RANDOM: {

        int rnd = random(0, (customers[customerIndex].numberOfMessages));


        showText(customers[customerIndex].messages[rnd]);
        Serial.print(customers[customerIndex].messages[rnd].text);
        break;
      }

    case SWITCH_ODD_EVEN_MINUTES: {

        if (minute(t) % 2 == 0) {
          showText(customers[customerIndex].messages[0]);
          Serial.print(customers[customerIndex].messages[0].text);
        } else {
          showText(customers[customerIndex].messages[1]);
          Serial.print(customers[customerIndex].messages[1].text);
        }
        break;
      }
    case SWITCH_DAY_NIGHT: {

        if (hour(t) >= 17 | hour(t) < 6) {
          showText(customers[customerIndex].messages[0]);
          Serial.println(customers[customerIndex].messages[0].text);
        }
        else if (hour(t) > 17 | hour(t) >= 6) {

          showText(customers[customerIndex].messages[1]);
          Serial.println(customers[customerIndex].messages[1].text);
        }
        break;
      }
    case SWITCH_BITMAP: {
        showText(customers[customerIndex].messages[0]);
        Serial.println(customers[customerIndex].messages[0].text);
        break;
      }
  }
  return;
}
