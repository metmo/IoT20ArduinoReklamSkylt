#include <stdlib.h>
#include <Arduino.h>
#include <string.h>
#include <TimeLib.h>
#include "customer.h"
#include "display.h"
#include "timer.h"
#include <avr/pgmspace.h>
#include <LiquidCrystal.h>
#include "lcd.h"

extern LiquidCrystal lcd;
extern enum TEXT_ATTRIBUTES activeAttr;
extern char text[50];
extern time_t t;


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
  Serial.print("\nCustomer id: ");
  Serial.print(customerIndex);

  switch (customers[customerIndex].switchMethod) {

    case SWITCH_RANDOM: {
        Serial.print("\nRANDOM ");
        int rnd = random(0, (customers[customerIndex].numberOfMessages + 1));
        Serial.print(rnd);
        
        showText(customers[customerIndex].messages[rnd]);
        Serial.print(customers[customerIndex].messages[rnd].text);
        break;
      }

    case SWITCH_ODD_EVEN_MINUTES: {
        Serial.print("\nODD/EVEN:");
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

      
        Serial.print(F("fiohfoirhfofoifhfoihfoirehoihfoiewhfoiehfoiehfoiehfoiehfoihfwoihfeoifhoifhweoihfeoifheoifhewoihfwoihf"));
        
   //     Serial.print("fiohfoirhfofoifhfoihfoirehoihfoiewhfoiehfoiehfoiehfoiehfoihfwoihfeoifhoifhweoihfeoifheoifhewoihfwoihf");


        
//        Serial.print("Time: ");
//        Serial.print(hour(t));
//        Serial.print(":");
//        Serial.print(minute(t));
//        Serial.print(":");
//        Serial.print(second(t));

        if (hour(t) >= 17 | hour(t) < 6) {
       //   Serial.print("\nNIGHT:");
          showText(customers[customerIndex].messages[0]);
      //    Serial.println(customers[customerIndex].messages[0].text);
        }
        else if (hour(t) > 17 | hour(t) >= 6) {
       //   Serial.print("\nDAY:");
          showText(customers[customerIndex].messages[1]);
       //   Serial.println(customers[customerIndex].messages[1].text);
        }
        break;
      }
    case SWITCH_BITMAP: {
    //    Serial.print("\nBITMAP:");
        showText(customers[customerIndex].messages[0]);
    //    Serial.println(customers[customerIndex].messages[0].text);
        break;
      }
  }
  return;
}
