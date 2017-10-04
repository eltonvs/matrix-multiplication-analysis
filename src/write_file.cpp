#include <iostream>
#include <cmath>

#include <fstream>
using std::ofstream;

#include "write_file.h"

WriteFile::WriteFile(string size, int n_threads) {
    string type_s = n_threads ? "conc_" + to_string(n_threads) : "seq";
    result_file = "data/results/C" + size + "x" + size + "_" + type_s + ".txt";
    metrics_file = "data/metrics/" + size + "_" + type_s + ".txt";
}

WriteFile::~WriteFile() {}

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
