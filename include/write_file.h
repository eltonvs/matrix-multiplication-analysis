#ifndef WRITE_FILE_H
#define WRITE_FILE_H

#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

#include "macros.h"

class WriteFile {
 private:
    string result_file;
    string metrics_file;

 public:
    WriteFile(string size, int n_threads = 0);
    ~WriteFile();
    void write_result_matrix(matrix matrix_result);
    void write_metrics(timing runtimes);
};

#endif
