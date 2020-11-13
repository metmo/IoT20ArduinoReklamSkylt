
#include <LiquidCrystal.h>            // includes the LiquidCrystal Library 

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
 
void setup() { 
 lcd.begin(16,2);                   // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display 
}


void loop() { 
 lcd.print("Köp paj hos");
 
 lcd.setCursor(2,1); 
 lcd.print("Farmor Anka"); 
 
 delay(2000); // 
 
for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
   
    
    lcd.scrollDisplayLeft();
 
    delay(150);
    lcd.clear();
    lcd.blink();
} 
{
                                          // Sets the location at which subsequent text written to the LCD will be displayed 
 lcd.print("Farmor Ankas");
 lcd.setCursor(2,1);                                          //lcd.setCursor(2,1);
 lcd.print("Pajer AB!");
 
 delay(2000);}

 for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
   
    
    lcd.scrollDisplayLeft();
 
    delay(150);
} 
                                                    //lcd.setCursor(2,1); // Sets the location at which subsequent text written to the LCD will be displayed 
                                                    //lcd.print("Hell yes!");                                                   //delay(6000); 
 lcd.clear();                                       // Clears the display 
 lcd.blink();                                       //Displays the blinking LCD cursor 
 delay(1000); 
                                                    // lcd.setCursor(7,1); 
                                                    //delay(1000); 
 lcd.noBlink();                                     // Turns off the blinking LCD cursor 
 lcd.cursor();                                      // Displays an underscore (line) at the position to which the next character will be written 
 delay(1000); 
 lcd.noCursor();                                    // Hides the LCD cursor 
 lcd.clear();                                       // Clears the LCD screen 
}
