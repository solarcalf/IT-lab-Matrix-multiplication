#include "..\include\includes.h"

// Reading params from terminal run
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

void set_matrixes_separately(FP **A, FP **B, std::string src) {
    *A = (FP*)malloc(M * N * sizeof(FP));
    *B = (FP*)malloc(N * K * sizeof(FP));

    std::string A_src = src + "A.npy";
    std::string B_src = src + "B.npy";

    FP value;
    std::ifstream file(A_src, std::ios::binary);

    for (size_t i = 0; i < M * N; ++i) {
        file.read(reinterpret_cast<char*>(&value), sizeof(FP));
        (*A)[i] = value;
    }

    file.close();
    file.open(B_src, std::ios::binary);
    
    for (size_t i = 0; i < N * K; ++i) {
        file.read(reinterpret_cast<char*>(&value), sizeof(FP));
        (*B)[i] = value;
    }
}

void set_matrixes(FP **A, FP **B) {
    *A = (FP*)malloc(M * N * sizeof(FP));
    *B = (FP*)malloc(N * K * sizeof(FP));

    std::ifstream file;
    file.open(file_src);

    std::string num_str;
    double num;

    // Filling A matrix
    for (size_t i = 0; i < M * N; ++i) {
        file >> num_str;
        num = std::stod(num_str);
        (*A)[i] = num;
    }

    // Filling B matrix
    for (size_t i = 0; i < N * K; ++i) {
        file >> num_str;
        num = std::stod(num_str);
        (*B)[i] = num;
    }

    file.close();
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
