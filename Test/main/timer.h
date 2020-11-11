#ifndef timerheader
#define timerheader

extern int timer1;
extern bool newCustomer;

void setupTimer();
ISR(TIMER0_COMPA_vect);


#endif
