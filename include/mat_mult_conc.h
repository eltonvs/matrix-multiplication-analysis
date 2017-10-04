#ifndef MAT_MULT_CONC_H
#define MAT_MULT_CONC_H

#include "macros.h"

void conc_multiply_part(matrix a, matrix b, matrix &c, unsigned init, unsigned end);

void conc_multiply(matrix a, matrix b, matrix &c, unsigned n_threads);

void conc_time_measurement(matrix a, matrix b, matrix &c, int n_threads, timing &runtimes);

#endif
