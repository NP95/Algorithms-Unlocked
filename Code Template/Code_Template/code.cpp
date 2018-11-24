#include "Headers/headers.h"

void fast_matrix_multiplication(std::vector<std::vector<uint64_t> > A, std::vector<std::vector<uint64_t> > B, std::vector<std::vector<uint64_t> > C)
{
    clock_t start_time;
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
    clock_t end_time = clock() - start_time;
    std::cerr << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
}

void slow_matrix_multiplication(std::vector<std::vector<uint64_t> > A, std::vector<std::vector<uint64_t> > B, std::vector<std::vector<uint64_t> > C)
{
    clock_t start_time;
    for(auto i = 0; i < 1000; i += h){
        for(auto j = 0; j < 1000; j += h){
            for (auto k = 0; k < 1000; k += h) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    std::cout << C[456][744] << std::endl;
    clock_t end_time = clock() - start_time;
    std::cerr << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
}

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
    
    // fast_matrix_multiplication(A, B, C);
    slow_matrix_multiplication(A, B, C);
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
