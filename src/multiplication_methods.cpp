#include "..\include\includes.h"

void naive_matrix_mult(FP *A, FP *B, FP *C, size_t M, size_t N, size_t K) {
    for (size_t i = 0; i < M; ++i)
        for (size_t j = 0; j < K; ++j) {
            C[i * K + j] = 0;
            for (size_t k = 0; k < N; ++k) 
                C[i * K + j] += A[i * N + k] * B[K * k + j];
        }
}

void transposed_nmm(FP *A, FP *B, FP *C, size_t M, size_t N, size_t K) {
    memset(C, 0, M * K * sizeof(FP));

    for (size_t i = 0; i < M; ++i)
        for (size_t k = 0; k < N; ++k)
            for (size_t j = 0; j < K; ++j) 
                C[i * K + j] += A[i * N + k] * B[K * k + j];
        
}