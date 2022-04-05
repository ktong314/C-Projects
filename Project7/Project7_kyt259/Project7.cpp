// CRM in C++ <filename.cpp>
// EE 312 Project 7 submission by
// Kevin Tong
// kyt259
// Slip days used: <0>
// Fall 2021

#include <iostream>
#include <stdio.h>
#include "UTString.h"
#include "Customer.h"
#include "CustomerDB.h"

void readString(UTString&);
void readNum(int&);

CustomerDB database;

int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;



/* clear the inventory and reset the customer database to empty */
void reset(void) {
    database.clear();
    num_bottles = 0;
    num_rattles = 0;
    num_diapers = 0;
}

/*
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Bottles", "Diapers" or "Rattles"
 * for example the expression *selectInventItem("Bottles") returns the
 * current global variable for the number of bottls in the inventory
 */
int* selectInventItem(UTString word) {
    if (word == "Bottles") {
        return &num_bottles;
    } else if (word == "Diapers") {
        return &num_diapers;
    } else if (word == "Rattles") {
        return &num_rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(UTString word, Customer& cust) {
    if (word == "Bottles") {
        return &cust.bottles;
    } else if (word == "Diapers") {
        return &cust.diapers;
    } else if (word == "Rattles") {
        return &cust.rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Bottles", "Rattles" or "Diapers".
 *
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(UTString type) {
    Customer* result = 0;
    int max = 0;
    for (int k = 0; k < database.size(); k += 1) {
        Customer& cust = database[k];
        int *p = selectInventItem(type, cust);
        if (*p > max) {
            max = *p;
            result = &cust;
        }
    }

    return result;
}

void processPurchase() {
    UTString purString;
    readString(purString);
    UTString purString2;
    readString(purString2);
    int purInt;
    readNum(purInt);

    if(purString2 == "Bottles"){
        if(purInt <= num_bottles){
            num_bottles = num_bottles - purInt;
            database[purString].bottles += purInt;
        }
    }
    else if(purString2 == "Rattles"){
        if(purInt <= num_rattles){
            num_rattles = num_rattles - purInt;
            database[purString].rattles += purInt;
        }
    }
    else if(purString2 == "Diapers"){
        if(purInt <= num_diapers){
            num_diapers = num_diapers - purInt;
            database[purString].diapers += purInt;
        }
    }
    //std::cout << database[purString].name.c_str() << std::endl;

    // not done, your effort goes here
}

void processSummarize() {

    std::cout << "There are " << num_bottles << " Bottles, " << num_diapers << " Diapers and " << num_rattles << " Rattles in inventory" << std::endl;
    std::cout << "we have had a total of " << database.size() << " different customers" << std::endl;
    if(findMax("Bottles") != NULL){
        std::cout << findMax("Bottles")->name.c_str() << " has purchased the most Bottles (" << findMax("Bottles")->bottles << ")" << std::endl;
    } else {
        std::cout << "no one has purchased any Bottles" << std::endl;
    }
    if(findMax("Diapers") != NULL){
        std::cout << findMax("Diapers")->name.c_str() << " has purchased the most Diapers (" << findMax("Diapers")->diapers << ")" << std::endl;
    } else {
        std::cout << "no one has purchased any Diapers" << std::endl;
    }
    if(findMax("Rattles") != NULL){
        std::cout << findMax("Rattles")->name.c_str() << " has purchased the most Rattles (" << findMax("Rattles")->rattles << ")" << std::endl;
    } else {
        std::cout << "no one has purchased any Rattles" << std::endl;
    }
}

void processInventory() {
    UTString invString;
    readString(invString);
    //std::cout << invString.c_str() << std::endl;
    int count;
    readNum(count);
    //std::cout << count << std::endl;
    if(invString == "Bottles"){
        num_bottles = count;
    }
    else if(invString == "Rattles"){
        num_rattles = count;
    }
    else if(invString == "Diapers"){
        num_diapers = count;
    }
    // not done, your effort goes here
}
