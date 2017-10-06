/**
 * @file  write_file.cpp
 * @brief Implements methods defined in class WriteFile
 * @date  05/10/2017
 */
#include <iostream>
#include <cmath>

#include <fstream>
using std::ofstream;

#include "write_file.h"

/**
 * @brief   WriteFile constructor
 * @details Defines name and location of results/metrics files
 * @param   size String that contains the size of the resulting matrix
 * @param   type Integer that defines the type/version of matrix multiplication
 */
WriteFile::WriteFile(string size, int type) {
    string type_s = type ? "conc" : "seq";
    result_file = "data/results/C" + size + "x" + size + "_" + type_s + ".txt";
    metrics_file = "data/metrics/" + size + "_" + type_s + ".txt";
}

/**
 * @details Empty Destructor
 */
WriteFile::~WriteFile() {}

/**
 * @brief Writes values of resulting matrix to a file
 * @param matrix_result Resulting matrix of integers 
 */
void WriteFile::write_result_matrix(matrix matrix_result) {
    ofstream result;
    result.open(result_file);

    if (!result.is_open()) {
        std::cout << "Error writing file!\n";
    }

    for (auto line : matrix_result) {
        for (auto val : line) {
            result << val << " ";
        }
        result << "\n";
    }

    result.close();
}

/**
 * @brief   Writes metrics of matrix multiplication runtimes to a file
 * @details Calculates average time, variance and standard deviation of 
 *          the runtimes of a matrix multiplication and writes these values
 *          to a file
 * @param   runtimes Vector that stores runtime of each multiplication  
 */
void WriteFile::write_metrics(timing runtimes) {
    // Calculate Average Runtime
    long double average_time = 0;
    for (long double val : runtimes) {
        average_time += val/runtimes.size();
    }

    // Calculate Variance
    long double variance = 0;
    for (long double val : runtimes) {
        variance += pow(val - average_time, 2.0)/runtimes.size();
    }

    // Calculate Standard Deviation
    long double standard_dev = sqrt(variance);

    // Write to metrics file
    ofstream metrics;
    metrics.open(metrics_file);
    metrics << "Average runtime: " << average_time << "\n";
    metrics << "Variance: " << variance << "\n";
    metrics << "Standard deviation: " << standard_dev << "\n";
    metrics.close();
}
