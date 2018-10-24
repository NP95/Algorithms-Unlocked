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
    /* We are removing white spaces so delimiter is a white space character */
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

std::vector<string> SplitWordsTokenizer (string input_string)
{
    /* Remove extra white spaces between words in a string. Unique puts it to the back of the string. */
    string::iterator str_end_iter = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y){
        return x == y && x == ' ';
    });
    /* Remove all extra white spaces from the end of the string */
    input_string.erase(str_end_iter, input_string.end());
    while(input_string[input_string.length() - 1] == ' '){
        input_string.pop_back();
    }
    std::vector<string> split_tokens;
    char delimiter = ' ';
    size_t pos, i = 0;
    /* Find white spaces and tokenized the string by slicing into substrings. Push back the sub strings. */
    pos = input_string.find(delimiter);
    while(pos != string::npos){
        split_tokens.push_back(input_string.substr(i, pos - i));
        i = pos + 1;
        pos = input_string.find(delimiter, i);
        /* Find the next white space and push it back. */
    }
    /* Last part of the string is still left out. */
    split_tokens.push_back(input_string.substr(i, std::min(pos, input_string.length())-i+1 ));
    /* Return vector of tokens */
    return split_tokens;
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
        outfile << "Comma seperated words from raw text file." << std::endl;
        while(!file.eof()){
            if(file.eof()) break;
            std::getline(file, input); /* Hidden Caveats here. */
            dump = RemoveSpace(input); /* Remove Numbers. */
            auto tokens = SplitWordsTokenizer(dump); /* Tokenize and print output. */
            outfile << "Line : ";
            for(const auto& tok : tokens){
                outfile << tok << ",";
            }
            outfile << " ($end)" << std::endl;
        }
    }
    file.close();
    outfile.close();
    return 0;
}
