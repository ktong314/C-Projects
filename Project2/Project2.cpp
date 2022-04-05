/* Project2.cpp
 * Kevin Tong
 * EE312, Fall 2021
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
    /*int b_rows = a_cols;
    int c_rows = a_rows;*/
    int c_cols = b_cols;
    int i = 0;
    while(i < a_rows){
        int j = 0;
        while(j < b_cols){
            int k = 0;
            c[i * c_cols + j] = 0;
            while(k < a_cols){
                c[i * c_cols + j] = c[i * c_cols + j] + a[i * a_cols + k] * b[k * b_cols + j];
                k++;
            }
            j++;
        }
        i++;
    }

    // https://en.wikipedia.org/wiki/Row-_and_column-major_order
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {
    int b_rows = a_cols;
    int c_rows = a_rows;
    int c_cols = b_cols;
    double** c;
    c = (double**)malloc(sizeof(double) * c_rows);
    for( int x = 0; x < c_cols; x++) {
        *(c + x) = (double *)malloc(sizeof(double) * c_cols);
    }


/*    for(int i = 0; i < a_rows; i++){
        for(int j = 0; j < a_cols; j++){
            printf("%.1f ", a[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < a_rows; i++){
        for(int j = 0; j < a_cols; j++){
            printf("%.1f ", b[i][j]);
        }
        printf("\n");
    }*/

    int i = 0;
    while(i < a_rows){
        int j = 0;
        while(j < b_cols) {
            int k = 0;
            c[i][j] = 0.0;
            while (k < a_cols) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
                k++;
            }
            j++;
        }
        i++;
    }
    return c;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {
    double** c;
    c = (double**)malloc(sizeof(double) * a_cols);
    for( int x = 0; x < a_cols; x++) {
        *(c + x) = (double *)malloc(sizeof(double) * a_rows);
    }
    int i = 0;
    while(i < a_cols){
        int j = 0;
        while(j < a_rows) {
            c[i][j] = a[j][i];
            j++;
        }
        i++;
    }
    return c;
}
