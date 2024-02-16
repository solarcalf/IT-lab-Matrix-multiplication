#include "..\include\includes.h"

int main(int argc, char* argv[]) {

    FP *A, *B;

    set_params(argc, argv);
    set_matrixes(&A, &B);

    FP *C = (FP*)malloc(M * K * sizeof(FP));

    auto start = std::chrono::high_resolution_clock::now();

    // naive_matrix_mult(A, B, C);
    transposed_nmm(A, B, C);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed time: " << elapsed_time.count() << " milliseconds" << '\n';

    // For small matrixes
    // print(M, N, A);
    // print(N, K, B);
    // print(M, K, C);

    fprint(M, K, C, "PROGRAMM_C_RES.txt");

    free(A);
    free(B);
    free(C);

    return 0;
}