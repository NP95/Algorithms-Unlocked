/**
 * CodeObsess® (SpawnTree)
 * Copyright © 2018 CodeObsess® All rights reserved
 * Feel free to use this code as you like. --attribute please.
 */

#ifndef static_h
#define static_h

#ifndef MIN_RANGE
#define MIN_RANGE 0
#endif

#ifndef MAX_RANGE
#define MAX_RANGE 655369636
#endif

#ifndef RANDOM_RANGE
#define RANDOM_RANGE 854412
#endif

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
    #include <curlpp/Easy.hpp>
    #include <curlpp/Options.hpp>
    #include <curlpp/cURLpp.hpp>
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
    #include <typeinfo>
    #include <ctype.h>
    #include <exception>
    #include <ctime>
    #include <time.h>
    #include <chrono>
    #include <system_error>
    #include <initializer_list>
    #include <tuple>
    #include <stdexcept>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/pb_ds/hash_policy.hpp>
    #include <ext/pb_ds/trie_policy.hpp>
    #include <ext/pb_ds/tag_and_trait.hpp>
    #include <ext/pb_ds/detail/standard_policies.hpp>
    #include <iomanip>

#endif /* static headers */

/* #define */
#define bit(x, i) ( x & (1<<i) )
#define lowbit(x) ( (x)&((x)^((x)-1)) )
#define hBit(msb, n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n))
#define MOD 10000000003
#define print(vec) for (const auto& i : vec) cout << i << endl;
#define fori(vec) for (const auto& i : vec)
#define fill(vec,size) for (auto i = 0; i < size; i++) { vec.pb(i); }
#define input(ss, inputbuffer) while(cin.good()) { getline(cin, inputbuffer); ss << inputbuffer << endl; }
#define inputLL(j, vec) while(cin.good()) { cin >> j;  vec.pb(j); }
#define sz(a) int((a).size())
#define vect(T) std::vector<T>
#define stck(T) std::stack<T>
#define dq(T) std::deque<T>
#define q(T) std::queue<T>
#define arr(T) std::array<T>
#define bits(T) std::bitset<T>
#define SIZE 655360
#define itn int
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define max(a, b) (a < b ? b : a)
#define full_all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rev(A) std::reverse(A.begin(), A.end())
#define container_sort(A) std::sort(A.begin(),A.end())
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forvec(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)
#define Assert(x) {if(!(x)){cerr<<"Assertion failed at line "<<__LINE__<<": "<<#x<<" = "<<(x)<<"\n";exit(1);}}
#define abs(x) ( x < 0 ? (-x) : x)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout)
#define LL long long

using namespace std;
using namespace __gnu_pbds;

/* Templates */
template <typename T> T min(T &a, T &b) {return (a < b ? a : b);}
template <typename T> T mod(T &a, T &b) { return (a < b ? a : a % b);}
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((long double)a*(long double)b)/(long double)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T> T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T> T power(T e, T n, T m){T x=1%m,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template<typename T> T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n){T x,y;T d = extended_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}
template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}
template <typename T> T gcd(T a, T b){return (!b)? a:gcd(b,a%b); }
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b))); }

/* Random bits */
std::random_device rd;
std::default_random_engine seed(rd());
std::uniform_int_distribution<int> random_engine_block(MIN_RANGE, MAX_RANGE);
auto rd_ints = std::bind(random_engine_block, seed);

typedef tree <int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update > red_black_tree;
typedef trie <string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> patricia_trie;

const uint64_t lr_mod  = 1000000003; // (10e9 + 3)

static uint64_t huge_mod_power(uint64_t base, uint64_t power)
{
    clock_t start_time;
    static uint64_t expo = base;
    while(power)
    {
        expo %= lr_mod;
        if (!(power & 1)){
            expo *= (expo % lr_mod);
            power >>= 1;
        } else {
            expo *= (base % lr_mod);
            --power;
        }
    }
    clock_t end_time = clock() - start_time;
    std::cerr << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
    return expo;
}

static std::vector<std::vector<uint64_t> > matrix (size_t row, size_t col, uint64_t value)
{
    clock_t start_time;
    std::vector<std::vector<uint64_t> > mat;
    std::vector<uint64_t> dump(col, value);
    for(unsigned i = 0; i < row; i++){
        mat.emplace_back(dump);
    }
    clock_t end_time = clock() - start_time;
    std::cerr << "Matrix : " << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
    return mat;
}

/* Blocked Cache Obvious matrix multiplication */
static std::vector<std::vector<uint64_t> > fast_matrix_modulo_multiplication(std::vector<std::vector<uint64_t> > &A, std::vector<std::vector<uint64_t> > &B)
{
    clock_t start_time;
    std::vector<std::vector<uint64_t> > C = matrix(A.size(), B[0].size(), 0);
    int cache_line = 1 << 3; /* 64B */
#pragma omp simd
    for(unsigned i = 0; i < A.size(); i += cache_line){
        for(unsigned j = 0; j < B[0].size(); j += cache_line){
            for (unsigned k = 0; k < B[0].size(); k += cache_line){
                for(unsigned il = i; il < (i + cache_line); il++){
                    for(unsigned jl = j; jl < (j + cache_line); jl++){
                        for (unsigned kl = k; kl < (k + cache_line); kl++){
                            C[il][jl] += ((A[il][kl])%lr_mod * (B[kl][jl])%lr_mod)%lr_mod;
                        }
                    }
                }
            }
        }
    }
    clock_t end_time = clock() - start_time;
    std::cerr << "Fast : " <<  ((float)end_time)/CLOCKS_PER_SEC << std::endl;
    return C;
}

