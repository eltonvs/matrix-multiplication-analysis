/**
 * @file  mat_mult_seq.cpp
 * @brief Implements functions of the sequential version of a matrix multiplication    
 * @date  05/10/2017
 */
#include <chrono>
using namespace std::chrono;
using std::milli;

#include <functional>
using std::ref;

#include "mat_mult_seq.h"

/**
 * @brief Multiplies matrixes sequentially 
 * @param a Matrix of integers
 * @param b Matrix of integers
 * @param c Matrix of integers 
 */
void seq_multiply(matrix a, matrix b, matrix &c) {

    for (auto i = 0u; i < a.size(); ++i) {
        for (auto j = 0u; j < b.size(); ++j) {
            int sum = 0;
            for (auto k = 0u; k < c.size(); ++k) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

/**
 * @brief Measures time of execution of matrix multiplication 
 * @param a Matrix of integers  
 * @param b Matrix of integers 
 * @param c Matrix of integers 
 * @param runtimes Vector that stores runtime of each multiplication     
 */
void seq_time_measurement(matrix a, matrix b, matrix &c, timing &runtimes) {

    for (int i = 0; i < N_EXECUTIONS; ++i) {
        auto s = steady_clock::now();
        seq_multiply(a, b, ref(c));
        auto e = steady_clock::now();
        auto diff = duration <double, milli> (e - s).count();
        runtimes.push_back(diff);
    }
}
