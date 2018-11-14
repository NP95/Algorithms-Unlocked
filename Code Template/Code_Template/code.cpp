#include "Headers/allheaders.h"

int main(int argc, char* argv[])
{
    start_time = clock();
    ioutil("stdin");
    /* Your Code here */
    
    
    
    end_time = clock() - start_time;
    log_time(end_time, argc, argv);
    close();
    return 0;
}
