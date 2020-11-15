#ifndef displayheader
#define displayheader

#include <Arduino.h>
#include "customer.h"
#include "timer.h"
#include "lcd.h"
#include <LiquidCrystal.h>
#include <TimeLib.h>



extern LiquidCrystal lcd;
extern enum TEXT_ATTRIBUTES activeAttr;
extern enum TEXT_ATTRIBUTES doEvent;
extern char text[50];
extern time_t t;
extern bool blinkState;

void eventCheck();
void showText(messageStruct message);
void displayCustomer(customerStruct *customer, int customerIndex);

#endif
