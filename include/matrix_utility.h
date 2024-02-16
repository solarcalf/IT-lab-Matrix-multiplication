#pragma once
#include "root.h"

void set_params(int argc, char* argv[], size_t& M, size_t& N, size_t& K, std::string& src);
void set_matrix(FP **A, size_t M, size_t N, std::string src);
void set_matrixes(FP **A, FP **B, size_t M, size_t N, size_t K, std::string src);
void print(FP *A, size_t M, size_t N);
void fprint(FP *A, size_t M, size_t N, std::string dest);