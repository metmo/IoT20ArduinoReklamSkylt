#include "lcd.h"

void addChars() {

  byte character[8][8] = {
    { B00100,
      B00000,
      B01110,
      B00001,
      B01111,
      B10001,
      B01111,
      B00000
    },

    { B00100,
      B00000,
      B01110,
      B10001,
      B10001,
      B11111,
      B10001,
      B10001
    },

    { B01010,
      B00000,
      B01110,
      B00001,
      B01111,
      B10001,
      B01111,
      B00000
    },

    { B01010,
      B00000,
      B01110,
      B10001,
      B10001,
      B11111,
      B10001,
      B10001
    },

    { B01010,
      B00000,
      B01110,
      B10001,
      B10001,
      B10001,
      B01110,
      B00000
    },

    { B01010,
      B00000,
      B01110,
      B10001,
      B10001,
      B10001,
      B10001,
      B01110
    }
  };

  for (int i = 0; i < 6; i++) {
    lcd.createChar(byte(i), character[i]);
  }
}

void lcdPrint(const char message[]) {
  for (int i = 0; i < 40; i++) {

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
      case '\n': {
          lcd.setCursor(0, 1);
          break;
        }
      default: {
          lcd.write(char(message[i]));
          break;
        }
    }
  }
}
