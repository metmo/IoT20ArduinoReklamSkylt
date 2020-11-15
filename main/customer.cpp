#include "customer.h"

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

  strcpy_P(message[0].text, (PGM_P)pgm_read_word(&(textData[0])));
  message[0].textAttributes = SCROLL_ATTR;
  strcpy_P(message[1].text, (PGM_P)pgm_read_word(&(textData[1])));
  message[1].textAttributes = STATIC_ATTR;
  strcpy_P(message[2].text, (PGM_P)pgm_read_word(&(textData[2])));
  message[2].textAttributes = BLINK_ATTR;
  customers[0] = addCustomer(SWITCH_RANDOM, 3, 1500, message);


  strcpy_P(message[0].text, (PGM_P)pgm_read_word(&(textData[3])));
  message[0].textAttributes = SCROLL_ATTR;
  strcpy_P(message[1].text, (PGM_P)pgm_read_word(&(textData[4])));
  message[1].textAttributes = STATIC_ATTR;
  customers[1] = addCustomer(SWITCH_RANDOM, 2, 3000, message);

  strcpy_P(message[0].text, (PGM_P)pgm_read_word(&(textData[5])));
  message[0].textAttributes = SCROLL_ATTR;
  strcpy_P(message[1].text, (PGM_P)pgm_read_word(&(textData[6])));
  message[1].textAttributes = STATIC_ATTR;
  customers[2] = addCustomer(SWITCH_ODD_EVEN_MINUTES, 2, 1500, message);

  strcpy_P(message[0].text, (PGM_P)pgm_read_word(&(textData[7])));
  message[0].textAttributes = STATIC_ATTR;
  strcpy_P(message[1].text, (PGM_P)pgm_read_word(&(textData[8])));
  message[1].textAttributes = SCROLL_ATTR;
  customers[3] = addCustomer(SWITCH_DAY_NIGHT, 2, 4000, message);

  strcpy_P(message[0].text, (PGM_P)pgm_read_word(&(textData[9])));
  message[0].textAttributes = BLINK_ATTR;
  customers[4] = addCustomer(SWITCH_BITMAP, 1, 1000, message);

  strcpy_P(message[0].text, (PGM_P)pgm_read_word(&(textData[10])));
  message[0].textAttributes = FLARE_ATTR;
  strcpy_P(message[1].text, (PGM_P)pgm_read_word(&(textData[11])));
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
