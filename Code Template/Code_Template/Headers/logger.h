//
//  logger.h
//  Google_Code
//
//  Created by SUMIT  LAHIRI on 11/4/18.
//  Copyright © 2018 Google PPLNS. All rights reserved.
//

#ifndef logger_h
#define logger_h
#include "static.h"

string to_hex(unsigned char s) {
    stringstream ss;
    ss << hex << (int) s;
    return ss.str();
}

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

void random_logger()
{
    std::string build_base = std::to_string(rd_ints());
    std::string str = "Build ID : " + build_base;
    std::cerr << "----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cerr << str << ", Build Hash : " << sha256(str) << std::endl;
}

void log_time(clock_t end_time, int &argc, char* *argv)
{
    std::cerr << "Running with " << argc << " " << argv[1] << " Time : " << ((float)end_time)/CLOCKS_PER_SEC << " sec, " << "Ticks : " << end_time << std::endl;
}

void ioutil(const string& type)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /* STDIN, STDOUT, STDERR, Test cases : STDIN_TEST_REDIRECT */
    if(type == "stdin")
    	freopen(STDIN_FILE_REDIRECT, "r+", stdin);
    else if (type == "testcase")
    	freopen(STDIN_TEST_REDIRECT, "r+", stdin);
    else
        freopen(type.c_str(), "r+", stdin);

    freopen(STDOUT_FILE_REDIRECT, "a+", stdout);
    freopen(STDOUT_LOGGER_ERROR_REDIRECT, "a+", stderr);
    
    random_logger();
}

void log(const string& log_str)
{
    time_t now = time(0);
    char* dt = ctime(&now);
    std::cerr << std::endl << "TIME : " << dt << "Log : " << log_str << std::endl;
}
#endif /* logger_h */
