#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"
#include "display.h"
#include "timer.h"
#include "lcd.h"
#include <Time.h>
#include <avr/pgmspace.h>
#include <LiquidCrystal.h>

int timer0_lastMillis;
int timer1_counter;
int counter;
extern time_t t;

void setupTimer() {

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
        int currentMillis = millis();
        if (currentMillis - timer0_lastMillis >= 300) {
          timer0_lastMillis = currentMillis;
          doEvent = SCROLL_ATTR;
        }
        break;
      }
    case STATIC_ATTR: {
        doEvent = STATIC_ATTR;
        break;
      }
    case BLINK_ATTR: {
        int currentMillis = millis();
        if (currentMillis - timer0_lastMillis >= 500) {
          timer0_lastMillis = currentMillis;
          doEvent = BLINK_ATTR;
        }
        break;

      case FLARE_ATTR: {
          doEvent = FLARE_ATTR;
          break;
        }
      }
  }

}
ISR(TIMER1_OVF_vect) {  // Timer1 Interrupt
  // TCNT1 = timer1_counter;
  counter++;;
  if (counter >= 20) {
    newCustomer = 1;
    counter = 0;
  }
}
