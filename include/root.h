#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>
#include "matrix_utility.h"
#include "test.h"

#define FP double

static size_t M = 1000;
static size_t N = 3000;
static size_t K = 4500;
static std::string file_src = "AB_matrix.txt";