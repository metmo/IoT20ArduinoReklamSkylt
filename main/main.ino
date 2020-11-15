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

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

customerStruct customers[NUMBER_OF_CUSTOMERS];
messageStruct (*messagePtr);

void setup()
{
  setTime(17, 20, 30, 11, 1, 2020);
  randomSeed(analogRead(A0));
  Serial.begin(9600);
  lcd.begin(16, 2);
  addChars();

  while (!Serial) ; // Needed for Leonardo only
  pinMode(13, OUTPUT);
  setSyncProvider( requestSync);  //set function to call when sync required
  Serial.println("Waiting for sync message");

  setupTimers();

  populateCustomerStruct(customers, NUMBER_OF_CUSTOMERS);
}

void loop()
{
  if (Serial.available()) {
    processSyncMessage();
  }

  eventCheck();
}

void digitalClockDisplay() {
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year());
  Serial.println();
}

void printDigits(int digits) {
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void processSyncMessage() {
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

  if (Serial.find(TIME_HEADER)) {
    pctime = Serial.parseInt();
    if ( pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
      setTime(pctime); // Sync Arduino clock to the time received on the serial port
      digitalClockDisplay();
    }
  }
}

time_t requestSync()
{
  Serial.write(TIME_REQUEST);
  return 0; // the time will be sent later in response to serial mesg
}
