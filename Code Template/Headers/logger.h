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
    std::random_device rd;
    std::default_random_engine seed(rd());
    std::uniform_int_distribution<int> random_engine_block(MIN_RANGE, MAX_RANGE);
    auto random = std::bind(random_engine_block, seed);
    std::string build_base = std::to_string(random());
    std::string str = "Build_id : " + build_base;
    std::cout << str << ", Build Hash : " << sha256(str) << std::endl;
}

#endif /* logger_h */
