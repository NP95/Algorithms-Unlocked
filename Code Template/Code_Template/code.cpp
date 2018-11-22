#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
    int T;
    std::cin >> T;
    while(T--)
    {
        std::string password;
        std::map<int, std::vector<int> > case_map;
        // case[0] -> islower, case[1] -> isupper, case[2] -> isdigit,
        cin >> password;
        for(auto i = 0; i < password.size(); ++i)
        {
            auto character = password[i];
            if(islower (character)) { case_map[0].emplace_back(i); std::cerr << "Got case : 0 ->" << character << std::endl; }
            if(isupper (character)) { case_map[1].emplace_back(i); std::cerr << "Got case : 1 ->" << character << std::endl; }
            if(isdigit (character)) { case_map[2].emplace_back(i); std::cerr << "Got case : 2 ->" << character << std::endl; }
        }
        if(case_map.size() == 1) // One of the requirements met.
        {
            /* There will be only one entry in the map */
            if(case_map.begin()->first == 0) password[1] = 'X'; password[2] = '9';
            if(case_map.begin()->first == 1) password[1] = 'b'; password[2] = '8';
            if(case_map.begin()->first == 2) password[1] = 's'; password[2] = 'Y';
        }
        else if (case_map.size() == 2) // Two were met.
        {
            auto return_greater_length = [](auto i, auto j) { return i.second.size() < j.second.size(); };
            auto index = max_element(case_map.begin(), case_map.end(), return_greater_length)->second[0];
            if(case_map[0].empty()) password[index] = 'v';
            if(case_map[1].empty()) password[index] = 'U';
            if(case_map[2].empty()) password[index] = '3';
        }
        std::cout << password << std::endl;
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

