#ifndef timerheader
#define timerheader

#include <Arduino.h>
#include <TimeLib.h>
#include "customer.h"
#include "lcd.h"

extern time_t t;
extern bool blinkState;
extern bool newCustomer;
extern enum TEXT_ATTRIBUTES activeAttr;
extern messageStruct (*messagePtr);

void setupTimers();
ISR(TIMER0_COMPA_vect);
ISR(TIMER1_OVF_vect);


#endif
