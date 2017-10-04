#include <chrono>
using namespace std::chrono;
using std::milli;

#include <functional>
using std::ref;

#include "mat_mult_seq.h"

void seq_multiply(matrix a, matrix b, matrix &c) {

    for (auto i = 0u; i < a.size(); ++i) {
        for (auto j = 0u; j < b.size(); ++j) {
            int sum = 0;
            for (auto k = 0u; k < c.size(); ++k) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

void seq_time_measurement(matrix a, matrix b, matrix &c, timing &runtimes) {

    for (int i = 0; i < N_EXECUTIONS; ++i) {
        auto s = steady_clock::now();
        seq_multiply(a, b, ref(c));
        auto e = steady_clock::now();
        auto diff = duration <double, milli> (e - s).count();
        runtimes.push_back(diff);
    }
}
