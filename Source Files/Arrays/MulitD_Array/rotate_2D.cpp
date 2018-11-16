#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include <mutex>
#include <map>
#include <random>
#include <array>
#include <sstream>
#include <unordered_map>
using namespace std;
 
std::vector<std::vector<int> > square_matrix;
std::vector<std::vector<int> > B;

std::vector<std::vector<int> > RotateMatrix(std::vector<std::vector<int> > &square_matrix)
{
    std::vector<int> dump;
    auto size = square_matrix.size();
    for(auto i = 0; i < size; i++){
        for(auto j = 0; j < size; j++){
            dump.emplace_back(0);
        }
        B.emplace_back(dump);
        dump.clear();
    }
    for(auto i = 0; i < size; i++){
        for(auto j = 0; j < size; j++){
            B[i][j] = square_matrix[size - 1- j][i];
        }
    }
    return B;
}

int main(int argc, char **argv)
{
    string ints = "";
    freopen(argv[1], "r+", stdin);
    freopen(argv[2], "w+", stdout);
    std::vector<int> dump, val;
    for(auto i = 0; i < 15; i++){
        val.emplace_back(i);
    }
    for(auto i = 0; i < 15; i++){
        for(auto j = 0; j < 15; j++){
            dump.emplace_back(val[i]);
        }
        square_matrix.emplace_back(dump);
        dump.clear();
    }
    for(const auto& e : square_matrix){
        for(const auto& u : e){
            std::cout << " " << u << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    auto sq = RotateMatrix(std::ref(square_matrix));
    for(const auto& e : sq){
        for(const auto& u : e){
            std::cout << " " << u << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
