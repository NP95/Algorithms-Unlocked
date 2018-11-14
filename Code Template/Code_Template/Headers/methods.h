//
//  methods.h
//  Google_Code
//
//  Created by SUMIT  LAHIRI on 11/4/18.
//  Copyright © 2018 Google PPLNS. All rights reserved.
//

#ifndef methods_h
#define methods_h
#include "static.h"

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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rev(A) std::reverse(A.begin(), A.end())
#define sort(A) std::sort(A.begin(),A.end())
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forvec(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)
#define abs(x) ( x < 0 ? (-x) : x) // big bug here if "-x" is not surrounded by "()"
using std::chrono::duration_cast;
using namespace std;
 
/* Templates */
template<class T> bool smaller(T &a, T &b) { return a < b ? true : false; }
template<class T> bool bigger(T &a, T &b) { return a > b ? true : false; }
template<class T, class U> T modulo(T& a, U& b) { return a % b; }
<<<<<<< HEAD
=======

void ioutil()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /* STDIN, STDOUT, STDERR */
    freopen(STDIN_FILE_REDIRECT, "r+", stdin);
    freopen(STDOUT_FILE_REDIRECT, "a+", stdout);
    freopen(STDOUT_LOGGER_ERROR_REDIRECT, "a+", stderr);
}
>>>>>>> 50f6c09ec5ca23875d3985c927b21537844e5307

#endif /* methods_h */

