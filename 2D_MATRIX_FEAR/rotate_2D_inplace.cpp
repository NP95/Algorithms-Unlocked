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
// Command cmake . && make && time ./trexxa outfile.txt infile.txt 
// 12s --> 0.0012s (Very fast optimization.)
std::vector<std::vector<int> > square_matrix;

std::vector<std::vector<int> > RotateMatrix(std::vector<std::vector<int> > &square_matrix)
{
    auto matrix_size = square_matrix.size() - 1;
    for(auto i = 0; i < square_matrix.size()/2; i++){
        for(auto  j = i; j < matrix_size - i; j++){
            // Decreasing sqaure area concentrically. Square into square into square.
            // row, col --> n - col, row.
            int first = square_matrix[i][j];
            int second = square_matrix[matrix_size - i][matrix_size - j];
            int third = square_matrix[j][matrix_size - i];
            int fourth = square_matrix[matrix_size - j][i];
            square_matrix[i][j] = fourth;
            square_matrix[matrix_size - i][matrix_size - j] = third;
            square_matrix[matrix_size - j][i] = second;
            square_matrix[j][matrix_size - i] = first;
        }
    }
    return square_matrix;
}

int main(int argc, char **argv)
{
    string ints = "";
    freopen(argv[1], "r+", stdin);
    freopen(argv[2], "w+", stdout);
    std::vector<int> dump, val;
    for(auto i = 0; i < 2000; i++){
        val.emplace_back(i);
    }
    for(auto i = 0; i < 2000; i++){
        for(auto j = 0; j < 2000; j++){
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
