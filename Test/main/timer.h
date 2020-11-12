#ifndef timerheader
#define timerheader

extern bool newCustomer;
extern enum TEXT_ATTRIBUTES activeAttr;
extern enum TEXT_ATTRIBUTES doEvent;

void setupTimer();
ISR(TIMER0_COMPA_vect);
ISR(TIMER1_OVF_vect);


#endif
