// Set <Project5.cpp>
// EE 312 Project 5 submission by
// Kevin Tong
// kyt259
// Slip days used: <0>
// Fall 2021

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Set.h"

/*
 * Several of the required functions have been written already
 * You may use these functions as-is or you may modify them in any way.
 * Please NOTE, you are responsible for ensuring that the functions work correctly in
 * your project solution. Just because the function works correctly in my solution does
 * NOT mean that the function will work correctly in yours.
 */

/*
 * Design NOTES:
 *
 * The design provided in this starter kit assumes
 * (1) empty sets will be represented with length == 0 and elements == nullptr (i.e., address 0)
 * (2) amortized doubling is not used, and capacity is ignored/unused. Functions should assume that
 * the amount of storage available in the elements[] array is equal to length
 */



/* done for you already */
void destroySet(Set* self) {
    free(self->elements);
}

/* done for you already */
void createEmptySet(Set* self) {
    self->len = 0;
    self->elements = nullptr;
}

/* done for you already */
void createSingletonSet(Set* self, int x) {
    self->elements = (int*) malloc(sizeof(int));
    self->elements[0] = x;
    self->len = 1;
}

/* done for you already */
void createCopySet(Set* self, const Set* other) {
    self->elements = (int*) malloc(other->len * sizeof(int));
    for (int k = 0; k < other->len; k += 1) {
        self->elements[k] = other->elements[k];
    }
    self->len = other->len;
}

/* done for you already */
void assignSet(Set* self, const Set* other) {
    if (self == other) { return; }

    destroySet(self);
    createCopySet(self, other);
}

/* return true if x is an element of self */
bool isMemberSet(const Set* self, int x) {
    for(int i = 0; i < self->len; i++){
        if(self->elements[i] == x){
            return true;
        }
    }
    return false;
}

/*
 * add x as a new member to this set.
 * If x is already a member, then self should not be changed
 * Be sure to restore the design invariant property that elemnts[] remains sorted
 * (yes, you can assume it is sorted when the function is called, that's what an invariant is all about)
 */
void insertSet(Set* self, int x) {
    if(isMemberSet(self, x) == false){
        self->len++;
        self->elements = (int*)realloc(self->elements, sizeof(int) * self->len);
        int j = self->len - 1;
        self->elements[j] = x;
        while(j > 0 && self->elements[j-1] > self->elements[j]){
            int temp = self->elements[j];
            self->elements[j] = self->elements[j-1];
            self->elements[j-1] = temp;
            j--;
        }
    }
}


/*
 * don't forget: it is OK to try to remove an element
 * that is NOT in the set.
 * If 'x' is not in the set 'self', then
 * removeSet should do nothing (it's not an error)
 * Otherwise, ('x' IS in the set), remove x. Be sure to update self->length
 * It is not necessary (nor recommended) to call malloc -- if removing an element means the
 * array on the heap is "too big", that's almost certainly OK, and reallocating a smaller array
 * is almost definitely NOT worth the trouble
 */
void removeSet(Set* self, int x) {
    if(isMemberSet(self, x) == true){
        int index;
        for(int i = 0; i < self->len; i++){
            if(self->elements[i] == x){
                index = i;
            }
        }
        for(int i = index; i < self->len - 1; i++){
            self->elements[i] = self->elements[i + 1];
        }
        self->elements[self->len - 1] = '\0';
        self->len--;
    }
}

/* done for you already */
void displaySet(const Set* self) {
    int k;

    printf("{");

    if (self->len == 0) {
        printf("}");
    }
    else {
        for (k = 0; k < self->len; k += 1) {
            if (k < self->len - 1) {
                printf("%d,", self->elements[k]);
            } else {
                printf("%d}", self->elements[k]);
            }
        }
    }
}

/* return true if self and other have exactly the same elements */
bool isEqualToSet(const Set* self, const Set* other) {
    int count = 0;
    if(self->len == other->len){
        for(int i = 0; i < self->len; i++){
            if(self->elements[i] == other->elements[i]){
                count++;
            }
        }
        if (count == self->len){ //not sure ab this one
            return true;
        }
    }
    return false;
}

