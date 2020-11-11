#ifndef customerheader
#define customerheader

#define MESSAGE_LENGTH 50
#define MAX_NUMBER_OF_MESSAGES 2


enum SWITCH_METHOD {
  SWITCH_RANDOM = 0,
  SWITCH_ODD_EVEN_MINUTES = 1,
  SWITCH_DAY_NIGHT = 2,
  SWITCH_BITMAP = 3
};

enum TEXT_ATTRIBUTES {
  SCROLL_ATTR = 0,
  STATIC_ATTR = 1,
  BLINK_ATTR = 2,
  FLARE_ATTR = 3
};

struct messageStruct {
  char text[MESSAGE_LENGTH];
  enum TEXT_ATTRIBUTES textAttributes;
};
struct customerStruct {
  enum SWITCH_METHOD switchMethod;
  unsigned long int customerCost;
  short numberOfMessages = MAX_NUMBER_OF_MESSAGES;
  messageStruct messages[MAX_NUMBER_OF_MESSAGES];


};

void storeData();
void populateCustomerStruct(customerStruct customers[], int numberOfCustomers );
customerStruct addCustomer(SWITCH_METHOD switchMethod, short numberOfMessages, unsigned int customerCost, messageStruct messages[]);
int chooseCustomer(customerStruct customers[], int numberOfCustomers);

#endif
