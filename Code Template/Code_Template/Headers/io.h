/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef reader_h
#define reader_h
#include "static.h"
#include "constants.h"
#include "exceptions.h"

long long int reader;

static void write_random_ints(const string &file_name = STDIN_TEST_REDIRECT, bool small = false)
{
    std::fstream file(file_name.c_str(), std::fstream::out);
    std::cerr << "Writing ints." << std::endl;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 10000; j++){
            if(!small)
                file << rd_ints() << " ";
            else
                file << (rd_ints())%10000 << " ";
        }
        file << "/n";
    }
    file.close();
}

static void write_random_ints_sorted(const string &file_name = STDIN_TEST_REDIRECT, bool small = false)
{
    std::fstream file(file_name.c_str(), std::fstream::out);
    std::cerr << "Writing ints." << std::endl;
    std::vector<long long int> dump;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 10000; j++){
            if(!small){
                dump.emplace_back(rd_ints());
            }
            else
                dump.emplace_back((rd_ints())%10000);
        }
        std::sort(dump.begin(), dump.end());
        for(const auto &a : dump) file << a << " ";
        dump.erase(dump.begin(), dump.end());
        file << "/n";
    }
    file.close();
}

static void write_random_strings(const string &file_name = STDIN_TEST_REDIRECT)
{
    std::string generator = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890~!@#$%^&*()_+{}|:";
    std::fstream file(file_name.c_str(), std::fstream::out);
    std::cerr << "Writing strings." << std::endl;
    for(auto i = 0; i < 100; i++){
        for(auto j = 0; j < 10000; j++){
            file << generator.substr((rd_ints())%80, (rd_ints())%80) << " ";
        }
        file << "/n";
    }
    file.close();
}

static void single_write_printf()
{
    std::cerr << "Write Test :  printf used" << std::endl;
    for(auto i = 0; i < 10000; i++){
        for(auto j = 0; j < 10000; j++){
            printf("%d ,", rd_ints());
        }
        printf("\n");
    }
}

static void single_write_cin()
{
    std::cerr << "Read Test : Read using custom function" << std::endl;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 10000; j++){
            std::cin >> reader;
        }
    }
}

static void single_write_scanf()
{
    std::cerr << "Read Test : Read using scanf" << std::endl;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 10000; j++){
            scanf("%lld", &reader);
        }
    }
}

static void read_data_write()
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

static std::vector<string> SplitWordsTokenizerFileRead (string input_string, char delimiter)
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

static std::vector<std::vector<string> > read_file_to_string (const string& filename = STDIN_CSV_REDIRECT, char delimiter = ',')
{
    std::string input = "";
    std::vector<std::vector<std::string> > CSVTokens;
    std::fstream fileCSVReader(filename.c_str(), std::fstream::in);
    while(fileCSVReader.good() && std::getline(fileCSVReader, input))
    {
        auto dump = SplitWordsTokenizerFileRead(input, delimiter);
        CSVTokens.push_back(dump);
    }
    fileCSVReader.close();
    return CSVTokens;
}

template <typename T>
class TextReader
{
    std::string fileName;
    public:
    TextReader(std::string file) : fileName(file){}
    std::vector<std::vector<T> > parseReturnData();
};

template <typename T>
std::vector<std::vector<T> > TextReader<T>::parseReturnData()
{
    T nums;
    std::ifstream file_stream(fileName.c_str(), std::fstream::in);
    std::vector<std::vector<T> > dataStore;
    std::vector<T> temp;
    if(file_stream.fail()){
        std::cerr << "Error Opening/Reading file." << std::endl;
        exit(EXIT_FAILURE);
    } else {
        while(!file_stream.eof()){
            for(auto cols = 0; cols < 3; cols++){
                file_stream >> nums;
                temp.push_back(nums);
            }
            if(file_stream.eof()) break;
            dataStore.push_back(temp);
            temp.clear();
        }
    }
    file_stream.close();
    return dataStore;
}

static long long file_size (const string &file_name)
{
    std::fstream file_pointer(file_name.c_str(), std::fstream::in);
    file_pointer.seekg(0, ios::end);
    long long file_size = file_pointer.tellg();
    return file_size;
}

