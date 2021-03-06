#include <Arduino.h>
#include <TimeLib.h>
#include "customer.h"
#include "display.h"
#include "timer.h"
#include "lcd.h"

int timer0_lastMillis = 0;
int timer0_lastMillis2 = 0;
int timer1_counter;
int counter;
extern time_t t;
extern bool blinkState;

void setupTimers() {

  noInterrupts();

  TIMSK0 |= (1 << OCIE0A);

  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 62499;
  // TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  
  interrupts();
}

ISR(TIMER0_COMPA_vect) {  // Timer0 Compare
  switch (activeAttr) {
    case SCROLL_ATTR: {
        int currentMillisScroll = millis();
        if (currentMillisScroll - timer0_lastMillis >= 300) {
          timer0_lastMillis = currentMillisScroll;
          doEvent = SCROLL_ATTR;
        }
        break;
      }
    case STATIC_ATTR: {
        doEvent = STATIC_ATTR;
        break;
      }
    case BLINK_ATTR: {
        int currentMillisBlink = millis();
        if (currentMillisBlink - timer0_lastMillis2 >= 600) {
          timer0_lastMillis2 = currentMillisBlink;
          blinkState = !blinkState;
          doEvent = BLINK_ATTR;
        }
        break;
      }

    case FLARE_ATTR: {
        doEvent = FLARE_ATTR;
        break;
      }
    default: {
        return;
      }
  }
}
ISR(TIMER1_OVF_vect) {  // Timer1 Overflow Interrupt
  counter++;;
  if (counter >= 10) {
    newCustomer = 1;
    counter = 0;
  }
}
