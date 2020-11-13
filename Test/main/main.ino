


#define NUMBER_OF_CUSTOMERS 6

#include <stdlib.h>
#include <Arduino.h>
#include <string.h>
#include <TimeLib.h>
#include "customer.h"
#include "display.h"
#include "timer.h"

#include <avr/pgmspace.h>
#include <LiquidCrystal.h>
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
int lastCustomerIndex = 0;

time_t t = now();

customerStruct customers[NUMBER_OF_CUSTOMERS];

void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2);
  addChars();
  setupTimer();

  setTime(16, 20, 30, 11, 1, 2020);
  Serial.print("Time: ");
  Serial.print(hour(t));
  Serial.print(":");
  Serial.print(minute(t));
  Serial.print(":");
  Serial.print(second(t));

  lcd.setCursor(2, 0);
  lcd.print("MVA"); // Marcus Vincent Andreas Commercial
  lcd.setCursor(2, 1);
  lcd.print("Commercial");
  delay(1000);

  populateCustomerStruct(customers, NUMBER_OF_CUSTOMERS);
  customers[0].customerCost = 1500;
}
void loop()
{
  if (newCustomer) {
    int customerIndex;
    do {
      customerIndex = chooseCustomer(customers, NUMBER_OF_CUSTOMERS);
    } while (lastCustomerIndex == customerIndex);
    lastCustomerIndex = customerIndex;
    //  Serial.print("\n\nCustomer index:");
    //  Serial.print(customerIndex);

    displayCustomer(customers, customerIndex);
    newCustomer = 0;
  }

  switch (doEvent) {
    case SCROLL_ATTR: {
        lcd.scrollDisplayRight();
        doEvent = NO_ATTR;
        break;
      }
    case STATIC_ATTR: {

        doEvent = NO_ATTR;
        break;
      }
    case BLINK_ATTR: {
        if (blinkState) {
          Serial.println(text);
          lcdPrint(text);
        } else {
          lcd.clear();
        }
        blinkState = !blinkState;
        doEvent = NO_ATTR;
        break;
      }
    case FLARE_ATTR: {
        doEvent = NO_ATTR;
        break;
    }  case NO_ATTR: {
        doEvent = NO_ATTR;
        break;
      }


  }
}
