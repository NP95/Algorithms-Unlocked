#include "Headers/allheaders.h"

int main(int argc, char* argv[])
{
    start_time = clock();
    ioutil();
<<<<<<< HEAD
    /* Your Code here */
    
=======
    random_logger();
>>>>>>> 50f6c09ec5ca23875d3985c927b21537844e5307
    
    
    end_time = clock() - start_time;
<<<<<<< HEAD
    log(end_time, argc, argv);
=======
    std::cerr << "Running. " << argc << " " << argv[1] << " Time : " << ((float)end_time)/CLOCKS_PER_SEC << " sec, " << "Ticks : " << end_time << std::endl;
>>>>>>> 50f6c09ec5ca23875d3985c927b21537844e5307
    close();
    return 0;
}
