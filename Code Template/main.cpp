#include "Headers/allheaders.h"
#include "Headers/static.h"
using namespace std;

int main(int argc, char *argv[])
{
    freopen(STDIN_FILE_REDIRECT, "r+", stdin);
    freopen(STDOUT_FILE_REDIRECT, "w+", stdout);
    freopen(STDOUT_LOGGER_ERROR_REDIRECT, "w+", stderr);
    std::cout << "NO ERROR. " << std::endl;
    
    close();
    exit(EXIT_SUCCESS);
}
