#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"
#include "display.h"



void populateCustomerStruct(customerStruct customers[], int numberOfCustomers) {


  customers[0].customerCost = 5000;
  customers[0].numberOfMessages = 2;
  customers[0].switchMethod = SWITCH_RANDOM;
  strcpy(customers[0].messages[0].text, "Köp bil hos Harry");
  customers[0].messages[0].textAttributes = SCROLL_ATTR;
  strcpy(customers[0].messages[1].text, "En god bilaffär(för Harry!)"); // måste delas i printen
  customers[0].messages[1].textAttributes = STATIC_ATTR;
  strcpy(customers[0].messages[2].text, "Hederlige Harrys Bilar");
  customers[0].messages[2].textAttributes = BLINK_ATTR;


  customers[1].customerCost = 3000;
  customers[1].numberOfMessages = 1;
  customers[1].switchMethod = SWITCH_RANDOM;
  strcpy(customers[1].messages[0].text, "Köp paj hos Farmor Anka");  // MÅSTE DELA I PRINT
  customers[1].messages[0].textAttributes = SCROLL_ATTR;
  strcpy(customers[1].messages[1].text, "Skynda innan Mårten ätit allt"); // måste dela i print
  customers[1].messages[1].textAttributes = STATIC_ATTR;


  customers[2].customerCost = 1500;
  customers[2].numberOfMessages = 1;
  customers[2].switchMethod = SWITCH_RANDOM;
  strcpy(customers[2].messages[0].text, "Låt Petter Bygga åt dig"); // dela och vis apå jämna minuter?
  customers[2].messages[0].textAttributes = SCROLL_ATTR;
  strcpy(customers[2].messages[1].text, "Bygga svart? Ring Petter"); // dela ojämna minuter
  customers[2].messages[1].textAttributes = STATIC_ATTR;


  customers[3].customerCost = 4000;
  customers[3].numberOfMessages = 1;
  customers[3].switchMethod = SWITCH_RANDOM;
  strcpy(customers[3].messages[0].text, "Mysterier? Ring Långben"); //endast på  kvällstid, dvs mellan 17:00-06:00
  customers[3].messages[0].textAttributes = SCROLL_ATTR;
  strcpy(customers[3].messages[1].text, "Långben fixar biffen"); // endast på dagtid
  customers[3].messages[1].textAttributes = STATIC_ATTR;


  customers[4].customerCost = 1000;
  customers[4].numberOfMessages = 1;
  customers[4].switchMethod = SWITCH_RANDOM;
  strcpy(customers[4].messages[0].text, "IOT-Reklambyå");
  customers[4].messages[0].textAttributes = SCROLL_ATTR;
  strcpy(customers[4].messages[1].text, "Bäst in town!"); // bonus
  customers[4].messages[1].textAttributes = STATIC_ATTR;
  strcpy(customers[4].messages[2].text, "kund 4 m3");
  customers[4].messages[2].textAttributes = BLINK_ATTR;



  customers[5].customerCost = 5000;
  strcpy(customers[5].messages[0].text, "S�tt upp din reklam hos oss");
  customers[5].messages[0].textAttributes = SCROLL_ATTR;
  strcpy(customers[5].messages[1].text, "Hela staden ser dig");
  customers[5].messages[1].textAttributes = STATIC_ATTR;
  strcpy(customers[5].messages[2].text, "IOT Reklambyr�n");
  customers[5].messages[2].textAttributes = BLINK_ATTR;

  return;
}

int chooseCustomer(customerStruct customers[], int numberOfCustomers) {
  long int totalSum = 0;
  for (int i = 0; i < numberOfCustomers; i++) {
    totalSum += customers[i].customerCost;
  }
  long int randomNumber = random(0, totalSum);
  totalSum = 0;
  for (int i = 0; i < numberOfCustomers; i++) {
    totalSum += customers[i].customerCost;
    if (randomNumber <= totalSum) {
      return i;
    }
  }
  return 0;
}
