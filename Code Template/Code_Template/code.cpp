#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
    std::cout << "char : " << sizeof(char) << std::endl;
    std::cout << "int :" <<  sizeof(int) << std::endl;
    std::cout << "double : " <<  sizeof(double) << std::endl;
    std::cout << "float : " <<  sizeof(float) << std::endl;
    std::cout << "long : " <<  sizeof(long) << std::endl;
    std::cout << "long long :" <<  sizeof(long long) << std::endl;
    std::cout << "long long int : " <<  sizeof(long long int) << std::endl;
    std::cout << "long long double : " <<  sizeof(long long double) << std::endl;
    std::cout << "unsigned int 64 : " <<  sizeof(uint64_t) << std::endl;
}

int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    CM_TRACE_FILE(TRACE);
    CM_TRACE_FUNC("main");
    start_time = clock();
    intialize_io("testcase");
    build_log();
    // HackerRank(); /* Unzip and copy files for input */
    // codejam(); /* Unzip and copy files for input */
#endif
    solution(argc, argv, envp);
#ifdef OFFLINE_START_BUILD
    build_solution();
    // std::cerr << "Solution Accepted : 0/1 -> " << Output_Compare() << std::endl; /* Automated comapre of output files */
    end_time_log(start_time, argc, argv, envp);
    /* Check mailbox for compilation & deployment status. */
#endif
    return 0;
}