/* return true if every element of self is also an element of other */
bool isSubsetOf(const Set* self, const Set* other) {
    int count = 0;
    if(self->len == 0){
        return true;
    }
    if(self->len > 0 && self->len <= other->len){
        for(int i = 0; i < other->len; i++){
            if (self->elements[count] == other->elements[i]){
                count++;
            }
            if (count == self->len){
                return true;
            }
        }
    }
    return false;
}

/* done for you */
bool isEmptySet(const Set* self) {
    return self->len == 0;
}

/* remove all elements from self that are not also elements of other */
void intersectFromSet(Set* self, const Set* other) {
    int i = 0;
    int j = 0;
    int* remove = (int*)malloc(sizeof(int) * self->len * 3);
    int z = 0;
    if(self->len == 0){
        return;
    }
    if(other->len == 0){
        int asd = self->len;
        for(int i = 0; i < asd; i++){
            removeSet(self, self->elements[0]);
        }
        return;
    }
    if((self->elements[0] > other->elements[other->len - 1]) || (self->elements[self->len - 1] < other->elements[0])){
        self->elements[0] = '\0';
        self->len = 0;
    } else {
        while(i < self->len && j < other->len){
            while(self->elements[i] > other->elements[j]){
                j++;
            }
            if(self->elements[i] != other->elements[j]){
                remove[z] = self->elements[i];
                z++;
            }
            i++;
        }
        while(i < self->len){
            remove[z] = self->elements[i];
            z++;
            i++;
        }

    }
    if(z == self->len){
        self->elements[0] = '\0';
        self->len = 0;
    }else{
        for(int i = 0; i < z; i++){
            removeSet(self, remove[i]);
        }
    }
    free(remove);
}

/* remove all elements from self that are also elements of other */
void subtractFromSet(Set* self, const Set* other) {
    int i = 0;
    int j = 0;
    int* remove = (int*)malloc(sizeof(int) * self->len);
    int z = 0;

    if(self->len == 0 || other->len == 0){
        return;
    }

    while( i < self->len && j < other->len){
        if(self->elements[i] == other->elements[j]){
            remove[z] = self->elements[i];
            z++;
            i++;
            j++;
        }
        else if(self->elements[i] < other->elements[j]){
            i++;
        }
        else if(self->elements[i] > other->elements[j]){
            j++;
        }
    }

    if(z == self->len){
        self->elements[0] = '\0';
        self->len = 0;
    }else{
        for(int i = 0; i < z; i++){
            removeSet(self, remove[i]);
        }
    }
    free(remove);
}

/* add all elements of other to self (obviously, without creating duplicate elements) */
void unionInSet(Set* self, const Set* other) {
    int* duplicate = (int*)malloc(sizeof(int) * other->len);
    int i = 0;
    int j = 0;
    int z = 0;
    if(other->len == 0){
        return;
    }
    if(self->len == 0){
        for(int asd = 0; asd < other->len; asd++){
            insertSet(self, other->elements[asd]);
        }
        return;
    }
    if((self->elements[0] > other->elements[other->len - 1]) || (self->elements[self->len - 1] < other->elements[0])){
        for(int asd = 0; asd < other->len; asd++){
            insertSet(self, other->elements[asd]);
        }
        return;
    }
    while( i < self->len || j < other->len){
        if(self->elements[i] == other->elements[j]){
            duplicate[z] = other->elements[i];
            z++;
            i++;
            j++;
        }
        else if(self->elements[i] < other->elements[j]){
            i++;
        }
        else if(self->elements[i] > other->elements[j]){
            j++;
        }
    }

    j = 0;
    z = 0;
    while (j < other->len){
        if(other->elements[j] == duplicate[z]){
            z++;
            j++;
        } else {
            insertSet(self, other->elements[j]);
            j++;
        }
    }
    free(duplicate);
}
