#pragma once
#include "root.h"
void naive_matrix_mult(FP *A, FP *B, FP *C, size_t M, size_t N, size_t K);
void transposed_nmm(FP *A, FP *B, FP *C, size_t M, size_t N, size_t K);