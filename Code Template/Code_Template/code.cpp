#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
 
}

static void extracted() {
    intialize_io("testcase");
}

int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    extracted();
    build_log();
#endif
    solution(argc, argv, envp);
#ifdef OFFLINE_START_BUILD
    build_solution();
    end_time_log(start_time, argc, argv, envp);
#endif
    return 0;
}

