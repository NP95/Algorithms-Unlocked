/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifdef __clang__
#    pragma clang system_header
#elif defined __GNUC__
#    pragma GCC system_header
#endif

#ifndef MIN_RANGE
#define MIN_RANGE 0
#endif

#ifndef MAX_RANGE
#define MAX_RANGE 655369636
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
#include <exception>
#include <ctime>
#include <time.h>
#include <chrono>
#include <system_error>
#include <initializer_list>
#include <tuple>
#include <stdexcept>
#include <iomanip>

/* #define */
#define bit(x, i) ( x & (1<<i) )  //select the bit of position i of x
#define lowbit(x) ( (x)&((x)^((x)-1)) ) //get the lowest bit of x
#define hBit(msb, n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
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
#define SIZE 65536
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
#define abs(x) ( x < 0 ? (-x) : x) // big bug here if "-x" is not surrounded by "()"
#define LL long long int
using namespace std;

/* Templates */
template <typename T> T min(T &a, T &b) {return (a < b ? a : b);}
template <typename T> T mod(T &a, T &b) { return (a < b ? a : a % b);}
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((long double)a*(long double)b)/(long double)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T> T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T> T power(T e, T n, T m){T x=1%m,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template<typename T> T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n){T x,y;T d = extended_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}
template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}
template <typename T> T gcd(T a, T b){return (!b)? a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));

std::random_device rd;
std::default_random_engine seed(rd());
std::uniform_int_distribution<int> random_engine_block(MIN_RANGE, MAX_RANGE);
auto rd_ints = std::bind(random_engine_block, seed);

/* Appended code here using freopen() */


/* Functions Here */
const int N = 1234567;

int to[N], ta[N], tb[N];
vector <int> inc[N];
int cost[N];
int a[N], b[N];
int p[N];
int out[N], comp[N];
vector < pair < int, pair <int, int> > > edges;

int find_set(int x) {
  if (x != p[x]) {
    p[x] = find_set(p[x]);
  }
  return p[x];
}

int match(int j, int i) {
  int wait = ((ta[j] - (ta[i] + tb[i])) % 24 + 24) % 24;
  return wait;
}

/* Main Here */

int main(int argc, char* argv[])
{
#ifdef /*__APPLE__ || */ _WIN32 || _WIN64
    start_time = clock();
    ioutil("codejam-large-c");
#endif
    
    int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      inc[i].clear();
    }
    for (int i = 0; i < 2 * n; i++) {
      scanf("%d %d %d", to + i, ta + i, tb + i);
      to[i]--;
    }
    int res = (int) 1e9;
    for (int rot = 0; rot < 2; rot++) {
      swap(to[0], to[1]);
      swap(ta[0], ta[1]);
      swap(tb[0], tb[1]);
      for (int i = 0; i < n; i++) {
        inc[i].clear();
      }
      for (int i = 0; i < 2 * n; i++) {
        inc[to[i]].push_back(i);
      }
      int ans = ta[0];
      for (int i = 0; i < 2 * n; i++) {
        ans += tb[i];
      }
      for (int i = 0; i < n; i++) {
        if (i != 0) {
          int x = match(2 * i, inc[i][0]) + match(2 * i + 1, inc[i][1]);
          int y = match(2 * i, inc[i][1]) + match(2 * i + 1, inc[i][0]);
          if (x > y) {
            swap(x, y);
            swap(inc[i][0], inc[i][1]);
          }
          cost[i] = y - x;
          ans += x;
        } else {
          int x = match(2 * i + 1, inc[i][1]);
          int y = match(2 * i + 1, inc[i][0]);
          if (x > y) {
            swap(x, y);
            swap(inc[i][0], inc[i][1]);
          }
          cost[i] = y - x;
          ans += x;
        }
      }
      for (int i = 0; i < 2 * n; i++) {
        a[i] = i;
      }
      for (int i = 0; i < n; i++) {
        b[inc[i][0]] = 2 * i;
        b[inc[i][1]] = 2 * i + 1;
      }
      for (int i = 0; i < 2 * n; i++) {
        out[a[i]] = b[i];
      }
      for (int i = 0; i < 2 * n; i++) {
        comp[i] = -1;
      }
      int nc = 0;
      for (int i = 0; i < 2 * n; i++) {
        if (comp[i] != -1) {
          continue;
        }
        int p = i;
        while (comp[p] == -1) {
          comp[p] = nc;
          p = out[p];
        }
        nc++;
      }
      edges.clear();
      for (int i = 0; i < n; i++) {
        int x = comp[2 * i];
        int y = comp[2 * i + 1];
        if (x != y) {
          edges.push_back(make_pair(cost[i], make_pair(x, y)));
        }
      }
      sort(edges.begin(), edges.end());
      for (int i = 0; i < nc; i++) {
        p[i] = i;
      }
      for (auto &e : edges) {
        int x = find_set(e.second.first);
        int y = find_set(e.second.second);
        if (x != y) {
          ans += e.first;
          p[x] = y;
        }
      }
      for (int i = 0; i < nc; i++) {
        assert(find_set(i) == find_set(0));
      }
      res = min(res, ans);
    }
    printf("%d\n", res);
  }

#ifdef /*__APPLE__ || */ _WIN32 || _WIN64
    copy_codechef();
    log_time(start_time, argc, argv);
    close();
#endif
    return 0;
}

/* Finished */
