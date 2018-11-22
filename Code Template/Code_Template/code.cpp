#include "Headers/headers.h"
std::map<int, std::vector<int> > case_map;
// case[0] -> islower, case[1] -> isupper, case[2] -> isdigit,

void solution(int argc, char* argv[], char* envp[])
{
    int T;
    std::string password;
    std::cin >> T;
    cin.sync();
    while(T--)
    {
        std::getline(std::cin, password);
        for(const auto& character : password)
        {
            if(islower(character)) case_map[0].push_back(character);
        }
    }
}

int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    start_time = clock();
    intialize_io("testcase");
    build_log();
    // HackerRank(); /* Unzip and copy files for input */
    // codejam(); /* Unzip and copy files for input */
#endif
    solution(argc, argv, envp);
#ifdef OFFLINE_START_BUILD
    build_solution();
    // std::cerr << "Solution Accepted : 0/1 -> " << HackerRank_Compare() << std::endl; /* Automated comapre of output files */
    end_time_log(start_time, argc, argv, envp);
    /* Check mailbox for compilation & deployment status. */
#endif
    return 0;
}

