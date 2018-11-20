#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{

}

int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    intialize_io("testcase");
    build_log();
    HackerRank();
    // codejam();
#endif
    solution(argc, argv, envp);
#ifdef OFFLINE_START_BUILD
    build_solution();
    end_time_log(start_time, argc, argv, envp);
#endif
    return 0;
}

