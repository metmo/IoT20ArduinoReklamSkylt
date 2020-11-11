#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"
#include "display.h"
#include "timer.h"
#include <Time.h>

int timer1_counter;
int counter;

void setupTimer() {

  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

 // timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz

  OCR1A = 62499;
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler
 TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();
}

ISR(TIMER1_OVF_vect) {   //This is the interrupt request

  TCNT1 = timer1_counter;   // preload timer
  counter++;;
  if (counter >= 1) {
    newCustomer = 1;
    counter = 0;
  }
}
