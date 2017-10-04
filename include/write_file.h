#ifndef WRITE_FILE_H
#define WRITE_FILE_H

#include <fstream>
using std::ofstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "macros.h"

class WriteFile {
 private:
    string result_file;
    string metrics_file;

 public:
    WriteFile(string size, int type);
    ~WriteFile();
    void write_result_matrix(vector<vector<int>> matrix_result);
};

#endif
