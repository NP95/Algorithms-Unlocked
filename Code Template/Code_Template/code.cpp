#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
    auto A = matrix (1000, 1000);
    auto B = A, C = B;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 1000; j++){
            A[i][j] = i + j;
            B[i][j] = i * j;
        }
    }
    int h = 8;
    for(auto i = 0; i < 1000; i += h){
        for(auto j = 0; j < 1000; j += h){
            for (auto k = 0; k < 1000; k += h) {
                for(auto il = i; il < (i + h); il++){
                    for(auto jl = j; jl < (j + h); jl++){
                        for (auto kl = k; kl < (k + h); kl++) {
                            C[il][jl] += A[il][kl] * B[kl][jl];
                        }
                    }
                }
            }
        }
    }
    std::cout << C[456][744] << std::endl;
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
