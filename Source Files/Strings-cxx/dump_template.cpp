#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include <mutex>
using namespace std;

int main(int argc, char **argv)
{
    string input = "";
    freopen(argv[1], "r+", stdin);
    std::fstream file(argv[2], std::fstream::out);
    std::getline(std::cin, input);
    string::iterator pos = std::unique(input.begin(), input.end());
    input.erase(pos, input.end());
    file << input << std::endl;
    file.close();
    return 0;
}
