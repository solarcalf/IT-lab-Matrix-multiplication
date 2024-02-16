#pragma once

//#define FP double
typedef double FP;

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>

typedef void* (*MethodPointer)(FP* A, FP* B, FP* C, size_t M, size_t N, size_t K);