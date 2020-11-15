#ifndef displayheader
#define displayheader

#include <Arduino.h>
#include "customer.h"
#include "timer.h"
#include "lcd.h"
#include <LiquidCrystal.h>
#include <TimeLib.h>

extern messageStruct (*messagePtr);
extern customerStruct customers[6];
extern LiquidCrystal lcd;
extern time_t t;

void eventCheck();
void showText(messageStruct *message);
void displayCustomer(customerStruct *customer, int customerIndex);

#endif
