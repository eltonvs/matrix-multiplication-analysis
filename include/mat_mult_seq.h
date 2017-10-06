/**
 * @file  mat_mult_seq.h
 * @brief Defines function headers of the sequential version of a matrix multiplication        
 * @date  05/10/2017
 */
#ifndef MAT_MULT_SEQ_H
#define MAT_MULT_SEQ_H

#include "macros.h"

/**
 * @brief Multiplies matrixes sequentially 
 * @param a Matrix of integers
 * @param b Matrix of integers
 * @param c Matrix of integers 
 */
void seq_multiply(int size, matrix a, matrix b, matrix &c);

/**
 * @brief Measures time of execution of matrix multiplication 
 * @param a Matrix of integers  
 * @param b Matrix of integers 
 * @param c Matrix of integers 
 * @param runtimes Vector that stores runtime of each multiplication     
 */
void seq_time_measurement(matrix a, matrix b, matrix &c, timing &runtimes);

#endif
