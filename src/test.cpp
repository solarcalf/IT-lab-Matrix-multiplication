#include "..\include\includes.h"

std::pair<FP, bool> test(size_t M, size_t N, size_t K, MethodPointer method, size_t test_num) {

    FP *A, *B, *correct_C;
    FP *C = (FP*)malloc(M * K * sizeof(FP));

    std::string dir_path = "..\\test\\test_data_" + std::to_string(test_num) + "\\";

    set_matrix(&A, M, N, dir_path + "A.npy");
    set_matrix(&B, N, K, dir_path + "B.npy");
    set_matrix(&correct_C, M, K, dir_path + "C.npy");

    auto start = std::chrono::high_resolution_clock::now();
    method(A, B, C, M, N, K);
    auto end = std::chrono::high_resolution_clock::now();
    FP elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    for (size_t i = 0; i < M * K; ++i) 
        if (abs(C[i] - correct_C[i]) > 0.1)
            return {elapsed_time, 0};
    
    free(A); free(B); free(C); free(correct_C);

    return {elapsed_time, 1};
}

void test_all(MethodPointer method) {
    size_t tests_amount = 5;
    size_t M[]{100, 347, 1000, 1000, 5000};
    size_t N[]{100, 987, 1000, 10000, 10000};
    size_t K[]{100, 297, 1000, 1000, 1000};

    for (size_t i = 0; i < tests_amount; ++i) {
        auto [time, correct] = test(M[i], N[i], K[i], method, i + 1);
        std::cout << "Test " << i + 1 << ": time: " << time << " correct: " << correct << '\n';
    }
};