#define NUMBER_OF_CUSTOMERS 6

#include <Arduino.h>
#include "timer.h"
#include "customer.h"
#include "display.h"
#include "lcd.h"

#define lcdD7pin 7
#define lcdD6pin 6
#define lcdD5pin 5
#define lcdD4pin 4
#define lcdENpin 3
#define lcdRSpin 2

LiquidCrystal lcd(lcdRSpin, lcdENpin, lcdD4pin, lcdD5pin, lcdD6pin, lcdD7pin);

bool newCustomer = 1;
bool blinkState = 1;
enum TEXT_ATTRIBUTES activeAttr;
enum TEXT_ATTRIBUTES doEvent;
char text[50];
time_t t;

customerStruct customers[NUMBER_OF_CUSTOMERS];

void setup()
{
  setTime(17, 20, 30, 11, 1, 2020);
  randomSeed(analogRead(A0));
  Serial.begin(9600);

  lcd.begin(16, 2);
  addChars();
  setupTimers();

  populateCustomerStruct(customers, NUMBER_OF_CUSTOMERS);

}
int lastCustomerIndex ;
void loop()
{
  int customerIndex;
  if (newCustomer) {
    do {
      customerIndex = chooseCustomer(customers, NUMBER_OF_CUSTOMERS);
    } while (lastCustomerIndex == customerIndex);
    lastCustomerIndex = customerIndex;
    displayCustomer(customers, customerIndex);
    newCustomer = 0;
  }
  eventCheck();
}
