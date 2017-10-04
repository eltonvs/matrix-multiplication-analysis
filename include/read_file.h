#ifndef READ_FILE_H
#define READ_FILE_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

class ReadFile {
 private:
 	ifstream file_a;
 	ifstream file_b;
 	string file_a_name;
 	string file_b_name;
 public:
 	ReadFile(string size);
 	~ReadFile();
 	vector<vector<int>> get_matrix_a();
 	vector<vector<int>> get_matrix_b();
};

#endif