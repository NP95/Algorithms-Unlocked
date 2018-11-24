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
static void huge_mod_power(uint64_t base, uint64_t power)
{
    clock_t start_time;
    static uint64_t expo = base;
    while(power)
    {
        std::cerr << "Power : " << power << ", " << to_string(expo) << std::endl;
        expo %= lr_mod;
        if (!(power & 1)){
            expo *= (expo % lr_mod);
            power >>= 1;
        } else {
            expo *= (base % lr_mod);
            --power;
        }
    }
    std::cout << to_string(expo) << std::endl;
    clock_t end_time = clock() - start_time;
    std::cerr << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
}

static std::vector<std::vector<uint64_t> > matrix (int row, int col, uint64_t value)
{
    clock_t start_time;
    std::vector<std::vector<uint64_t> > mat;
    std::vector<uint64_t> dump(col, value);
    for(auto i = 0; i < row; i++){
        mat.emplace_back(dump);
    }
    clock_t end_time = clock() - start_time;
    std::cerr << "Matrix : " << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
    return mat;
}


/* Blocked Cache Obvious matrix multiplication */
std::vector<std::vector<uint64_t> > fast_matrix_multiplication(std::vector<std::vector<uint64_t> > &A, std::vector<std::vector<uint64_t> > &B)
{
    std::vector<std::vector<uint64_t> > C = matrix(A.size(), B[0].size(), 0);
    clock_t start_time;
    int h = 1 << 3;
    for(auto i = 0; i < 1000; i += h){
        for(auto j = 0; j < 1000; j += h){
            for (auto k = 0; k < 1000; k += h) {
                for(auto il = i; il < (i + h); il++){
                    for(auto jl = j; jl < (j + h); jl++){
                        for (auto kl = k; kl < (k + h); kl++) {
                            C[il][jl] += A[il][kl] * B[kl][jl];
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

std::vector<std::vector<uint64_t> > slow_matrix_multiplication(std::vector<std::vector<uint64_t> > &A, std::vector<std::vector<uint64_t> > &B)
{
    std::vector<std::vector<uint64_t> > C = matrix(A.size(), B[0].size(), 0);
    clock_t start_time;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 1000; j++){
            for (auto k = 0; k < 1000; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    std::cout << C[456][744] << std::endl;
    clock_t end_time = clock() - start_time;
    std::cerr << "Slow : " << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
    return C;
}

#endif /* functions_h */
