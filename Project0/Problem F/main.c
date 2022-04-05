#include <stdio.h>

int gcd(int x, int y){
    int smaller;
    int larger;
    int gcd_ = 0;
    if( x < y ){
        smaller = x;
        larger = y;
    }
    else if( y < x ){
        smaller = y;
        larger = x;
    }
    else{
        smaller = x;
        larger = y;
    }
    for (int i = 1; i <= smaller; i++){
        if (smaller % i == 0){
            if (larger % i == 0){
                gcd_ = i;
            }
        }
    }
    return gcd_;
}

int main() {

    printf("GCD of 48 and 18 is: %d\n", gcd(48, 18));
    printf("GCD of 144 and 60 is: %d\n", gcd(144, 60));
    printf("GCD of 65 and 12 is: %d\n", gcd(65, 12));
    printf("GCD of 179 and 7 is: %d\n", gcd(179, 7));

}
