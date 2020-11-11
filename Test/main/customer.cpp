#include <stdlib.h>
#include <Arduino.h>
#include <stdarg.h>
#include "customer.h"
#include "display.h"


customerStruct addCustomer(SWITCH_METHOD switchMethod, short numberOfMessages, unsigned int customerCost, messageStruct messages[]) {

  customerStruct customer;
  customer.customerCost = customerCost;
  customer.numberOfMessages = numberOfMessages;
  customer.switchMethod = switchMethod;

  for (int i = 0; i < numberOfMessages; i++) {
    strcpy(customer.messages[i].text, messages[i].text);
    customer.messages[i].textAttributes = messages[i].textAttributes;
  }
  return customer;
}


void populateCustomerStruct(customerStruct customers[], int numberOfCustomers) {

  messageStruct message[3];

  strcpy(message[0].text, "Köp bil hos Harry");
  message[0].textAttributes = SCROLL_ATTR;
  strcpy(message[1].text, "En god bilaffär(för Harry!)");
  message[1].textAttributes = STATIC_ATTR;
  strcpy(message[2].text, "Hederlige Harrys Bilar");
  message[2].textAttributes = BLINK_ATTR;
  customers[0] = addCustomer(SWITCH_RANDOM, 3, 5000, message);

  strcpy(message[0].text, "Köp paj hos Farmor Anka");
  message[0].textAttributes = SCROLL_ATTR;
  strcpy(message[1].text, "Skynda innan Mårten ätit alla pajer");
  message[1].textAttributes = STATIC_ATTR;
  customers[1] = addCustomer(SWITCH_RANDOM, 2, 3000, message);

  strcpy(message[0].text, "Låt Petter Bygga åt dig");
  message[0].textAttributes = SCROLL_ATTR;
  strcpy(message[1].text, "Bygga svart? Ring Petter");
  message[1].textAttributes = STATIC_ATTR;
  customers[2] = addCustomer(SWITCH_ODD_EVEN_MINUTES, 2, 1500, message);

  
  strcpy(message[0].text, "Mysterier? Ring Långben");
  message[0].textAttributes = SCROLL_ATTR;
  strcpy(message[1].text, "Långben fixar biffen");
  message[1].textAttributes = STATIC_ATTR;
  customers[3] = addCustomer(SWITCH_ODD_EVEN_MINUTES, 2, 4000, message);
//
//  strcpy(message[0].text, "Mysterier? Ring Långben");
//  message[0].textAttributes = STATIC_ATTR;
//  strcpy(message[1].text, "Långben fixar biffen");
//  message[1].textAttributes = STATIC_ATTR;
//  customers[3] = addCustomer(SWITCH_DAY_NIGHT, 2, 4000, message);

  strcpy(message[0].text, "Synas här? IOT:s Reklambyrå");
  message[0].textAttributes = STATIC_ATTR;
  customers[4] = addCustomer(SWITCH_BITMAP, 1, 1000, message);

  strcpy(message[0].text, "T-Röd - för dig som tänkt klart");
  message[0].textAttributes = FLARE_ATTR;
  strcpy(message[1].text, "Claes Månsson - om flickan själv får välja");
  message[1].textAttributes = FLARE_ATTR;
  customers[5] = addCustomer(SWITCH_RANDOM, 2, 6000, message);

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
