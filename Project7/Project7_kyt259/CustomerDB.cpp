// CRM in C++ <filename.cpp>
// EE 312 Project 7 submission by
// Kevin Tong
// kyt259
// Slip days used: <0>
// Fall 2021

#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) { // not done, your effort goes here
    for(int i = 0; i < length; i++){
        if(data[i].name == name){
            return data[i];
        }
    }
    if (length < capacity){
        data[length] = Customer(name);
        length++;
        return data[length - 1];
    } else {
        capacity = capacity*2;
        Customer* newData = new Customer[capacity];
        for(int i = 0; i < length; i++) {
            newData[i].name = data[i].name;
            newData[i].bottles = data[i].bottles;
            newData[i].diapers = data[i].diapers;
            newData[i].rattles = data[i].rattles;
        }
        delete[] data;
        data = newData;
        data[length] = Customer(name);
        length++;
        return data[length - 1];
    }
}

bool CustomerDB::isMember(UTString name) { // not done, your effort goes here
    for(int i = 0; i < length; i++){
        if(data[i].name == name){
            return true;
        }
    }
    return false;
}
