#include "Headers/headers.h"





/* Main Here */
int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    ioutil("testcase");
    random_logger();
#endif
/* Start */
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
/* End */
#ifdef OFFLINE_END_BUILD
    copy_code();
    log_time(start_time, argc, argv, envp);
#endif
    return 0;
}
/* Finished */
