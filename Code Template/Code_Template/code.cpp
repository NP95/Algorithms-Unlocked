#include "Headers/allheaders.h"
int main(int argc, char* argv[])
{
    start_time = clock();
    ioutil("testcase");

    log_time(start_time, argc, argv);
    close();
    return 0;
}
