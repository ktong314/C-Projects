


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "MyString.h"
#include "Invent.h"

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;
int num_failedcustomers = 0;
int num_bottles = 0;
int num_diapers = 0;
int num_rattles = 0;
int failedCustomersInd[MAX_CUSTOMERS];

/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */


/* clear the inventory and reset the customer database to empty */
void reset(void) {

    num_customers = 0;
    num_failedcustomers = 0;
    num_bottles = 0;
    num_diapers = 0;
    num_rattles = 0;

    for(int i = 0; i < MAX_CUSTOMERS; i++){
        customers[i].bottles = 0;
        customers[i].rattles = 0;
        customers[i].diapers = 0;
    }

    for(int i = 0; i < MAX_CUSTOMERS; i++){
        failedCustomersInd[i] = 0;
    }


}

void processSummarize() { //print out the summary in the given form
    int mostBottles = 0;
    int mostBottlesInd = -1;
    int mostDiapers = 0;
    int mostDiapersInd = -1;
    int mostRattles = 0;
    int mostRattlesInd = -1;
    //int failedCustomerIndex = 0;
    //int alreadyfail = 0;
    int realCustomers = 0;

/*    for(int i = 0; i < num_customers; i++){
        //printf("%.*s: %d %d %d\n", customers[i].name.len, customers[i].name.ptr, customers[i].bottles,customers[i].diapers,customers[i].rattles);
        if(customers[i].bottles == 0 && customers[i].diapers == 0 && customers[i].rattles == 0){
            for(int k = 0; k < failedCustomerIndex; k++){
                if(failedCustomersInd[k] == i){
                    alreadyfail = 1;
                }
            }
            if(alreadyfail == 0){
                failedCustomersInd[failedCustomerIndex] = i;
                failedCustomerIndex++;
                num_failedcustomers++;
            }

        }
    }*/

    for(int i = 0; i < num_customers; i++){
        if(!(customers[i].bottles == 0 && customers[i].diapers == 0 && customers[i].rattles == 0)){
            realCustomers++;
        }
    }

    printf("There are %d Bottles %d Diapers and %d Rattles in inventory\n",num_bottles, num_diapers, num_rattles);
    printf("we have had a total of %d different customers\n", realCustomers);
    for(int i = 0; i < num_customers; i++){
        if(mostBottles < customers[i].bottles){
            mostBottles = customers[i].bottles;
            mostBottlesInd = i;
        }
    }
    if(mostBottles > 0){
        printf("%.*s has purchased the most Bottles (%d)\n",customers[mostBottlesInd].name.len, customers[mostBottlesInd].name.ptr, mostBottles);
    }
    else{
        printf("no one has purchased any Bottles\n");
    }
    for(int i = 0; i < num_customers; i++){
        if(mostDiapers < customers[i].diapers){
            mostDiapers = customers[i].diapers;
            mostDiapersInd = i;
        }
    }
    if(mostDiapers > 0){
        printf("%.*s has purchased the most Diapers (%d)\n",customers[mostDiapersInd].name.len, customers[mostDiapersInd].name.ptr, mostDiapers);
    }
    else{
        printf("no one has purchased any Diapers\n");
    }
    for(int i = 0; i < num_customers; i++){
        if(mostRattles < customers[i].rattles){
            mostRattles = customers[i].rattles;
            mostRattlesInd = i;
        }
    }
    if(mostRattles > 0){
        printf("%.*s has purchased the most Rattles (%d)\n",customers[mostRattlesInd].name.len, customers[mostRattlesInd].name.ptr, mostRattles);
    }
    else{
        printf("no one has purchased any Rattles\n");
    }
    printf("\n");


}

void processPurchase() {
    readString(&customers[num_customers].name);

    int match = 0;
    int current_customer;

    for(int i = 0; i < num_customers; i++){
        if(StringIsEqualTo(&customers[num_customers].name, &customers[i].name)){
            match = 1;
            current_customer = i;
        }
    }
    if (match == 0){
        current_customer = num_customers;
        num_customers++;
    }



    String* purStringPtr2; //item they are buying
    purStringPtr2 = (String*)malloc(sizeof(String));
    readString(purStringPtr2);
    //printf("%.*s\n", purStringPtr2->len,purStringPtr2->ptr);
    int* purIntPtr; //amount they bought
    purIntPtr = (int*)malloc(sizeof(int));
    readNum(purIntPtr);
    //printf("%d\n", *purIntPtr);

    if(purStringPtr2->ptr[0] == 'B'){
        if(num_bottles >=0 && *purIntPtr >= 0){
            customers[current_customer].bottles = customers[current_customer].bottles + *purIntPtr;
            num_bottles = num_bottles - *purIntPtr;
            if(num_bottles < 0){
                customers[current_customer].bottles = customers[current_customer].bottles - *purIntPtr;
                num_bottles = num_bottles + *purIntPtr;
                printf("Sorry %.*s, we only have %d Bottles\n", customers[current_customer].name.len, customers[current_customer].name.ptr, num_bottles);
            }
        }
    }
    if(purStringPtr2->ptr[0] == 'D'){
        if(num_diapers >=0 && *purIntPtr >= 0){
            customers[current_customer].diapers = customers[current_customer].diapers + *purIntPtr;
            num_diapers = num_diapers - *purIntPtr;
            if(num_diapers < 0){
                customers[current_customer].diapers = customers[current_customer].diapers - *purIntPtr;
                num_diapers = num_diapers + *purIntPtr;
                printf("Sorry %.*s, we only have %d Diapers\n", customers[current_customer].name.len, customers[current_customer].name.ptr, num_diapers);
            }
        }
    }
    if(purStringPtr2->ptr[0] == 'R'){
        if(num_rattles >=0 && *purIntPtr >= 0){
            customers[current_customer].rattles = customers[current_customer].rattles + *purIntPtr;
            num_rattles = num_rattles - *purIntPtr;
            if(num_rattles < 0){
                customers[current_customer].rattles = customers[current_customer].rattles - *purIntPtr;
                num_rattles = num_rattles + *purIntPtr;
                printf("Sorry %.*s, we only have %d Rattles\n", customers[current_customer].name.len, customers[current_customer].name.ptr, num_rattles);
            }
        }
    }

    free(purIntPtr);
    //StringDestroy(purStringPtr);
    StringDestroy(purStringPtr2);
}

void processInventory() { //write if statements, If(invStringPtr->ptr == "Bottles"){num_bottles = invIntPtr;} etc...
    String* invStringPtr;
    invStringPtr = (String*)malloc(sizeof(String));
    readString(invStringPtr);

    //printf("%.*s\n", invStringPtr->len,invStringPtr->ptr);
    int* invIntPtr;
    invIntPtr = (int*)malloc(sizeof(int));
    readNum(invIntPtr);
    //printf("%d\n", *invIntPtr);

    if(*invIntPtr >= 0){
        if(invStringPtr->ptr[0] == 'B'){
            num_bottles = *invIntPtr;
        }
        if(invStringPtr->ptr[0] == 'D'){
            num_diapers = *invIntPtr;
        }
        if(invStringPtr->ptr[0] == 'R'){
            num_rattles = *invIntPtr;
        }
    }

    StringDestroy(invStringPtr);
    free(invIntPtr);
}
