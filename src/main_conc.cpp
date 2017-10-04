#include <iostream>
using std::cout;
using std::endl;

#include <functional>
using std::ref;

#include "read_file.h"
#include "write_file.h"
#include "mat_mult_conc.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Error" << endl;
        exit(EXIT_FAILURE);
    }

    int size = stoi(argv[1]);
    int n_threads = stoi(argv[2]);

    ReadFile rf(argv[1]);
    WriteFile wf(argv[1], n_threads);

    matrix a = rf.get_matrix_a();
    matrix b = rf.get_matrix_b();
    matrix c(size, vector<int>(size, 0));

    timing runtimes;
    conc_time_measurement(a, b, ref(c), n_threads, runtimes);

    wf.write_result_matrix(c);
    wf.write_metrics(runtimes);

    return 0;
}
