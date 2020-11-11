#ifndef customerheader
#define customerheader

#define MESSAGE_LENGTH 50
#define MAX_NUMBER_OF_MESSAGES 2
#define INITIAL_CUSTOMER_COST 1000


enum SWITCH_METHOD {
  SWITCH_RANDOM,
  SWITCH_ODD_EVEN_MINUTES,
  SWITCH_DAY_NIGHT,
  SWITCH_BITMAP
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
  unsigned int customerCost = INITIAL_CUSTOMER_COST;
  short numberOfMessages = MAX_NUMBER_OF_MESSAGES;
  messageStruct messages[MAX_NUMBER_OF_MESSAGES];
  enum SWITCH_METHOD switchMethod;

};

void populateCustomerStruct(customerStruct *customers, int numberOfCustomers );
customerStruct addCustomer(SWITCH_METHOD switchMethod, short numberOfMessages, unsigned int customerCost, messageStruct messages[]);
int chooseCustomer(customerStruct *customers, int numberOfCustomers);

#endif
