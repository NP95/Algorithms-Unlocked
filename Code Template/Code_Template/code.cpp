#include "Headers/allheaders.h"
#include "Headers/static.h"
clock_t start_time, end_time;

int main(int argc, char* *argv)
{
    start_time = clock();
    ioutil();
    random_logger();
    

    
    end_time = clock() - start_time;
    std::cerr << "Running. " << argc << " " << argv[1] << " Time : " << ((float)end_time)/CLOCKS_PER_SEC << " sec, " << "Ticks : " << end_time << std::endl;
    close();
    return 0;
}
