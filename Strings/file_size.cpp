#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include <mutex>
#include <sstream>
using namespace std;
// Command make && time ./coding_ground infile.txt outfile.txt

int file_size (const string& file_name, const int N)
{
    std::fstream file_pointer(file_name.c_str(), std::fstream::in);
    file_pointer.seekg(0, ios::end);
    int file_size = file_pointer.tellg();
    return file_size;
}

int main(int argc, char **argv)
{
    string file_name = "";
    freopen(argv[1], "r+", stdin);
    std::getline(std::cin, file_name);
    std::fstream file(argv[2], std::fstream::out);
    file << file_size(argv[1], 1) << std::endl;
    file.close();
    return 0;
}
