#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>
#include <windows.h>
#define FP double

size_t M = 1000;
size_t N = 3000;
size_t K = 4500;

std::string file_src = "AB_matrix.txt";
// std::string file_src = "mat.txt";

void set_params(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.find("M=") == 0 || arg.find("m=") == 0) {
            M = std::stoi(arg.substr(2));
        } 
        else if (arg.find("N=") == 0 || arg.find("n=") == 0) {
            N = std::stoi(arg.substr(2));
        } 
        else if (arg.find("K=") == 0 || arg.find("k=") == 0) {
            K = std::stoi(arg.substr(2));
        }
        else if (arg.find("src=") == 0) {
            file_src = (arg.substr(4));
        }
    }
}

void set_matrixes(FP **A, FP **B) {
    *A = (FP*)malloc(M * N * sizeof(FP));
    *B = (FP*)malloc(N * K * sizeof(FP));

    std::ifstream file;
    file.open(file_src);

    std::string num_str;
    double num;

    for (size_t i = 0; i < M * N; ++i) {
        file >> num_str;
        num = std::stod(num_str);
        (*A)[i] = num;
    }

    for (size_t i = 0; i < N * K; ++i) {
        file >> num_str;
        num = std::stod(num_str);
        (*B)[i] = num;
    }

    file.close();
}

void naive_matrix_mult(FP *A, FP *B, FP *C) {
    for (size_t i = 0; i < M; ++i)
        for (size_t j = 0; j < K; ++j) {
            C[i * K + j] = 0;
            for (size_t k = 0; k < N; ++k) 
                C[i * K + j] += A[i * N + k] * B[K * k + j];
        }
}

void transposed_nmm(FP *A, FP *B, FP *C) {
    
    memset(C, 0, M * K * sizeof(FP));

    for (size_t i = 0; i < M; ++i)
        for (size_t k = 0; k < N; ++k)
            for (size_t j = 0; j < K; ++j) 
                C[i * K + j] += A[i * N + k] * B[K * k + j];
        
}

void print(size_t m, size_t n, FP *A) {
    
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j)
            std::cout << A[i * n + j] << ' ';
        std::cout << '\n';
    }
}

void fprint(size_t m, size_t n, FP *A, std::string dest) {
    
    std::ofstream file;
    file.open(dest);

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j)
            file << A[i * n + j] << ' ';
        file << '\n';
    }

    file.close();
}

int main(int argc, char* argv[]) {
    
    FP *A, *B;

    set_params(argc, argv);
    set_matrixes(&A, &B);

    FP *C = (FP*)malloc(M * K * sizeof(FP));

    double t1, t2, dt;

    auto start = std::chrono::high_resolution_clock::now();

    // naive_matrix_mult(A, B, C);
    transposed_nmm(A, B, C);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed time: " << elapsed_time.count() << " milliseconds" << std::endl;


    // print(M, N, A);
    // print(N, K, B);
    // print(M, K, C);

    fprint(M, K, C, "PROGRAMM_C_RES.txt");

    free(A);
    free(B);
    free(C);

    return 0;
}