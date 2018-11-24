#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
    static LL base = 1500, expo = 1;
    static int power = 256, counter = 0;
    while(power)
    {
        counter++;
        if (!(power&1)){
            expo *= (expo % MOD);
            expo %= MOD;
            power >>= 1;
        } else {
            expo *= (base % MOD);
            expo %= MOD;
            --power;
        }
        std::cout << power << ", " << counter << ", " << to_string(expo) << std::endl;
    }
    if(expo < 0) std::cout << "Overflow." << std::endl;
    else std::cout << to_string(expo) << std::endl;
}

int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    CM_TRACE_FILE(TRACE);
    CM_TRACE_FUNC("main");
    start_time = clock();
    intialize_io("testcase");
    build_log();
    // HackerRank(); /* Unzip and copy files for input */
    // codejam(); /* Unzip and copy files for input */
#endif
    solution(argc, argv, envp);
#ifdef OFFLINE_START_BUILD
    build_solution();
    // std::cerr << "Solution Accepted : 0/1 -> " << Output_Compare() << std::endl; /* Automated comapre of output files */
    end_time_log(start_time, argc, argv, envp);
    /* Check mailbox for compilation & deployment status. */
#endif
    return 0;
}
