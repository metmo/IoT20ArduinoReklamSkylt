#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"
#include "display.h"
#include "timer.h"


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


void displayCustomer(customerStruct customers[], int numberOfCustomers, int customerIndex) {


    switch (customers[customerIndex].switchMethod) {

      case SWITCH_RANDOM: {
          unsigned char rnd = random(0, customers[customerIndex].numberOfMessages);
          showText(customers[customerIndex].messages[rnd]);
          break;
        }

      case SWITCH_ODD_EVEN_MINUTES: {

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

#define TIME 1800

          if ((TIME > 1700 ) && ( TIME < 2200)) {
          showText(customers[customerIndex].messages[0]);
          }
          else {
          showText(customers[customerIndex].messages[1]);
          }
          break;
        }
    }
  return;
}
