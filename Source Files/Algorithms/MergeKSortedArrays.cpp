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

struct IterCompare
{
    std::vector<int>::const_iterator current;
    std::vector<int>::const_iterator end;

    // Min Heap Comparator.
    inline bool operator<(const IterCompare& that) const {
        return (*(current) > *(that.current));
    }
};

std::vector<int> MergeSortedArrays (const std::vector<std::vector<int> > &sorted_arrays)
{
    priority_queue<IterCompare, vector<IterCompare> > min_heap;
    for(const auto& sorted_array : sorted_arrays){
        if(!sorted_array.empty()){
            min_heap.emplace(IterCompare{sorted_array.cbegin(), sorted_array.cend()});
        }
    }
    std::vector<int> result;
    while(!min_heap.empty()){
        auto smallest_top_array = min_heap.top();
        min_heap.pop();
        if(smallest_top_array.current != smallest_top_array.end)
        {
            result.emplace_back(*smallest_top_array.current);
            min_heap.emplace(IterCompare{std::next(smallest_top_array.current), smallest_top_array.end});
        }
    }
    return result;
}

std::vector<std::vector<int> > sorted_arrays;
int main(int argc, char **argv)
{
    string token, ints = "";
    std::vector<int> dump;
    freopen(argv[1], "r+", stdin);
    freopen(argv[2], "w+", stdout);
    while(std::getline(std::cin, ints))
    {   
        stringstream ss(ints);
        while(std::getline(ss, token, ',')){
            auto value = std::stoi(token, nullptr, 10);
            dump.emplace_back(value);
        }
        std::sort(dump.begin(), dump.end());
        sorted_arrays.emplace_back(dump);
        dump.clear();
        token.clear();
    }
    dump = MergeSortedArrays(std::ref(sorted_arrays));
    for(const auto& s : dump){
        std::cout << "Item : " << s << std::endl;
    }
    return 0;
}

