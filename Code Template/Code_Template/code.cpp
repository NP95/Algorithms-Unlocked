#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
    
}


int main(int argc, char* argv[], char* envp[])
{
    char * const file_parameters[] = { "/bin/cp", "-a", "./", "./../../ProjectStudio/Algorithms-Unlocked/Code\ Template/Code_Template", NULL};
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    ioutil("testcase"); // ./Code/
    random_logger();
    run_prog_from_args(file_parameters);
    // run_prog_from_args(zip_parameters);
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

