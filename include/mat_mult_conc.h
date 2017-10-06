/**
 * @file  mat_mult_conc.h
 * @brief Defines function headers of the concurrent version of a matrix multiplication  
 * @date  05/10/2017
 */
#ifndef MAT_MULT_CONC_H
#define MAT_MULT_CONC_H

#include "macros.h"

/**
 * @brief Multiplies a specific part of a matrix
 * @param a Matrix of integers
 * @param b Matrix of integers
 * @param c Matrix of integers
 * @param init Initial line of matrix section 
 * @param end Final line of matrix section   
 */
void conc_multiply_part(matrix a, matrix b, matrix &c, unsigned init, unsigned end);

/**
 * @brief Uses threads to multiply fractions of matrixes       
 * @param a Matrix of integers 
 * @param b Matrix of integers
 * @param c Matrix of integers
 * @param n_threads Number of threads to be used in a matrix multiplication    
 */
void conc_multiply(matrix a, matrix b, matrix &c, unsigned n_threads);

/**
 * @brief Measures time of execution of matrix multiplication
 * @param a Matrix of integers
 * @param b Matrix of integers
 * @param c Matrix of integers
 * @param n_threads Number of threads to be used in a matrix multiplication
 * @param runtimes Vector that stores runtime of each multiplication    
 */
void conc_time_measurement(matrix a, matrix b, matrix &c, int n_threads, timing &runtimes);

#endif
