// matrix-multiplication Project2.cpp
// EE 312 Project 2 submission by
// Nishanth Navali
// nan686
// Slip days used: 0
// Spring 2020

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

    const uint32_t c_rows = a_rows; // Matrix product result of MxN * NxP is MxP
    const uint32_t c_cols = b_cols;

    // init sum variable and counters
    double sum = 0;
    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = 0;

    // loop through matricies
    while(i < c_rows) {
        while(j < c_cols) {
            while(k < a_cols) {
                sum += a[i * a_cols + k] * b[j + k * c_cols]; // go through row of a and col of b, multiply, and add to sum
                k++; // increment k
            }
            k = 0; // reset k
            c[i*c_cols + j] = sum; // set sum into product matrix
            sum = 0; // reset sum
            j++; // increment j
        }
        j = 0; // reset k
        i++; // increment i
    }
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {

    // init sum and counters
    double sum = 0;
    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = 0;

    // create array of pointers
    double **c_matrix = (double**) malloc(a_rows * sizeof(double));
    for(int i = 0; i < a_rows; i++) {
        c_matrix[i] = (double*) malloc(b_cols * sizeof(double)); // each element is a pointer to another array
    }

    // loop through matrix
    while(i < a_rows) {
        while(j < b_cols) {
            while(k < a_cols) {
                sum += a[i][k] * b[k][j]; // same logic as previous, except with 2D array
                k++;
            }
            k = 0;
            c_matrix[i][j] = sum; // set sum into output matrix
            j++;
            sum = 0;
        }
        j = 0;
        i++;
    }
    return c_matrix;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {


    double **t = (double**) malloc(a_cols * sizeof(double)); // create array of opposite dimentions
    for (int i = 0; i < a_cols; ++i) {
        t[i] = (double*) malloc(a_rows * sizeof(double)); // array of pointers pointing to other arrays (2D)
    }

    // init pointers
    uint32_t i = 0;
    uint32_t j = 0;

    // loop through matrix
    while(i < a_rows) {
        while(j < a_cols) {
            t[j][i] = a[i][j]; // flip j and i
            j++;
        }
        j = 0;
        i++;
    }
    return t;
}
