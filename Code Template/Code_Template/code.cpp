#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
    std::cout << "char : " << sizeof(char) << "B" << std::endl;
    std::cout << "int : " <<  sizeof(int) << "B" <<  std::endl;
    std::cout << "double : " <<  sizeof(double) << "B" <<  std::endl;
    std::cout << "float : " <<  sizeof(float) << "B" <<  std::endl;
    std::cout << "long : " <<  sizeof(long) << "B" <<  std::endl;
    std::cout << "long long : " <<  sizeof(long long) << "B" <<  std::endl;
    std::cout << "long long int : " <<  sizeof(long long int) << "B" <<  std::endl;
    std::cout << "unsigned int : " <<  sizeof(unsigned int) << "B" <<  std::endl;
    std::cout << "unsigned long : " <<  sizeof(unsigned long) << "B" <<  std::endl;
    std::cout << "unsigned int 64 : " <<  sizeof(uint64_t) << "B" <<  std::endl;
    std::cout << "long double : " <<  sizeof(long double) << "B" <<  std::endl;
    long double huge_integer = 1 << 127;
    std::cout << "long double : " <<  huge_integer << std::endl;
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
