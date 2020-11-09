#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"


void populateCustomerStruct(customerStruct customers[], int numberOfCustomers ) {

  customers[0].customerCost = 3000;
  customers[0].numberOfMessages = 2;
  customers[0].switchMethod = SWITCH_RANDOM;

  strcpy(customers[0].messages[0].text,"Message 1");
  customers[0].messages[0].textAttributes = SCROLL_ATTR;
  
  strcpy(customers[0].messages[1].text,"Message 2");
  customers[0].messages[1].textAttributes = STATIC_ATTR;
  
  strcpy(customers[0].messages[2].text,"Message 3");
  customers[0].messages[2].textAttributes = BLINK_ATTR;

}
