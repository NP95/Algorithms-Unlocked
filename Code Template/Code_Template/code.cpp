#include "Headers/headers.h"

/* Main Here */
int main(int argc, char* argv[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    ioutil("testcase");
    random_logger();
#endif

    
    
    
    
    
    
#ifdef OFFLINE_END_BUILD
    copy_code();
    log_time(start_time, argc, argv);
#endif
    return 0;
}
/* Finished */
