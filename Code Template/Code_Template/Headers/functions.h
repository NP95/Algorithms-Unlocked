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
static string sha256(string line) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, line.c_str(), line.length());
    SHA256_Final(hash, &sha256);
    
    string output = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        output += to_hex(hash[i]);
    }
    return output;
}
#endif

static void fork_and_run(char * const args[]) {
    pid_t processId;
    if ((processId = fork()) == 0) {
        if (execv(args[0], args) < 0) {
            throw FATAL_EXCEPTION("No Program to run.");
        }
    } else if (processId < 0) {
        throw FATAL_EXCEPTION("No Process");
    } else {
        /* Nothing */
    }
}

#endif /* functions_h */
