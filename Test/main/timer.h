#ifndef timerheader
#define timerheader

extern bool newCustomer;

void setupTimer();
ISR(TIMER0_COMPA_vect);


#endif
