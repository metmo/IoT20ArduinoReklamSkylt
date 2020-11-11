


#define NUMBER_OF_CUSTOMERS 6


#include <stdlib.h>
#include <Arduino.h>
#include <string.h>

#include "customer.h"
#include "display.h"
#include "timer.h"
#include <avr/pgmspace.h>

bool newCustomer = 1;
int lastCustomerIndex = 0;

customerStruct customers[NUMBER_OF_CUSTOMERS];

void setup()
{
  setupTimer();
  Serial.begin(9600);

  storeData();

  populateCustomerStruct(customers, NUMBER_OF_CUSTOMERS);
}
void loop()
{
  if (newCustomer) {
    int customerIndex;
    do {
      customerIndex = chooseCustomer(customers, NUMBER_OF_CUSTOMERS);
    } while (lastCustomerIndex == customerIndex);
    lastCustomerIndex = customerIndex;
    Serial.print("\n\nCustomer index:");
    Serial.print(customerIndex);
    displayCustomer(customers, customerIndex);
    newCustomer = 0;
  }
}
