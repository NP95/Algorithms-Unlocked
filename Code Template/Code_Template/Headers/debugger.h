/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef debugger_h
#define debugger_h
#include "static.h"


#define Assert(x) {if(!(x)){cerr<<"Assertion failed at line "<<__LINE__<<": "<<#x<<" = "<<(x)<<"\n";exit(1);}}
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)

#endif /* debugger_h */
