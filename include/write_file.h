/**
 * @file    write_file.h
 * @brief   Definition of WriteFile class
 * @date    05/10/2017
 */
#ifndef WRITE_FILE_H
#define WRITE_FILE_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "macros.h"

/**
 * @class WriteFile write_file.h
 * @brief Class that writes resulting data of matrix multiplication to files  
 */
class WriteFile {
 private:
    string result_file;
    string metrics_file;

 public:
    WriteFile(string size, int type);
    ~WriteFile();
    void write_result_matrix(matrix matrix_result);
    void write_metrics(timing runtimes);
};

#endif
