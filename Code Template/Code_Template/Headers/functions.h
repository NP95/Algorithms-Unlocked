/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef functions_h
#define functions_h
#include "static.h"
#include "constants.h"
#include "exceptions.h"

static string to_hex(unsigned char s) {
    stringstream ss;
    ss << hex << (int) s;
    return ss.str();
}

#ifdef HASH
static string sha256(string &line) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, line.c_str(), line.length());
    SHA256_Final(hash, &sha256);
    string output = "0x";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        output += to_hex(hash[i]);
    }
    return output;
}

static string double_sha256(string &line) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, line.c_str(), line.length());
    SHA256_Final(hash, &sha256);
    SHA256_Final(hash, &sha256);
    string output = "0x";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        output += to_hex(hash[i]);
    }
    return output;
}
#endif /* Hash */

static void fork_and_run(char * const args[]) {
    clock_t start = clock();
    pid_t processId;
    if ((processId = fork()) == 0) {
        if (execv(args[0], args) < 0) {
            throw FATAL_EXCEPTION("Program fork error --error.");
        }
    } else if (processId < 0) {
        throw FATAL_EXCEPTION("No fork --nofrk-error");
    } else {
        std::cerr << "Program ran sucessfully. " << 1.0 * (start - clock())/CLOCKS_PER_SEC << std::endl;
    }
}

char * const case_parameters[] = { "/bin/cp", "-r", "./Code/<name-of-file-here>", "./Code/testcase.txt", NULL};

static void copy_to_test_case(char * const args[] = case_parameters) {
    clock_t start = clock();
    pid_t processId;
    if ((processId = fork()) == 0) {
        if (execv(args[0], args) < 0) {
            throw FATAL_EXCEPTION("cp error --error.");
        }
    } else if (processId < 0) {
        throw FATAL_EXCEPTION("No fork --nofrk-error");
    } else {
        std::cerr << "Copied sucessfully. " << 1.0 * (start - clock())/CLOCKS_PER_SEC << std::endl;
    }
}

const uint64_t lr_mod  = 1000000003; // (10e9 + 3)

static uint64_t huge_mod_power(uint64_t base = 13, uint64_t power = 15)
{
    clock_t start_time;
    static uint64_t expo = base;
    while(power)
    {
        expo %= lr_mod;
        if (!(power & 1)){
            expo *= (expo % lr_mod);
            power >>= 1;
        } else {
            expo *= (base % lr_mod);
            --power;
        }
    }
    clock_t end_time = clock() - start_time;
    std::cerr << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
    return expo;
}

static std::vector<std::vector<uint64_t> > matrix (size_t row = 10000, size_t col = 10000, uint64_t value = 54774541)
{
    clock_t start_time;
    std::vector<std::vector<uint64_t> > mat;
    std::vector<uint64_t> dump(col, value);
    for(unsigned i = 0; i < row; i++){
        mat.emplace_back(dump);
    }
    clock_t end_time = clock() - start_time;
    std::cerr << "Matrix : " << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
    return mat;
}

/* Blocked Cache Obvious matrix multiplication */
static std::vector<std::vector<uint64_t> > fast_matrix_modulo_multiplication(std::vector<std::vector<uint64_t> > &A, std::vector<std::vector<uint64_t> > &B)
{
    clock_t start_time;
    std::vector<std::vector<uint64_t> > C = matrix(A.size(), B[0].size(), 0);
    int cache_line = 1 << 3; /* 64B */
#pragma omp simd
    for(unsigned i = 0; i < A.size(); i += cache_line){
        for(unsigned j = 0; j < B[0].size(); j += cache_line){
            for (unsigned k = 0; k < B[0].size(); k += cache_line){
                for(unsigned il = i; il < (i + cache_line); il++){
                    for(unsigned jl = j; jl < (j + cache_line); jl++){
                        for (unsigned kl = k; kl < (k + cache_line); kl++){
                            C[il][jl] += ((A[il][kl])%lr_mod * (B[kl][jl])%lr_mod)%lr_mod;
                        }
                    }
                }
            }
        }
    }
    clock_t end_time = clock() - start_time;
    std::cerr << "Fast : " <<  ((float)end_time)/CLOCKS_PER_SEC << std::endl;
    return C;
}

static std::vector<std::vector<uint64_t> > slow_matrix_modulo_multiplication(std::vector<std::vector<uint64_t> > &A, std::vector<std::vector<uint64_t> > &B)
{
    clock_t start_time;
    std::vector<std::vector<uint64_t> > C = matrix(A.size(), B[0].size(), 0);
#pragma omp simd
    for(unsigned i = 0; i < A.size(); i++){
        for(unsigned j = 0; j < B[0].size(); j++){
            for (unsigned k = 0; k < B[0].size(); k++){
                C[i][j] += ((A[i][k])%lr_mod * (B[k][j])%lr_mod)%lr_mod;
            }
        }
    }
    clock_t end_time = clock() - start_time;
    std::cerr << "Slow : " << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
    return C;
}

static void sizes()
{
    std::cout << "int : " <<  8 * sizeof(int) << " bits" <<  std::endl;
    std::cout << "char : " << 8 * sizeof(char) << " bits" <<  std::endl;
    std::cout << "long : " <<  8 * sizeof(long) << " bits" <<  std::endl;
    std::cout << "short : " <<  8 * sizeof(short) << " bits" <<  std::endl;
    std::cout << "float : " <<  8 * sizeof(float) << " bits" <<  std::endl;
    std::cout << "double : " <<  8 * sizeof(double) << " bits" <<  std::endl;
    std::cout << "long long : " <<  8 * sizeof(long long) << " bits" <<  std::endl;
    std::cout << "long double : " << 8 * sizeof(long double) << " bits" <<  std::endl;
    std::cout << "unsigned int : " <<  8 * sizeof(unsigned int) << " bits" <<  std::endl;
    std::cout << "unsigned long : " <<  8 * sizeof(unsigned long) << " bits" <<  std::endl;
    std::cout << "long long int : " <<  8 * sizeof(long long int) << " bits" <<  std::endl;
    std::cout << "unsigned int 64 : " <<  8 * sizeof(uint64_t) << " bits" <<  std::endl;
}

static uint64_t unsigned_ripple_carry_adder(uint64_t a = 589, uint64_t b = 7454)
{
    uint64_t carryin = 0, sum = 0, mask = 1, temp_a = a, temp_b = b;
    while(temp_a || temp_b)
    {
        uint64_t a_last = a & mask;
        uint64_t b_last = b & mask;
        uint64_t carryout = (a_last & carryin) | (b_last & carryin) | (a_last & b_last);
        sum |= a_last ^ b_last ^ carryin;
        carryin = carryout << 1; mask <<= 1; temp_a >>= 1; temp_b >>= 1;
    }
    return sum | carryin;
}

static uint64_t ripple_multiply(uint64_t x = 2, uint64_t y = 33)
{
    uint64_t sum = 0;
    while(x)
    {
        if(x & 1){
            sum = unsigned_ripple_carry_adder(sum, y);
        }
        x >>= 1; y <<= 1;
    }
    return sum;
}

unsigned int BinaryToGray(unsigned int num)
{
    return num ^ (num >> 1);
}

/*
 * Each Gray code bit is exclusive-ored with all more significant bits.
 */

unsigned int GrayToBinary(unsigned int num)
{
    unsigned int mask = num >> 1;
    while (mask != 0)
    {
        num = num ^ mask;
        mask = mask >> 1;
    }
    return num;
}

#endif /* functions_h */
