#include <stdio.h>

void printMultTableInt(int n);
void printMultTableFrac(int n);

int main(void){

    // You can change this to test your code
    int size = 10;

    printMultTableInt(size);
    printMultTableFrac(size);

    return 0;

}

// Prints multiplication table of integers from 1 to n
void printMultTableInt(int n){

    for( int x = 1; x <= n; x++){
        for (int y = 1; y <= n; y++){
            printf("%d ", y*x);
        }
        printf("\n");
    }

}

// Prints multiplication table for fractions from 1, 1/2, 1/3 to 1/n
void printMultTableFrac(int n){

    for( double x = 1; x <= n; x++){
        for (double y = 1; y <= n; y++){
            printf("%.2f ", 1/(x*y));
        }
        printf("\n");
    }

}
