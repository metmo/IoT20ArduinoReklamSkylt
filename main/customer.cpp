#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"


void populateCustomerStruct(customerStruct customers[], int numberOfCustomers ) {

  customers[0].customerCost = 1000;

  customers[1].customerCost = 2000;
  customers[2].customerCost = 500;
  customers[3].customerCost = 20000;
  customers[4].customerCost = 3000;
  customers[5].customerCost = 5000;
  customers[6].customerCost = 7000;
  customers[7].customerCost = 3000;
  customers[8].customerCost = 5000;
  customers[9].customerCost = 7000;


  customers[0].numberOfMessages = 2;
  customers[0].switchMethod = SWITCH_RANDOM;

  strcpy(customers[0].messages[0].text, "Message 1");
  customers[0].messages[0].textAttributes = SCROLL_ATTR;

  strcpy(customers[0].messages[1].text, "Message 2");
  customers[0].messages[1].textAttributes = STATIC_ATTR;

  strcpy(customers[0].messages[2].text, "Message 3");
  customers[0].messages[2].textAttributes = BLINK_ATTR;

  return;
}

int chooseCustomer(customerStruct customers[], int numberOfCustomers) {
  long int totalSum = 0;
  for (int i = 0; i < numberOfCustomers; i++) {
    totalSum += customers[i].customerCost;
  }
  long int randomNumber = random(0, totalSum);
  totalSum = 0;
  for (int i = 0; i < numberOfCustomers; i++) {
    totalSum += customers[i].customerCost;
    if (randomNumber <= totalSum) {
      return i;
    }
  }
  return 0;
}
