


#define NUMBER_OF_CUSTOMERS 6

#include <stdlib.h>
#include <Arduino.h>
#include <string.h>
#include <TimeLib.h>
#include "customer.h"
#include "display.h"
#include "timer.h"
#include <avr/pgmspace.h>

bool newCustomer = 1;
int lastCustomerIndex = 0;
time_t t = now();

customerStruct customers[NUMBER_OF_CUSTOMERS];

void setup()
{
  Serial.begin(9600);
  setupTimer();

  setTime(16, 20, 30, 11, 1, 2020);
  Serial.print("Time: ");
  Serial.print(hour(t));
  Serial.print(":");
  Serial.print(minute(t));
  Serial.print(":");
  Serial.print(second(t));

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
