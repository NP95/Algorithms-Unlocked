#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
using namespace std;

string RemoveSpace(string input_string)
{
    char delimiter = ' ';
    size_t pos = input_string.find(delimiter);
    /* Remove all space in beginning */
    while(input_string[pos] == ' '){
        pos = input_string.find(delimiter);
        input_string.erase(input_string.begin(), input_string.begin() + pos + 1);
    }
    /* First space left */
    input_string.erase(input_string.begin(), input_string.begin() + pos);
    /* All space space removed from front. Now remove the first order number. */
    pos = input_string.find(delimiter);
    input_string.erase(input_string.begin(), input_string.begin() + pos);
    /* Return the string */
    return input_string;
}

int main(void)
{
    string input, dump;
    fstream file, outfile;
    file.open("commands.txt", std::fstream::in);
    outfile.open("commands_bash.sh", std::fstream::out);
    if(file.fail() || outfile.fail()){
        std::cout << "Error opening the files. Please check sudo and files exists." << std::endl;
        exit(EXIT_FAILURE);
    } else {
        while(!file.eof()){
            if(file.eof()) break;
            std::getline(file, input);
            dump = RemoveSpace(input);
            outfile << dump << std::endl;
        }
    }
    file.close();
    outfile.close();
    return 0;
}
