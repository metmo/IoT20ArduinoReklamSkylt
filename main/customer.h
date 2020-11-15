#ifndef customerheader
#define customerheader

#include <Arduino.h>
#include <avr/pgmspace.h>

#define MESSAGE_LENGTH 40
#define MAX_NUMBER_OF_MESSAGES 3

  const char line0[] PROGMEM = "Köp bil\nhos Harry";
  const char line1[] PROGMEM = "En god bilaffär\n(för Harry!)";
  const char line2[] PROGMEM = "Hederlige harrys bilar";
  const char line3[] PROGMEM = "Köp paj hos Farmor Anka";
  const char line4[] PROGMEM = "Skynda innan\nMårten ätit allt";
  const char line5[] PROGMEM = "Låt Petter\nBygga åt dig";
  const char line6[] PROGMEM = "Bygga svart?\nRing Petter";
  const char line7[] PROGMEM = "Mysterier? Ring\nLångben";
  const char line8[] PROGMEM = "Långben fixar\nbiffen";
  const char line9[] PROGMEM = "IOT-Reklambyrå";
  const char line10[] PROGMEM = "T-Röd - för dig\nsom tänkt klart";
  const char line11[] PROGMEM = "Claes Månsson\noch flickan";
  
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
  SWITCH_RANDOM,
  SWITCH_ODD_EVEN_MINUTES,

  SWITCH_DAY_NIGHT,
  SWITCH_BITMAP
};

enum TEXT_ATTRIBUTES {
  SCROLL_ATTR,
  STATIC_ATTR,
  BLINK_ATTR,
  FLARE_ATTR,
  NO_ATTR

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

void populateCustomerStruct(customerStruct customers[], int numberOfCustomers );
customerStruct addCustomer(SWITCH_METHOD switchMethod, short numberOfMessages, unsigned int customerCost, messageStruct messages[]);
int chooseCustomer(customerStruct customers[], int numberOfCustomers);

#endif