static std::vector<std::vector<uint64_t> > slow_matrix_modulo_multiplication(std::vector<std::vector<uint64_t> > &A, std::vector<std::vector<uint64_t> > &B)
{
    clock_t start_time;
    std::vector<std::vector<uint64_t> > C = matrix(A.size(), B[0].size(), 0);
#pragma omp simd
    for(unsigned i = 0; i < A.size(); i++){
        for(unsigned j = 0; j < B[0].size(); j++){
            for (unsigned k = 0; k < B[0].size(); k++){
                C[i][j] += ((A[i][k])%lr_mod * (B[k][j])%lr_mod)%lr_mod;
            }
        }
    }
    clock_t end_time = clock() - start_time;
    std::cerr << "Slow : " << ((float)end_time)/CLOCKS_PER_SEC << std::endl;
    return C;
}

static void sizes()
{
    std::cout << "int : " <<  8 * sizeof(int) << " bits" <<  std::endl;
    std::cout << "char : " << 8 * sizeof(char) << " bits" <<  std::endl;
    std::cout << "long : " <<  8 * sizeof(long) << " bits" <<  std::endl;
    std::cout << "short : " <<  8 * sizeof(short) << " bits" <<  std::endl;
    std::cout << "float : " <<  8 * sizeof(float) << " bits" <<  std::endl;
    std::cout << "double : " <<  8 * sizeof(double) << " bits" <<  std::endl;
    std::cout << "long long : " <<  8 * sizeof(long long) << " bits" <<  std::endl;
    std::cout << "long double : " << 8 * sizeof(long double) << " bits" <<  std::endl;
    std::cout << "unsigned int : " <<  8 * sizeof(unsigned int) << " bits" <<  std::endl;
    std::cout << "unsigned long : " <<  8 * sizeof(unsigned long) << " bits" <<  std::endl;
    std::cout << "long long int : " <<  8 * sizeof(long long int) << " bits" <<  std::endl;
    std::cout << "unsigned int 64 : " <<  8 * sizeof(uint64_t) << " bits" <<  std::endl;
}

static uint64_t unsigned_ripple_carry_adder(uint64_t a, uint64_t b)
{
    uint64_t carryin = 0, sum = 0, mask = 1, temp_a = a, temp_b = b;
    while(temp_a || temp_b)
    {
        uint64_t a_last = a & mask;
        uint64_t b_last = b & mask;
        uint64_t carryout = (a_last & carryin) | (b_last & carryin) | (a_last & b_last);
        sum |= a_last ^ b_last ^ carryin;
        carryin = carryout << 1; mask <<= 1; temp_a >>= 1; temp_b >>= 1;
    }
    return sum | carryin;
}

static uint64_t ripple_multiply(uint64_t x, uint64_t y)
{
    uint64_t sum = 0;
    while(x)
    {
        if(x & 1){
            sum = unsigned_ripple_carry_adder(sum, y);
        }
        x >>= 1; y <<= 1;
    }
    return sum;
}

/* Appended working code here using freopen() */

template <typename T>
struct AVLNode;

template <typename T>
using nodeptr = std::shared_ptr<AVLNode<T> >;

/* AVL Tree Node */
template <typename T>
struct AVLNode
{
    T data;
    int balance;
    nodeptr<T> left, right, parent;
    AVLNode(T value, nodeptr<T> p) : data(value), parent(p),
        left(nullptr), right(nullptr), balance(0){
            std::cerr << "AVL Tree __static_node_initialization__." << std::endl;
    }
    ~AVLNode(){
        std::cerr << "AVL Tree __static__initialization__and__destruction__.";
    }
};

template <typename T>
class balanced_set
{
public:
    balanced_set (void) noexcept {
        std::cerr << "AVL Tree __static_initialization__." << std::endl;
    }
    ~balanced_set (void) noexcept {
        std::cerr << "AVL Tree __static_destruction__." << std::endl;
    }
    bool insert_key (const T value);
    bool delete_key (const T value);
    void print_tree_balance ();
private:
    nodeptr<T> root;
    nodeptr<T> rotateLeft (nodeptr<T> a);
    nodeptr<T> rotateRight (nodeptr<T> a);
    nodeptr<T> rotateLeftthenRight (nodeptr<T> a);
    nodeptr<T> rotateRightthenLeft (nodeptr<T> a);
    void rebalance (nodeptr<T> a);
    int height (nodeptr<T> a);
    void setbalance (nodeptr<T> a);
    void printbalance (nodeptr<T> a);
    void clearnode (nodeptr<T> a);
};




void solution(int argc, char* argv[], char* envp[])
{
    
}

int main(int argc, char* argv[], char* envp[])
{
#ifdef OFFLINE_START_BUILD
    CM_TRACE_FILE(TRACE);
    CM_TRACE_FUNC("main");
    start_time = clock();
    intialize_io("testcase");
    build_log();
    // HackerRank(); /* Unzip and copy files for input */
    // codejam(); /* Unzip and copy files for input */
#endif
    solution(argc, argv, envp);
#ifdef OFFLINE_START_BUILD
    build_solution();
    // std::cerr << "Solution Accepted : 0/1 -> " << Output_Compare() << std::endl; /* Automated comapre of output files */
    end_time_log(start_time, argc, argv, envp);
    /* Check mailbox for compilation & deployment status. */
#endif
    return 0;
}
