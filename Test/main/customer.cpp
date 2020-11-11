#include <stdlib.h>
#include <Arduino.h>
#include <stdarg.h>
#include "customer.h"
#include "display.h"
#include <avr/pgmspace.h>

void storeData() {

  const char line1[] PROGMEM = "Everyone lost a hero";
  const char line2[] PROGMEM = "the day Harambe";
  const char line3[] PROGMEM = "died.";
  const char line4[] PROGMEM = "";
  const char line5[] PROGMEM = "Some thought it was";
  const char line6[] PROGMEM = "unfair.";
  const char line7[] PROGMEM = "Others took action!";
  const char line8[] PROGMEM = "In a far corner of";
  const char line9[] PROGMEM = "the world a plan was";
  const char line10[] PROGMEM = "hatched to enable...";

  const char * const textData[] PROGMEM =
  {
    line1,
    line2,
    line3,
    line4,
    line5,
    line6,
    line7,
    line8,
    line9,
    line10
  };

  return;
}



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

  Serial.println("Populating");

  strcpy(message[0].text, "TEXT1");
  message[0].textAttributes = SCROLL_ATTR;
  strcpy(message[1].text, "TEXT2");
  message[1].textAttributes = STATIC_ATTR;
  strcpy(message[2].text, "TEXT3");
  message[2].textAttributes = BLINK_ATTR;
  customers[0] = addCustomer(SWITCH_RANDOM, 2, 5000, message);

  strcpy(message[0].text, "TEXT1");
  message[0].textAttributes = SCROLL_ATTR;
  strcpy(message[1].text, "TEXT2");
  message[1].textAttributes = STATIC_ATTR;
  customers[1] = addCustomer(SWITCH_RANDOM, 1, 3000, message);

  strcpy(message[0].text, "TEXT1");
  message[0].textAttributes = SCROLL_ATTR;
  strcpy(message[1].text, "TEXT2");
  message[1].textAttributes = STATIC_ATTR;
  customers[2] = addCustomer(SWITCH_ODD_EVEN_MINUTES, 1, 1500, message);


  strcpy(message[0].text, "TEXT1");
  message[0].textAttributes = SCROLL_ATTR;
  strcpy(message[1].text, "TEXT2");
  message[1].textAttributes = STATIC_ATTR;
  customers[3] = addCustomer(SWITCH_ODD_EVEN_MINUTES, 1, 4000, message);


  strcpy(message[0].text, "TEXT1");
  message[0].textAttributes = STATIC_ATTR;
  customers[4] = addCustomer(SWITCH_BITMAP, 1, 1000, message);

  strcpy(message[0].text, "TEXT1");
  message[0].textAttributes = FLARE_ATTR;
  strcpy(message[1].text, "TEXT2");
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
