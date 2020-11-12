#ifndef customerheader
#define customerheader

#define MESSAGE_LENGTH 50
#define MAX_NUMBER_OF_MESSAGES 3

  const char line0[] PROGMEM = "Köp bil hos\nHarry";
  const char line1[] PROGMEM = "En god bilaffär\n(för Harry!)";
  const char line2[] PROGMEM = "Hederlige Harrys Bilar";
  const char line3[] PROGMEM = "Köp paj hos\nFarmor Anka";
  const char line4[] PROGMEM = "Skynda innan\nMårten ätit allt";
  const char line5[] PROGMEM = "Låt Petter\nBygga åt dig";
  const char line6[] PROGMEM = "Bygga svart?\nRing Petter";
  const char line7[] PROGMEM = "Mysterier?\nRing Långben";
  const char line8[] PROGMEM = "Långben fixar\nbiffen";
  const char line9[] PROGMEM = "IOT-Reklambyå";
  const char line10[] PROGMEM = "T-Röd - för dig\nsom tänkt klart";
  const char line11[] PROGMEM = "Claes Månsson - om\nflickan själv får välja";
  
  const char * const textData[] PROGMEM =
  {
    line0,
    line1,
    line2,
    line3,
    line4,
    line5,
    line6,
    line7,
    line8,
    line9,
    line10,
    line11
  };


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
