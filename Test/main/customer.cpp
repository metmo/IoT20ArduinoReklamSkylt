#include <stdlib.h>
#include <Arduino.h>
#include "customer.h"
#include "display.h"



void populateCustomerStruct(customerStruct customers[], int numberOfCustomers) {

    customers[0].customerCost = 1000;
    customers[1].customerCost = 2000;
    customers[2].customerCost = 500;
    customers[3].customerCost = 20000;
    customers[4].customerCost = 3000;
    customers[5].customerCost = 5000;
    customers[6].customerCost = 7000;
    customers[7].customerCost = 3000;
    customers[8].customerCost = 5000;
    customers[9].customerCost = 7000;


    customers[0].numberOfMessages = 2;
    customers[0].switchMethod = SWITCH_RANDOM;

    strcpy(customers[0].messages[0].text, "S�tt upp din reklam hos oss");
    customers[0].messages[0].textAttributes = SCROLL_ATTR;

    strcpy(customers[0].messages[1].text, "Hela staden ser dig");
    customers[0].messages[1].textAttributes = STATIC_ATTR;

    strcpy(customers[0].messages[2].text, "IOT Reklambyr�n");
    customers[0].messages[2].textAttributes = BLINK_ATTR;

    

    customers[1].numberOfMessages = 2;
    customers[1].switchMethod = SWITCH_RANDOM;

    strcpy(customers[1].messages[0].text, "kund 1 m1");
    customers[1].messages[0].textAttributes = SCROLL_ATTR;

    strcpy(customers[1].messages[1].text, "kund 1 m2");
    customers[1].messages[1].textAttributes = STATIC_ATTR;

    strcpy(customers[1].messages[2].text, "kund 1 m3");
    customers[1].messages[2].textAttributes = BLINK_ATTR;



    customers[2].numberOfMessages = 2;
    customers[2].switchMethod = SWITCH_RANDOM;

    strcpy(customers[2].messages[0].text, "kund 2 m1");
    customers[2].messages[0].textAttributes = SCROLL_ATTR;

    strcpy(customers[2].messages[1].text, "kund 2 m2");
    customers[2].messages[1].textAttributes = STATIC_ATTR;

    strcpy(customers[2].messages[2].text, "kund 2 m3 ");
    customers[2].messages[2].textAttributes = BLINK_ATTR;



    customers[3].numberOfMessages = 2;
    customers[3].switchMethod = SWITCH_RANDOM;

    strcpy(customers[3].messages[0].text, "kund 3 m1");
    customers[3].messages[0].textAttributes = SCROLL_ATTR;

    strcpy(customers[3].messages[1].text, "kund 3 m2");
    customers[3].messages[1].textAttributes = STATIC_ATTR;

    strcpy(customers[3].messages[2].text, "kund 3 m3");
    customers[3].messages[2].textAttributes = BLINK_ATTR;



    customers[4].numberOfMessages = 2;
    customers[4].switchMethod = SWITCH_RANDOM;

    strcpy(customers[4].messages[0].text, "kund 4 m1");
    customers[4].messages[0].textAttributes = SCROLL_ATTR;

    strcpy(customers[4].messages[1].text, "kund 4 m2 ");
    customers[4].messages[1].textAttributes = STATIC_ATTR;

    strcpy(customers[4].messages[2].text, "kund 4 m3");
    customers[4].messages[2].textAttributes = BLINK_ATTR;



    strcpy(customers[5].messages[0].text, "S�tt upp din reklam hos oss");
    customers[5].messages[0].textAttributes = SCROLL_ATTR;

    strcpy(customers[5].messages[1].text, "Hela staden ser dig");
    customers[5].messages[1].textAttributes = STATIC_ATTR;

    strcpy(customers[5].messages[2].text, "IOT Reklambyr�n");
    customers[5].messages[2].textAttributes = BLINK_ATTR;



    customers[6].numberOfMessages = 2;
    customers[6].switchMethod = SWITCH_RANDOM;

    strcpy(customers[6].messages[0].text, "kund 1 m1");
    customers[6].messages[0].textAttributes = SCROLL_ATTR;

    strcpy(customers[6].messages[1].text, "kund 1 m2");
    customers[6].messages[1].textAttributes = STATIC_ATTR;

    strcpy(customers[6].messages[2].text, "kund 1 m3");
    customers[6].messages[2].textAttributes = BLINK_ATTR;



    customers[7].numberOfMessages = 2;
    customers[7].switchMethod = SWITCH_RANDOM;

    strcpy(customers[7].messages[0].text, "kund 2 m1");
    customers[7].messages[0].textAttributes = SCROLL_ATTR;

    strcpy(customers[7].messages[1].text, "kund 2 m2");
    customers[7].messages[1].textAttributes = STATIC_ATTR;

    strcpy(customers[7].messages[2].text, "kund 2 m3 ");
    customers[7].messages[2].textAttributes = BLINK_ATTR;



    customers[8].numberOfMessages = 2;
    customers[8].switchMethod = SWITCH_RANDOM;

    strcpy(customers[8].messages[0].text, "kund 3 m1");
    customers[8].messages[0].textAttributes = SCROLL_ATTR;

    strcpy(customers[8].messages[1].text, "kund 3 m2");
    customers[8].messages[1].textAttributes = STATIC_ATTR;

    strcpy(customers[8].messages[2].text, "kund 3 m3");
    customers[8].messages[2].textAttributes = BLINK_ATTR;



    customers[9].numberOfMessages = 2;
    customers[9].switchMethod = SWITCH_RANDOM;

    strcpy(customers[9].messages[0].text, "kund 4 m1");
    customers[9].messages[0].textAttributes = SCROLL_ATTR;

    strcpy(customers[9].messages[1].text, "kund 4 m2 ");
    customers[9].messages[1].textAttributes = STATIC_ATTR;

    strcpy(customers[9].messages[2].text, "kund 4 m3");
    customers[9].messages[2].textAttributes = BLINK_ATTR;


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
