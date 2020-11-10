#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"
#include "display.h"


void displayCustomer(customerStruct customers[], int numberOfCustomers, int customerIndex, bool newCustomer) {

  if (newCustomer) {
    switch (customers[customerIndex].switchMethod) {
      case SWITCH_RANDOM: {

          // Här ska message väljas random


          break;
        }
      case SWITCH_ODD_EVEN_MINUTES: {


          // Här ska message väljas beroende på jämn/ojämn minut


          break;
        }
      case SWITCH_DAY_NIGHT: {

          //Här ska meddelande väljas beroende på klockslag 17-06;


          break;
        }
    }
  }
  newCustomer = 0;
  return;
}
