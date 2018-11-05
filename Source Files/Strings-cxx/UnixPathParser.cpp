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

std::string UNIXPathParser (const string& full_path)
{
    vector<string> path_name_stack;
    if(full_path.empty()){
        throw "No path string provided.";
    }
    if(full_path.front() == '/'){ // Absolute path given.
        path_name_stack.emplace_back("/");
    }
    stringstream stream(full_path);
    string token = "";
    while(std::getline(stream, token, '/'))
    {
        if(token == ".."){
            if(path_name_stack.empty() || path_name_stack.back() == ".."){
                path_name_stack.emplace_back(token);
            } else {
                if(path_name_stack.back() == "/")
                    throw "Invalid PATH Entered.";
            }
            path_name_stack.pop_back();
        }
        if(token != "." && token != ""){
            path_name_stack.emplace_back(token);
        }
    }
    string result;
    if(!path_name_stack.empty()){
        result = path_name_stack.front();
        for(auto i = 0; i < path_name_stack.size(); i++){
            if(i == 1 && result == "/"){
                result += path_name_stack[i];
            } else {
                result += "/" + path_name_stack[i];
            }
        }
    }
    return result;
}


int main(int argc, char **argv)
{
    string file_name = "";
    freopen(argv[1], "r+", stdin);
    std::getline(std::cin, file_name);
    std::fstream file(argv[2], std::fstream::out);
    file << UNIXPathParser(file_name) << std::endl;
    file.close();
    return 0;
}
