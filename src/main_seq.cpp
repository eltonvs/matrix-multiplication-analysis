#include <iostream>
using std::cout;
using std::endl;

#include <chrono>
using namespace std::chrono;
using std::milli;

#include "read_file.h"
#include "write_file.h"
#include "mat_mult_seq.h"

#define N_EXECUTIONS 20

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Error" << endl;
        exit(EXIT_FAILURE);
    }

    ReadFile rf(argv[1]);
    WriteFile wf(argv[1], 0);

    int size = stoi(argv[1]);
    matrix a = rf.get_matrix_a();
    matrix b = rf.get_matrix_b();
    matrix c(size, vector<int>(size, 0));

    vector<long double> runtimes;
    for (int i = 0; i < N_EXECUTIONS; ++i) {
        auto s = steady_clock::now();
        seq_multiply(size, a, b, c);
        auto e = steady_clock::now();
        auto diff = duration <double, milli> (e - s).count();
        runtimes.push_back(diff);
    }

    wf.write_result_matrix(c);
    wf.write_metrics(runtimes);

    return 0;
}
