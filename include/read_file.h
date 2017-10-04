#ifndef READ_FILE_H
#define READ_FILE_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::stoi;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include "macros.h"

class ReadFile {
 private:
    ifstream file_a;
    ifstream file_b;
    string file_a_name;
    string file_b_name;
 public:
    ReadFile(string size);
    ~ReadFile();
    matrix get_matrix_a();
    matrix get_matrix_b();
};

#endif
