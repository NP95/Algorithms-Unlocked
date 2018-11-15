#include "Headers/headers.h"

/* Main Here */
int main(int argc, char* argv[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    ioutil("testcase");
#endif

    
    
#ifdef OFFLINE_END_BUILD
    log("Offline Build.");
    // copy_codechef();
    log_time(start_time, argc, argv);
    close();
#endif
    return 0;
}

/* Finished */
