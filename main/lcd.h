#ifndef lcdheader
#define lcdheader

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "display.h"
#include "customer.h"

extern LiquidCrystal lcd;

void addChars();
void lcdPrint(char message[]);

#endif
