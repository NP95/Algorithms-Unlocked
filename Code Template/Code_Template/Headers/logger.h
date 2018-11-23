/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef logger_h
#define logger_h
#include "static.h"
#include "functions.h"
#include "trace.h"

static void build_log()
{
    CM_TRACE_FUNC("START_LOGGING");
    std::string build_base = std::to_string(rd_ints());
    std::string str = "Build ID : " + build_base;
    std::cerr << "--------------------------------------------------------------------BUILD---------------------------------------------------------------------" << std::endl;
#ifdef HASH
    std::cerr << str << ", Build Hash : " << double_sha256(str) << std::endl;
#elif _WIN64 || _WIN32
    std::cerr << str << std::endl;
#endif
}

static void end_time_log(clock_t start_time, int &argc, char* *argv, char* *envp)
{
    CM_TRACE_FUNC("end_time_log");
    clock_t end_time = clock() - start_time;
    std::cerr << "--------------------------------------------------------------------FINAL::TIME---------------------------------------------------------------" << std::endl;
    std::cerr << "Running with -"<< argv[0] << " $" << envp[9] << " Time : " << ((float)end_time)/CLOCKS_PER_SEC << " sec, " << "Ticks : " << end_time << " (" << argc << ")" << std::endl;
}

static void log(const string& log_str)
{
    CM_TRACE_FUNC("log");
    time_t now = time(0);
    char* dt = ctime(&now);
    std::cerr << std::endl << "TIME : " << dt << "Log : " << log_str << std::endl;
}

#endif /* logger_h */
