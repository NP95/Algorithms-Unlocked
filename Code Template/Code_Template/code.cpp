#include "Headers/allheaders.h"
const string input_type = "stdin";
int main(int argc, char* argv[])
{
    start_time = clock();
    ioutil(input_type);
    /* Your Code here */
    
    
    
    end_time = clock() - start_time;
    log_time(end_time, argc, argv);
    close();
    return 0;
}
