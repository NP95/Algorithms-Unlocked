/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef logger_h
#define logger_h
#include "static.h"

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

void random_logger()
{
    std::string build_base = std::to_string(rd_ints());
    std::string str = "Build ID : " + build_base;
    std::cerr << "--------------------------------------------------------------------BUILD---------------------------------------------------------------------" << std::endl;
#ifdef HASH
    std::cerr << str << ", Build Hash : " << sha256(str) << std::endl;
#elif _WIN64 || _WIN32
    std::cerr << str << std::endl;
#endif
}

void log_time(clock_t start_time, int &argc, char* *argv)
{
    clock_t end_time = clock() - start_time;
    std::cerr << "--------------------------------------------------------------------FINAL::TIME---------------------------------------------------------------" << std::endl;
    std::cerr << "Running with " << argc << " " << argv[1] << " Time : " << ((float)end_time)/CLOCKS_PER_SEC << " sec, " << "Ticks : " << end_time << std::endl;
}

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
    random_logger();
}

void log(const string& log_str)
{
    time_t now = time(0);
    char* dt = ctime(&now);
    std::cerr << std::endl << "TIME : " << dt << "Log : " << log_str << std::endl;
}

#endif /* logger_h */
