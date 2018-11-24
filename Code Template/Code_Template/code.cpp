#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
    auto array_mat = matrix(1000, 1000);
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 1000; j++){
            array_mat[j][i] = (1ULL << 37);
        }
    }
    std::cout << array_mat[500][752] << std::endl;
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
