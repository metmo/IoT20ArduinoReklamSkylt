#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"
#include "display.h"
#include "timer.h"
#include <avr/pgmspace.h>



void showText(messageStruct message) {

  switch (message.textAttributes) {
    case SCROLL_ATTR: {
        Serial.print("\nScrolling: ");
        Serial.print(message.text);
        break;
      }
    case STATIC_ATTR: {
        Serial.print("\nStatic: ");
        Serial.print(message.text);
        break;
      }
    case BLINK_ATTR: {
        Serial.print("\nBlinking: ");
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

Serial.println("displayCustomer");

  switch (customers[customerIndex].switchMethod) {

    case SWITCH_RANDOM: {
        Serial.print("\nRANDOM");
        unsigned char rnd = random(0, customers[customerIndex].numberOfMessages);
        showText(customers[customerIndex].messages[rnd]);
        break;
      }

    case SWITCH_ODD_EVEN_MINUTES: {
        Serial.print("\nODD/EVEN");

#define MINUTE 1

        if ((MINUTE % 2) == 0) {
          showText(customers[customerIndex].messages[0]);
        }
        else {
          showText(customers[customerIndex].messages[1]);
        }
        break;
      }

    case SWITCH_DAY_NIGHT: {
        Serial.print("\nDAY/NIGHT");
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
