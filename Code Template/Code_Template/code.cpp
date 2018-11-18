#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
 
}


int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    ioutil("testcase");
    random_logger();
#endif
    solution(argc, argv, envp);
#ifdef OFFLINE_START_BUILD
    copy_code();
    log_time(start_time, argc, argv, envp);
#endif
    return 0;
}

