#include "mat_mult_seq.h"

void seq_multiply(int size, matrix a, matrix b, matrix &c) {

	for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int sum = 0;
            for (int k = 0; k < size; ++k) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

