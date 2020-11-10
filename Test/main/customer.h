#include <stdlib.h>
#include <Arduino.h>


#define TIME_BETWEEN_SWITCH 20 // Second between switch
#define NUMBER_OF_CUSTOMERS 5 //10
#define MESSAGE_LENGTH 40


enum SWITCH_METHOD {
  SWITCH_RANDOM,
  SWITCH_ODD_EVEN_MINUTES,
  SWITCH_DAY_NIGHT
};

enum TEXT_ATTRIBUTES {
  SCROLL_ATTR,
  STATIC_ATTR,
  BLINK_ATTR,
  FLARE_ATTR
};

struct messageStruct {
  char text[MESSAGE_LENGTH];
  enum TEXT_ATTRIBUTES textAttributes;
};
struct customerStruct {
  unsigned short int customerCost = 0;
  short numberOfMessages = 0;
  messageStruct messages[3];
  enum SWITCH_METHOD switchMethod;

};

void populateCustomerStruct(customerStruct customers[], int numberOfCustomers );
int chooseCustomer(customerStruct customers[], int numberOfCustomers);
