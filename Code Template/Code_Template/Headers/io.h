/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef reader_h
#define reader_h
#include "static.h"
#include "constants.h"
#include "exceptions.h"

#endif /* reader_h */

long long int reader;

void single_write_cout()
{
    std::cerr << "Write Test : cout used" << std::endl;
    for(auto i = 0; i < 10000; i++){
        for(auto j = 0; j < 10000; j++){
            std::cout << rd_ints() << ", ";
        }
        std::cout << "/n";
    }
}

void single_write_printf()
{
    std::cerr << "Write Test :  printf used" << std::endl;
    for(auto i = 0; i < 10000; i++){
        for(auto j = 0; j < 10000; j++){
            printf("%d ,", rd_ints());
        }
        printf("\n");
    }
}
void single_write_cin()
{
    std::cerr << "Read Test : Read using custom function" << std::endl;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 10000; j++){
            std::cin >> reader;
        }
    }
}

void single_write_scanf()
{
    std::cerr << "Read Test : Read using scanf" << std::endl;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 10000; j++){
            scanf("%lld", &reader);
        }
    }
}

void read_data_write()
{
    std::cerr << "Read and write data using cin, printf" << std::endl;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 10000; j++){
            std::cin >> reader;
            std::cout << reader;
        }
        std::cout << "/n";
    }
}

/* Read, Tokenize, Write CSV, text */
std::vector<string> SplitWordsTokenizerCSVRead (string input_string, char delimiter)
{
    string::iterator str_end_iter = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y){
        return x == y && x == ' ';
    });

    input_string.erase(str_end_iter, input_string.end());
    while(input_string[input_string.length() - 1] == ' '){
        input_string.pop_back();
    }
    std::vector<string> split_tokens;
    size_t pos, i = 0;
    pos = input_string.find(delimiter);
    while(pos != string::npos){
        auto temp = input_string.substr(i, pos - i);
        if(temp.front() == ' ') temp.erase(0, 1);
        split_tokens.push_back(temp);
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    auto temp = input_string.substr(i, std::min(pos, input_string.length()));
    temp.erase(0, 1);
    split_tokens.push_back(temp);
    return split_tokens;
}

std::vector<std::vector<string> > read_csv_to_string (const string& filename = STDIN_CSV_REDIRECT, char delimiter = ',') /* Right first */
{
    std::string input = "";
    std::vector<std::vector<std::string> > CSVTokens;
    std::fstream fileCSVReader(filename.c_str(), std::fstream::in);
    while(fileCSVReader.good() && std::getline(fileCSVReader, input))
    {
        auto dump = SplitWordsTokenizerCSVRead(input, delimiter);
        CSVTokens.push_back(dump);
    }
    fileCSVReader.close();
    return CSVTokens;
}

void copy_code()
{
    std::string str;
    freopen(MAIN, "r+", stdin);
    freopen(STDOUT_CODECHEF_REDIRECT, "w+", stdout);
    std::fstream file(DUMP_HEADERS, std::fstream::in);
    while(std::getline(file, str)){
        printf("%s\n", str.c_str());
    }
    file.close();
    freopen(STDOUT_CODECHEF_REDIRECT, "a+", stdout);
    std::getline(std::cin, str);
    while(std::getline(std::cin, str)){
        printf("%s\n", str.c_str());
    }
}

void ioutil(const string& type = "stdin")
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    
    if(type == "stdin")
        freopen(STDIN_FILE_REDIRECT, "r+", stdin);
    else if (type == "testcase")
        freopen(STDIN_TEST_REDIRECT, "r+", stdin);
    else
        freopen(type.c_str(), "r+", stdin);
    
    freopen(STDOUT_FILE_REDIRECT, "w+", stdout);
    freopen(STDOUT_LOGGER_ERROR_REDIRECT, "a+", stderr);
}

char * const copy_parameters[] = { "/bin/cp", "-r", "./Code/A-small-practice.in", "./Code/testcase.txt", NULL};

static void codejam(char * const args[]) {
    pid_t processId;
    if ((processId = fork()) == 0) {
        if (execv(args[0], args) < 0) {
            throw FATAL_EXCEPTION("No Program to run.");
        }
    } else if (processId < 0) {
        throw FATAL_EXCEPTION("No Process");
    } else {
        /* Nothing */
    }
}
