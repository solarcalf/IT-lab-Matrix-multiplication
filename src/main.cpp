#include "..\include\includes.h"

int main(int argc, char* argv[]) {

    test_all((MethodPointer)&transposed_nmm);
    // test_all((MethodPointer)&naive_matrix_mult);

    // size_t M = 3, N = 3, K = 1;

    // FP *A, *B, *C_cor;
    // set_matrix(&A, M, N, "..\\data\\test\\test_data_6\\A.bin");
    // set_matrix(&B, N, K, "..\\data\\test\\test_data_6\\B.bin");
    // set_matrix(&C_cor, M, K, "..\\data\\test\\test_data_6\\C.bin");

    // print(A, M, N);
    // print(B, N, K);
    // print(C_cor, M, K);

    // for (size_t i = 0; i < M * N; ++i)
    //     std::cout << A[i] << ' ';

    // return 0;
}