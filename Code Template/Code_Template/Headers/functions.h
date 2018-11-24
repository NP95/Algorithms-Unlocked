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

const LL lr_mod  = 1000000003;

void huge_mod_power(LL base, LL power, LL lr_mod, )
{
    static LL base = 2, expo = base % lr_mod;
    static LL power = 1 << 30, counter = 0;
    while(power)
    {
        expo %= lr_mod;
        if (!(power&1)){
            expo *= (expo % lr_mod);
            power >>= 1;
        } else {
            expo *= (base % lr_mod);
            --power;
        }
    }
    std::cout << to_string(expo) << std::endl;
}

#endif /* functions_h */