static void Remove_char_from_string(std::string &input, char rmove)
{
    input.erase(std::remove(input.begin(), input.end(), rmove), input.end());
}

static void build_solution()
{
    std::string str;
    freopen(MAIN, "r+", stdin);
    freopen(STDOUT_CODECHEF_REDIRECT, "w+", stdout);
    std::fstream file(DUMP_HEADERS, std::fstream::in);
    if(file.fail()){
        std::cerr << "Error Opening/Reading Header file." << std::endl;
    } else {
        while(std::getline(file, str)){
            printf("%s\n", str.c_str());
        }
    }
    file.close();
    freopen(STDOUT_CODECHEF_REDIRECT, "a+", stdout);
    std::getline(std::cin, str);
    while(std::getline(std::cin, str)){
        printf("%s\n", str.c_str());
    }
}

static void intialize_io(const string& type = "stdin")
{
        if(type == "stdin")
    freopen(STDIN_FILE_REDIRECT, "r+", stdin);
    else if (type == "testcase")
    freopen(STDIN_TEST_REDIRECT, "r+", stdin);
    else
    freopen(type.c_str(), "r+", stdin);
    
    freopen(STDOUT_FILE_REDIRECT, "w+", stdout);
    freopen(STDOUT_LOGGER_ERROR_REDIRECT, "a+", stderr);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

char * const copy_parameters[] = { "/bin/cp", "-r", "./Code/A-small-practice.in", "./Code/testcase.txt", NULL};
char * const unzip_parameters[] = {  "/usr/bin/unzip", "-o", "-qq" ,"./Code/download.zip", "-d", "./", NULL };
char * const copy_hrrank_parameters[] = { "/bin/cp", "-r", "./Input/input00.txt", "./Code/testcase.txt", NULL};


static void codejam(char * const args[] = copy_parameters) {
    clock_t start = clock();
    pid_t processId;
    if ((processId = fork()) == 0) {
        if (execv(args[0], args) < 0) {
            throw FATAL_EXCEPTION("cp --error-ocurred.");
        }
    } else if (processId < 0) {
        throw FATAL_EXCEPTION("No process --no-fork");
    } else {
        std::cerr << "Program ran sucessfully. " << 1.0 * (start - clock())/CLOCKS_PER_SEC << std::endl;
    }
}

static void HackerRank_Helper(char * const args[] = copy_hrrank_parameters)
{
    clock_t start = clock();
    pid_t processId;
    if ((processId = fork()) == 0) {
        if (execv(args[0], args) < 0) {
            throw FATAL_EXCEPTION("cp --error-ocurred.");
        }
    } else if (processId < 0) {
        throw FATAL_EXCEPTION("No process --no-fork");
    } else {
        std::cerr << "Program ran sucessfully. " << 1.0 * (start - clock())/CLOCKS_PER_SEC << std::endl;
    }
}

static void HackerRank(char * const args[] = unzip_parameters) {
    clock_t start = clock();
    pid_t processId;
    if ((processId = fork()) == 0) {
        if (execv(args[0], args) < 0) {
            throw FATAL_EXCEPTION("unzip --error ocurred.");
        }
    } else if (processId < 0) {
        throw FATAL_EXCEPTION("No process --no-fork");
    } else {
        std::cerr << "Program ran sucessfully. " << 1.0 * (start - clock())/CLOCKS_PER_SEC << std::endl;
    }
    HackerRank_Helper();
}

static string compute_file_sha(const string& file_name)
{
    std::string str, dump;
    std::fstream file(file_name.c_str(), std::fstream::in);
    if(file.fail()) {
        std::cerr << "Error Opening/Reading file." << std::endl;
    } else {
        while(std::getline(file, str)){
            dump += double_sha256(str);
            str.clear();
        }
    }
    file.close();
    return dump;
}

static bool compare_files_sha256(const string& file1, const string& file2)
{
    string one = compute_file_sha(file1);
    string two = compute_file_sha(file2);
    return (double_sha256(one) == double_sha256(two)) ? true : false;
}

#endif /* reader_h */

