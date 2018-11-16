#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
    std::cout << "Git-merged" << std::endl;
}


int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    ioutil("testcase"); // ./Code/
    random_logger();
    copy_to_git();
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

