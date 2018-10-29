#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stdlib.h>
using namespace std;

bool ip_is_valid(const string& input)
{
    int value = 0;
    if(input.length() > 3){
        return false;
    }
    if(input.front() == '0' && input.length() > 1){
        return false;
    }
    try{
        value = stoi(input, nullptr, 10);
    } catch(std::exception& e) {
        std::cout << "Ill-formatted String. " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    return ((value <= 255) && (value >= 0));
}

std::vector<string> GetValidIPRanges(const string& raw_string)
{
    if(raw_string.length() > 12 || raw_string.length() < 4){
        throw "Invalid raw ip-string passed.";
    }
    std::vector<std::string> ipaddrs;
    for(size_t i = 1; i < 4; i++){
        auto first = raw_string.substr(0, i);
        if(ip_is_valid(first)){
            for(size_t j = 1; i + j < raw_string.length() && j < 4; j++){
                auto second = raw_string.substr(i, j);
                if(ip_is_valid(second)){
                    for(size_t k = 1; i + j + k < raw_string.length() && k < 4; k++){
                        auto third = raw_string.substr(i + j, k); 
                        auto fourth = raw_string.substr(i + j + k, string::npos);
                        if(ip_is_valid(third) && ip_is_valid(fourth)){
                            ipaddrs.emplace_back(first + "." + second + "." + third + "." + fourth);
                        }
                    }
                }
            }
        }
    }
    return ipaddrs;
}

int main(void)
{
    string input = "";
    std::getline(std::cin, input);
    auto ipaddrs = GetValidIPRanges(input);
    for(const auto& ip : ipaddrs){
        std::cout << "Valid IPs : " << ip << std::endl;
    }
}
