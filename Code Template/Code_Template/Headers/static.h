/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef static_h
#define static_h

#ifdef __clang__
#    pragma clang system_header
#elif defined __GNUC__
#    pragma GCC system_header
#endif

#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
#ifdef _WIN64
//define something for Windows (64-bit only)
#else
//define something for Windows (32-bit only)
#endif
#elif __APPLE__
    #include "TargetConditionals.h"
    #include <sys/types.h>
    #include <unistd.h>
    #include <sys/resource.h>
    #include <openssl/sha.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <sys/mman.h>
    #include <errno.h>
    #include <netinet/in.h>
    #include <netdb.h>
    #include <arpa/inet.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#elif TARGET_OS_IPHONE
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#   error "Unknown Apple platform"
#endif
#elif __linux__
    #include <unistd.h>
    #include <sys/resource.h>
    #include <openssl/sha.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
    #include <sys/mman.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>
    #include <errno.h>
#elif __unix__ // all unices not caught above
// Unix
#elif defined(_POSIX_VERSION)
// POSIX
#else
#   error "Unknown compiler"
#endif

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <array>
#include <bitset>
#include <functional>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <math.h>
#include <thread>
#include <forward_list>
#include <list>
#include <ios>
#include <streambuf>
#include <atomic>
#include <future>
#include <mutex>
#include <thread>
#include <numeric>
#include <random>
#include <regex>
#include <utility>
#include <type_traits>
#include <typeinfo>
#include <exception>
#include <ctime>
#include <time.h>
#include <chrono>
#include <system_error>
#include <initializer_list>
#include <tuple>
#include <ctype.h>
#include <stdexcept>
#include <iomanip>
#include "constants.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace pb_ds;
using namespace pb_ds;

/* Random Global */
std::random_device rd;
std::mt19937 seed(rd());
std::uniform_int_distribution<int> random_engine_block(MIN_RANGE, MAX_RANGE);
auto rd_ints = std::bind(random_engine_block, seed);
clock_t start_time, end_time;

#endif /* static_h */

