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
std::vector<std::vector<int> > square_matrix;

std::vector<int> PrintSpiralOrder (std::vector<std::vector<int> > &square_matrix)
{
    const std::array<std::array<int, 2>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    int dir = 0, x = 0, y = 0;
    std::vector<int> spiral_order;
    auto size = square_matrix.size();
    for(auto i = 0; i < (size * size); i++)
    {
        spiral_order.emplace_back(square_matrix[x][y]);
        square_matrix[x][y] = -1;
        int next_x = x + directions[dir][0];
        int next_y = y + directions[dir][1];
        if(next_x < 0 || next_x >= size || next_y < 0 || next_y >= size || square_matrix[next_x][next_y] == -1){
            dir = (dir + 1) % 4;
            next_x = x + directions[dir][0];
            next_y = y + directions[dir][1];
        }
        x = next_x;
        y = next_y;
    }
    return spiral_order;
}

int main(int argc, char **argv)
{
    string ints = "";
    freopen(argv[1], "r+", stdin);
    freopen(argv[2], "w+", stdout);
    std::vector<int> dump;
    for(auto i = 0; i < 2000; i++){
        for(auto j = 0; j < 2000; j++){
            std::getline(std::cin, ints);
            auto value = std::stoi(ints, nullptr, 10);
            dump.emplace_back(value);
        }
        square_matrix.emplace_back(dump);
        dump.clear();
    }
    dump = PrintSpiralOrder(std::ref(square_matrix));
    for(const auto& e : dump){
        std::cout << "sp" << e << std::endl;
    }
    return 0;
}
