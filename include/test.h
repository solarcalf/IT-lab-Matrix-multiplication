#pragma once
#include "root.h"

std::pair<FP, bool> test(size_t M, size_t N, size_t K, MethodPointer method, size_t test_num);
void test_all(MethodPointer method);
