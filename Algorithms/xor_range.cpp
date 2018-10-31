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
    #define MIN_RANGE 59845578
    #define MAX_RANGE 780000477
    using namespace std;

    long long xor_func(const long long &a)
    {
        // 4K, 4K+1, 4K+2, 4K+3.
        long long xor_result_array[] = {a, 1, a + 1, 0};
        return xor_result_array[a & 3]; // a % 4.
    }

    long long xor_range(const long long a, const long long b)
    {
        return (xor_func(a) ^ xor_func(b - 1));
    }

    int main(int argc, char **argv)
    {
        freopen(argv[1], "r+", stdin);
        freopen(argv[2], "w+", stdout);
        std::cout << xor_range(MIN_RANGE, MAX_RANGE) << std::endl;
        return 0;
    }
