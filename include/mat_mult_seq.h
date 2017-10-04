#ifndef MAT_MULT_SEQ_H
#define MAT_MULT_SEQ_H

#include <chrono>
using namespace std::chrono;
using std::milli;

#include <vector>
using std::vector;

#include "macros.h"

void seq_multiply(int size, matrix a, matrix b, matrix &c);

void seq_time_measurement(matrix a, matrix b, matrix &c, timing &runtimes);

#endif
