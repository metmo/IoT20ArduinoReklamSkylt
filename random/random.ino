//RANDOM
#include <arduino-timer.h>
auto timer = timer_create_default(); // create a timer with default settings
long randomNumber;
randomSeed(1999);
char harrysBilar()
{
  char kopBilReklam[][40] = {"Köp bil hos Harry","Hederlige Harrys Bilar","En god bilaffär (för Harry!)"}; 
  int randomNUm = random(0,3);
  return Serial.print(randomNUm);
}

void FarmorAnkasPajerAB()
{
  char pajReklam[][40] = {"Köp paj hos Farmor Anka","Skynda innan Mårten ätit alla pajer"};
}

void SvartePettersSvartbyggen()
{
  char svartByggeReklam[][40] = {"Låt Petter bygga åt dig","Bygga svart? Ring Petter"};
}

bool print_message(void *) {
  Serial.print("print_message: Called at: ");
  Serial.println(millis());
  return true; // repeat? true
}
//*****************************************************************/
//                      SETUP INITIALIZATION
//*****************************************************************/
void setup() {
  Serial.begin(9600);

  randomSeed(42);
  // call the print_message function every 20000 millis (20 second)
  timer.every(5000, print_message);
}
//*****************************************************************/
//                           LOOP CRAP
//*****************************************************************/
void loop() {
  randomNumber = random(2,5);
  timer.tick(); // tick the timer
  //Serial.print("The Random Num is = ");
  //Serial.print(randomNumber);
  
}
