#include <iostream>

#include "write_file.h"

WriteFile::WriteFile(string size, int type) {
    string type_s = type ? "conc" : "seq";
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
        for (auto i : line) {
            result << i << " ";
        }
        result << "\n";
    }

    result.close();
}
