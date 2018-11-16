#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <mutex>
#include <map>
#include <random>
#include <array>
#include <sstream>
#include <unordered_map>
#define MIN_RANGE 21
#define MAX_RANGE 99999
using namespace std;
// Command cmake . && make && time ./trexxa outfile.txt infile.txt 

struct Star
{
    double id, x, y, z;
    inline bool operator<(const Star& s) const {
        return Distance() < s.Distance();
    }
    double Distance() const {
        return sqrt(x*x + y*y + z*z);
    }
};

std::vector<Star> MinClosestStars(int k)
{
    std::vector<double> dump;
    priority_queue<Star, std::vector<Star> > max_heap;
    std::vector<Star> Star_arrays;
    std::string file_line, star_data;
    while(std::getline(std::cin, file_line))
    {
        stringstream ss(file_line);
        while(std::getline(ss, star_data, ',')){
            dump.emplace_back(std::stod(star_data));
        }
        max_heap.emplace(Star{dump[0], dump[1], dump[2], dump[3]});
        if(max_heap.size() == k + 1){
            max_heap.pop();
        }
    }

    while(!max_heap.empty())
    {
        Star_arrays.emplace_back(max_heap.top());
        max_heap.pop();
    }

    std::reverse(Star_arrays.begin(), Star_arrays.end());
    return Star_arrays;
}

std::vector<std::vector<int> > sorted_arrays;
int main(int argc, char **argv)
{
    string token, ints = "";
    std::vector<int> dump;
    freopen(argv[1], "r+", stdin);
    freopen(argv[2], "w+", stdout);
    auto star_data = MinClosestStars(4);
    for(const auto& s : star_data){
        std::cout << "Item : " << s.id << " Dist : " << s.Distance() << std::endl;
    }
    return 0;
}

