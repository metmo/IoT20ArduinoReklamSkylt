#include <stdlib.h>
#include <Arduino.h>
#include <stdarg.h>
#include "customer.h"
#include "display.h"
#include "lcd.h"
#include <avr/pgmspace.h>
#include <LiquidCrystal.h>

extern LiquidCrystal lcd;

void addChars() {

  byte a1[8] = {//å
    B00100,
    B00000,
    B01110,
    B00001,
    B01111,
    B10001,
    B01111,
    B00000
  };

  byte a2[8] = {//Å
    B00100,
    B00000,
    B01110,
    B10001,
    B10001,
    B11111,
    B10001,
    B10001
  };

  byte a3[8] = {//ä
    B01010,
    B00000,
    B01110,
    B00001,
    B01111,
    B10001,
    B01111,
    B00000
  };

  byte a4[8] = {//Ä
    B01010,
    B00000,
    B01110,
    B10001,
    B10001,
    B11111,
    B10001,
    B10001
  };

  byte a5[8] = {//ö
    B01010,
    B00000,
    B01110,
    B10001,
    B10001,
    B10001,
    B01110,
    B00000
  };
  byte a6[8] = {//Ö
    B01010,
    B00000,
    B01110,
    B10001,
    B10001,
    B10001,
    B10001,
    B01110
  };

  lcd.createChar(byte(0), a1);
  lcd.createChar(byte(1), a2);
  lcd.createChar(byte(2), a3);
  lcd.createChar(byte(3), a4);
  lcd.createChar(byte(4), a5);
  lcd.createChar(byte(5), a6);
}

//test

void lcdPrint(const char message[]) {
lcd.clear();
lcd.setCursor(0,0);
  for (int i = 0; i < 50; i++) {

    switch (message[i]) {
      case char('å'): {
          lcd.write(byte(0));
          break;
        }
      case char('Å'): {
          lcd.write(byte(1));
          break;
        }
      case char('ä'): {
          lcd.write(byte(2));
          break;
        }
      case char('Ä'): {
          lcd.write(byte(3));
          break;
        }
      case char('ö'): {
          lcd.write(byte(4));
          break;
        }
      case char('Ö'): {
          lcd.write(byte(5));
          break;
        }
      case '\0': {
          return;
          break;
        }
      case '\xc3': {
          break;
        }
        case '\n':{
          lcd.setCursor(0,1);
          break;
        }

      default: {
          lcd.write(char(message[i]));
          break;
        }
    }
  }
}
