#include "read_file.h"

ReadFile::ReadFile(string size) {
    file_a_name = "data/A" + size + "x" + size + ".txt";
    file_b_name = "data/B" + size + "x" + size + ".txt";
}

ReadFile::~ReadFile() {

}

vector<vector<int>> ReadFile::get_matrix_a() {
    int size, height;
    file_a.open(file_a_name);

    if(!file_a.is_open()) {
        exit(EXIT_FAILURE);
    }

    file_a >> size >> height;
    vector<vector<int>> a(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
             file_a >> a[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
             cout << a[i][j] << " ";
        }
        cout << endl;
    }

    file_a.close();

    return a;
}

vector<vector<int>> ReadFile::get_matrix_b() {
    int size, height;
    file_b.open(file_b_name);

    if(!file_b.is_open()) {
        exit(EXIT_FAILURE);
    }

    file_b >> size >> height;
    vector<vector<int>> b(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
             file_b >> b[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
             cout << b[i][j] << " ";
        }
        cout << endl;
    }

    file_b.close();

    return b;
}