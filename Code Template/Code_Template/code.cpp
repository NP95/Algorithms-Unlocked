#include "Headers/headers.h"
#define LARGEMOD 998244353
LL bicoloring[1004][2008][4];

void solution(int argc, char* argv[], char* envp[])
{
    int n = 0, k = 0; std::cin >> n >> k;
    bicoloring[1][1][0] = 1; // WW has 1 component.
    bicoloring[1][2][1] = 1; // WB has 2 components.
    bicoloring[1][2][2] = 1; // BW has 2 components.
    bicoloring[1][1][3] = 1; // BB has 1 component.
    /* What happens on adding successive columns */
    for(auto i = 2; i <= n; ++i ) // columns
    {
        for(auto j = 1; j <= 2 * i; ++j ) // components
        {
            bicoloring[i][j][0] = (bicoloring[i - 1][j    ][0] + bicoloring[i - 1][j    ][1] + bicoloring[i - 1][j    ][2] + bicoloring[i - 1][j - 1][3]) % LARGEMOD;
            bicoloring[i][j][1] = (bicoloring[i - 1][j - 1][0] + bicoloring[i - 1][j    ][1] + bicoloring[i - 1][j - 2][2] + bicoloring[i - 1][j - 1][3]) % LARGEMOD;
            bicoloring[i][j][2] = (bicoloring[i - 1][j - 1][0] + bicoloring[i - 1][j - 2][1] + bicoloring[i - 1][j    ][2] + bicoloring[i - 1][j - 1][3]) % LARGEMOD;
            bicoloring[i][j][3] = (bicoloring[i - 1][j - 1][0] + bicoloring[i - 1][j    ][1] + bicoloring[i - 1][j    ][2] + bicoloring[i - 1][j    ][3]) % LARGEMOD;
        }
    }
    std::cout << (bicoloring[n][k][0] + bicoloring[n][k][1] + bicoloring[n][k][2] + bicoloring[n][k][3]) % LARGEMOD << std::endl;
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
