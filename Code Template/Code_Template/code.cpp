#include "Headers/allheaders.h"
#include "Headers/static.h"
clock_t start_time, end_time;

int main(int argc, char* *argv)
{
    start_time = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /* STDIN, STDOUT, STDERR */
    freopen(STDIN_FILE_REDIRECT, "r+", stdin);
    freopen(STDOUT_FILE_REDIRECT, "w+", stdout);
    freopen(STDOUT_LOGGER_ERROR_REDIRECT, "a+", stderr);
    random_logger();
    

    
    end_time = clock() - start_time;
    std::cerr << "Time : " << ((float)end_time)/CLOCKS_PER_SEC << " sec, " << "Ticks : " << end_time << std::endl;
    close();
    return 0;
}
