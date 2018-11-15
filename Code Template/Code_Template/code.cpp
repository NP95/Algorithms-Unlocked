#include "Headers/headers.h"

char * const file_parameters[] = { "/bin/cp", "./../CodeChef_Codes", "./../../ProjectStudio/Algorithms-Unlocked/Code\ Template/Code_Template", NULL};
char * const zip_parameters[] = { "/usr/bin/unzip", "-o", "-qq" ,"./Code/download.zip", "-d", "Code", NULL };

/* Main Here */
int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    ioutil("testcase");
    random_logger();
    run_prog_from_args(file_parameters);
    // run_prog_from_args(zip_parameters);
#endif
/* Start */

    
    
    
/* End */
#ifdef OFFLINE_START_BUILD
    copy_code();
    log_time(start_time, argc, argv, envp);
#endif
    return 0;
}
/* Finished */
