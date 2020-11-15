#include "display.h"

int lastCustomerIndex ;
bool newCustomer = 1;
bool blinkState = 1;
enum TEXT_ATTRIBUTES activeAttr;

void eventCheck() {

  int customerIndex;
  if (newCustomer) {
    do {
      customerIndex = chooseCustomer(customers, 6);
    } while (lastCustomerIndex == customerIndex);
    lastCustomerIndex = customerIndex;
    displayCustomer(customers, customerIndex);
    newCustomer = 0;
  }

  switch ((*messagePtr).textAttributes) {
    case SCROLL_ATTR: {
        lcd.scrollDisplayRight();
        (*messagePtr).textAttributes = NO_ATTR;
        break;
      }
    case STATIC_ATTR: {
        (*messagePtr).textAttributes = NO_ATTR;
        break;
      }
    case BLINK_ATTR: {
        if (blinkState) {
          lcd.clear();
          lcdPrint((*messagePtr).text);
        } else {
          lcd.clear();
        }
        (*messagePtr).textAttributes = NO_ATTR;
        break;
      }
    case FLARE_ATTR: {

        // Do Flare event, set global variables etc
        // Switch even to Scroll or other.
        activeAttr = SCROLL_ATTR;
        (*messagePtr).textAttributes = SCROLL_ATTR;

        //    (*messagePtr).textAttributes = NO_ATTR;
        break;

    }  case NO_ATTR: {
        break;
      }
  }
}


void showText(messageStruct *message) {

  messagePtr = message;
  activeAttr = message->textAttributes;
  //doEvent = message->textAttributes;
  lcdPrint((*messagePtr).text);
  Serial.println((*messagePtr).text);
}


void displayCustomer(customerStruct customers[], int customerIndex) {
  Serial.print("\nCustomer id: ");
  Serial.println(customerIndex);

  switch (customers[customerIndex].switchMethod) {

    case SWITCH_RANDOM: {

        int rnd = random(0, (customers[customerIndex].numberOfMessages));
        showText(&customers[customerIndex].messages[rnd]);
        break;
      }

    case SWITCH_ODD_EVEN_MINUTES: {

        if (minute(t) % 2 == 0) {
          showText(&customers[customerIndex].messages[0]);
        } else {
          showText(&customers[customerIndex].messages[1]);
        }
        break;
      }
    case SWITCH_DAY_NIGHT: {

        if (hour(t) >= 17 | hour(t) < 6) {
          showText(&customers[customerIndex].messages[0]);
        }
        else if (hour(t) > 17 | hour(t) >= 6) {

          showText(&customers[customerIndex].messages[1]);
        }
        break;
      }
    case SWITCH_BITMAP: {
        showText(&customers[customerIndex].messages[0]);
        break;
      }
  }
  return;
}
