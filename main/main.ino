#define NUMBER_OF_CUSTOMERS 6

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <TimeLib.h>

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

time_t t;

customerStruct customers[NUMBER_OF_CUSTOMERS];
messageStruct (*messagePtr);

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

void loop()
{
  eventCheck();
}
