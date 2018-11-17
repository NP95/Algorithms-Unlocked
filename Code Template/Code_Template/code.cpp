#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{

}


int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    ioutil("testcase"); // ./Code/
    random_logger();
#endif
/* Start */
    solution(argc, argv, envp);
/* End */
#ifdef OFFLINE_START_BUILD
    copy_code();
    log("Finished");
    log_time(start_time, argc, argv, envp);
#endif
    return 0;
}

