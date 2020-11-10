//RANDOM
#include <arduino-timer.h>
#include <string.h>
auto timer = timer_create_default(); // create a timer with default settings
long randomNumber;

//randomSeed(1999);
void harrysBilar()
{
  char kopBilReklam[][40] = {"Köp bil hos Harry","Hederlige Harrys Bilar","En god bilaffär (för Harry!)"}; 
  char bufferplace[50];
  strcpy(bufferplace,kopBilReklam[random(0,3)]);
  Serial.println(bufferplace);
}

void FarmorAnkasPajerAB()
{
  char pajReklam[][40] = {"Köp paj hos Farmor Anka","Skynda innan Mårten ätit alla pajer"};
  
}

void SvartePettersSvartbyggen()
{
  char svartByggeReklam[][40] = {"Låt Petter bygga åt dig","Bygga svart? Ring Petter"};
  
}

bool print_message(void *) 
{
  harrysBilar();
  Serial.println("print_message: Called at: ");
  Serial.println(millis());
  return true; // repeat? true
}
//*****************************************************************/
//                      SETUP INITIALIZATION
//*****************************************************************/
void setup() 
{
  Serial.begin(9600);

  randomSeed(analogRead(0));
  // call the print_message function every 20000 millis (20 second)
  timer.every(5000, print_message);
}
//*****************************************************************/
//                           LOOP CRAP
//*****************************************************************/
void loop() 
{
  //randomNumber = random(2,5);
  timer.tick(); // tick the timer
  //Serial.print("The Random Num is = ");
  //Serial.print(randomNumber);
  
}
