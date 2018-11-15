/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef functions_h
#define functions_h
#include "static.h"
#include "constants.h"

string to_hex(unsigned char s) {
    stringstream ss;
    ss << hex << (int) s;
    return ss.str();
}

#ifdef HASH
string sha256(string line) {
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

void ioutil(const string& type = "stdin")
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    
    if(type == "stdin")
        freopen(STDIN_FILE_REDIRECT, "r+", stdin);
    else if (type == "testcase")
        freopen(STDIN_TEST_REDIRECT, "r+", stdin);
    else if (type == "codejam-small-a")
        freopen(STDIN_CODEJAM_SMALL_REDIRECTA, "r+", stdin);
    else if (type == "codejam-large-a")
        freopen(STDIN_CODEJAM_LARGE_REDIRECTA, "r+", stdin);
    else if (type == "codejam-small-b")
        freopen(STDIN_CODEJAM_SMALL_REDIRECTB, "r+", stdin);
    else if (type == "codejam-large-b")
        freopen(STDIN_CODEJAM_LARGE_REDIRECTB, "r+", stdin);
    else if (type == "codejam-small-c")
        freopen(STDIN_CODEJAM_SMALL_REDIRECTC, "r+", stdin);
    else if (type == "codejam-large-c")
        freopen(STDIN_CODEJAM_LARGE_REDIRECTC, "r+", stdin);
    else if (type == "codejam-small-d")
        freopen(STDIN_CODEJAM_SMALL_REDIRECTD, "r+", stdin);
    else if (type == "codejam-large-d")
        freopen(STDIN_CODEJAM_LARGE_REDIRECTD, "r+", stdin);
    else
        freopen(type.c_str(), "r+", stdin);
    
    freopen(STDOUT_FILE_REDIRECT, "w+", stdout);
    freopen(STDOUT_LOGGER_ERROR_REDIRECT, "a+", stderr);
}

#endif /* functions_h */
