#include <iostream>
using std::cout;
using std::endl;

#include <chrono>
using namespace std::chrono;
using std::milli;

#include "read_file.h"
#include "write_file.h"
#include "mat_mult_seq.h"

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

    timing runtimes;
    seq_time_measurement(a, b, c, runtimes);

    wf.write_result_matrix(c);
    wf.write_metrics(runtimes);

    return 0;
}
