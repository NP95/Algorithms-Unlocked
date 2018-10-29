#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void RemoveChar(std::string &input, char rmove)
{
    // Erase-Remove Idiom.
    input.erase(std::remove(input.begin(), input.end(), rmove), input.end());
}

int main(void)
{
    string str = "";
    std::getline(cin, str);
    RemoveChar(std::ref(str), 'a');
    std::cout << str << std::endl;
    return 0;
}