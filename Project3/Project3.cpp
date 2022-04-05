/*
 // String ADT <Project3.cpp>
// EE 312 Project 3 submission by
// Kevin Tong
// kyt259
// Slip days used: <0>
// FALL 2021
// Copy and paste this file at the top of all your submitted source code files.  Do not turn this in by itself.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "UTString.h"

/*
 * Helper macro to find the signature of a UTString
 * Treat this like a function that takes a UTString*
 * Accesses a uint32_t from where the signature should be located
 */
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
 * Checks if a UTString is valid or not.
 */
bool isOurs(const UTString* s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}

/*
 * Allocate a utstring on the heap.
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */
UTString* utstrdup(const char* src) {
    UTString* ptr;
    ptr = (UTString*)malloc(sizeof(UTString));
    ptr->string = (char*)malloc(strlen(src) + 5);
    strcpy(ptr->string, src);
    ptr->length = strlen(src);
    ptr->capacity = strlen(src);
    CHECK(ptr) = SIGNATURE;
    return ptr;
}

/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */
uint32_t utstrlen(const UTString* s) {
    assert(isOurs(s));
    return s->length;
}

/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s.
 * Update the length of s.
 * Return s with the above changes. */
UTString* utstrcat(UTString* s, const char* suffix) {
    assert(isOurs(s));

    //char *str1 = s->string;
    int suffixLength = 0;
    while(suffix[suffixLength] != 0x00){
        suffixLength++;
    }
    if(suffixLength + s->length > s->capacity){
        suffixLength = s->capacity - s->length;
    }
    //int str1Length = s->length;
    int x = 0;
    while(suffix[x] != 0x00){
        s->string[s->length] = suffix[x];
        x++;
        s->length++;
        if(s->length >= s->capacity){
            break;
        }
    }

/*    for(int i = 0; i <= suffixLength; i++){
        s->string[s->length] = suffix[i];
        s->length++;
    }*/
    s->string[s->length] = 0x00;
/*
    strncat(s->string, suffix, s->capacity - s->length);
    s->length = s->length + suffixLength;
    if(s->length > s->capacity){
        s->length = s->capacity;
    }*/
    CHECK(s) = SIGNATURE;
    return s;
}

/*
 * Copy src into dst.
 *  dst must be a valid UTString.
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst.
 * Return dst with the above changes.
 */
UTString* utstrcpy(UTString* dst, const char* src) {
    assert(isOurs(dst));
    strncpy(dst->string, src, dst->capacity);
    if(strlen(src) >= dst->capacity){
        dst->length = dst->capacity;
    }
    else{
        dst->length = strlen(src);
    }
    (*(uint32_t*) ((dst)->string + (dst)->length)) = 0x00;
    CHECK(dst) = SIGNATURE;

    return dst;
}

/*
 * Free all memory associated with the given UTString.
 */
void utstrfree(UTString* self) {
    assert(isOurs(self));
    free(self->string);
    free(self);
}

/*
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity,
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata.
 * Return s with the above changes.
 */
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    assert(isOurs(s));
    if(s->capacity < new_capacity){
        char* ptr;
        ptr = (char*) malloc(new_capacity + 5);
        strcpy(ptr, s->string);
        free(s->string);
        s->string = ptr;
        s->capacity = new_capacity;
        CHECK(s) = SIGNATURE;
    }
    return s;
}
