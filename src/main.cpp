#include "..\include\includes.h"

int main(int argc, char* argv[]) {

    // test_all((MethodPointer)&transposed_nmm);
    // test_all((MethodPointer)&naive_matrix_mult);

    size_t M = 3, N = 3, K = 1;

    FP *A, *B, *C_cor;
    set_matrix(&A, M, N, "..\\test\\test_data_6\\A.npy");
    set_matrix(&B, N, K, "..\\test\\test_data_6\\B.npy");
    set_matrix(&A, M, K, "..\\test\\test_data_6\\C.npy");

    print(A, M, N);
    print(B, N, K);
    print(C_cor, M, K);

    return 0;
}