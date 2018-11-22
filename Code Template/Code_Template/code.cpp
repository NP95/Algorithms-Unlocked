#include "Headers/headers.h"

void solution(int argc, char* argv[], char* envp[])
{
    int T;
    std::string password;
    std::cin >> T;
    // cin.sync();
    while(T--)
    {
        std::map<int, std::vector<int> > case_map;
        // case[0] -> islower, case[1] -> isupper, case[2] -> isdigit,

        std::getline(std::cin, password);
        for(const auto& character : password)
        {
            if(islower(character)) case_map[0].emplace_back(character);
            if(isupper(character)) case_map[1].emplace_back(character);
            if(isdigit(character)) case_map[2].emplace_back(character);
        }
        if(case_map.size() == 1) // One of the requirements met.
        {
            /* There will be only one entry in the map */
            if(case_map.begin()->first == 0) password[1] = 'G'; password[2] = '7';
            if(case_map.begin()->first == 1) password[1] = 'l'; password[2] = '6';
            if(case_map.begin()->first == 2) password[1] = 'q'; password[2] = 'M';
        }
        else if (case_map.size() == 2) // Two were met.
        {
            auto return_greater_length = [](auto i, auto j) { return i.second.size() < j.second.size(); };
            auto index = max_element(case_map.begin(), case_map.end(), return_greater_length)->second[0];
            if(case_map[0].empty()) password[index] = 'x';
            if(case_map[1].empty()) password[index] = 'J';
            if(case_map[2].empty()) password[index] = '3';
        }
        std::cout << password << std::endl;
        password.erase(password.begin(), password.end());
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

