/**
 * @file  mat_mult_conc.cpp
 * @brief Implements functions of the concurrent version of a matrix multiplication    
 * @date  05/10/2017
 */
#include <chrono>
using namespace std::chrono;
using std::milli;

#include <cmath>
using std::round;

#include <functional>
using std::ref;

#include <thread>
using std::thread;
#include "mat_mult_conc.h"

/**
 * @brief Multiplies a specific part of a matrix
 * @param a Matrix of integers
 * @param b Matrix of integers
 * @param c Matrix of integers
 * @param init Initial line of matrix section 
 * @param end Final line of matrix section   
 */
void conc_multiply_part(matrix a, matrix b, matrix &c, unsigned init, unsigned end) {

    for (auto i = init; i < end; ++i) {
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
 * @brief Uses threads to multiply fractions of matrixes       
 * @param a Matrix of integers 
 * @param b Matrix of integers
 * @param c Matrix of integers
 * @param n_threads Number of threads to be used in a matrix multiplication    
 */
void conc_multiply(matrix a, matrix b, matrix &c, unsigned n_threads) {
    vector<thread> threads;
    n_threads = n_threads < a.size() ? n_threads : a.size();
    unsigned fraction = round(a.size()/n_threads);
    unsigned init = 0, end = 0;

    for (auto i = 0u; i < n_threads; ++i) {
        init = i*fraction;
        end = init + fraction;
        if (i == n_threads - 1) {
            end = a.size();
        }
        threads.push_back(thread(conc_multiply_part, a, b, ref(c), init, end));
    }
    for (auto i = 0u; i < threads.size(); ++i) {
        threads[i].join();
    }
}

/**
 * @brief Measures time of execution of matrix multiplication
 * @param a Matrix of integers
 * @param b Matrix of integers
 * @param c Matrix of integers
 * @param n_threads Number of threads to be used in a matrix multiplication
 * @param runtimes Vector that stores runtime of each multiplication    
 */
void conc_time_measurement(matrix a, matrix b, matrix &c, int n_threads, timing &runtimes) {

    for (int i = 0; i < N_EXECUTIONS; ++i) {
        auto s = steady_clock::now();
        conc_multiply(a, b, c, n_threads);
        auto e = steady_clock::now();
        auto diff = duration <double, milli> (e - s).count();
        runtimes.push_back(diff);
    }
}
