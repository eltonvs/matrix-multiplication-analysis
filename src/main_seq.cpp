#include <iostream>

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

    seq_multiply(size, a, b, c);
    wf.write_result_matrix(c);

    vector<long double> runtimes;
    wf.write_metrics(runtimes);

    return 0;
}
