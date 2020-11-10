#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"
#include "display.h"

int timer = 0;

void setupTimer(){
  TCCR0A=(1<<WGM01);    //Set the CTC mode   
  OCR0A=0xF9; //Value for ORC0A for 1ms 
  
  TIMSK0|=(1<<OCIE0A);   //Set the interrupt request
  sei(); //Enable interrupt
  
  TCCR0B|=(1<<CS01);    //Set the prescale 1/64 clock
  TCCR0B|=(1<<CS00);
}

ISR(TIMER0_COMPA_vect){    //This is the interrupt request
  timer++;
}
