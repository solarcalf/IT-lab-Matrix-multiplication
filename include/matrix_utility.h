#pragma once

#include <string>
#define FP double

void set_params(int argc, char* argv[]);
void set_matrixes_separately(FP **A, FP **B, std::string src);
void set_matrixes(FP **A, FP **B);
void print(size_t m, size_t n, FP *A);
void fprint(size_t m, size_t n, FP *A, std::string dest);