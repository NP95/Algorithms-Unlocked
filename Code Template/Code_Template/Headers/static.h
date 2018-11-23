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

/* Random Global */
std::random_device rd;
std::mt19937 seed(rd());
std::uniform_int_distribution<int> random_engine_block(MIN_RANGE, MAX_RANGE);
auto rd_ints = std::bind(random_engine_block, seed);
clock_t start_time, end_time;

#endif /* static_h */

typedef tree <int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
/* insert(elem), ptr->find_by_order(order_level) */

// An interval of unsigned integers.
typedef pair< unsigned int, unsigned int> interval;

// Functor updating maximal endpoints of entries. Algorithm taken from
// "Introduction to Algorithms" by Cormen, Leiserson, and Rivest.
template<class Const_Node_Iterator,
class Node_Iterator,
class Cmp_Fn,
class Allocator>
struct intervals_node_update
{
    public:
    // The metadata that each node stores is the largest endpoint of an
    // interval in its subtree. In this case, this is an unsigned int.
    typedef unsigned int metadata_type;
    
    // Checks whether a set of intervals contains at least one interval
    // overlapping some interval. Algorithm taken from "Introduction to
    // Algorithms" by Cormen, Leiserson, and Rivest.
    bool
    overlaps(const interval& r_interval)
    {
        Const_Node_Iterator nd_it = node_begin();
        Const_Node_Iterator end_it = node_end();
        
        while (nd_it != end_it)
        {
            // Check whether r_interval overlaps the current interval.
            if (r_interval.second >= (*nd_it)->first&&
                r_interval.first <= (*nd_it)->second)
            return true;
            
            // Get the const node iterator of the node's left child.
            Const_Node_Iterator l_nd_it = nd_it.get_l_child();
            
            // Calculate the maximal endpoint of the left child. If the
            // node has no left child, then this is the node's maximal
            // endpoint.
            const unsigned int l_max_endpoint =(l_nd_it == end_it)?
            0 : l_nd_it.get_metadata();
            
            // Now use the endpoint to determine which child to choose.
            if (l_max_endpoint >= r_interval.first)
            nd_it = l_nd_it;
            else
            nd_it = nd_it.get_r_child();
        }
        
        return false;
    }
    
    protected:
    // Update predicate: nd_it is a node iterator to the node currently
    // updated; end_nd_it is a const node iterator to a just-after leaf
    // node.
    inline void
    operator()(Node_Iterator nd_it, Const_Node_Iterator end_nd_it)
    {
        // The left maximal endpoint is 0 if there is no left child.
        const unsigned int l_max_endpoint =(nd_it.get_l_child() == end_nd_it)?
        0 : nd_it.get_l_child().get_metadata();
        
        // The right maximal endpoint is 0 if there is no right child.
        const unsigned int r_max_endpoint =(nd_it.get_r_child() == end_nd_it)?
        0 : nd_it.get_r_child().get_metadata();
        
        // The maximal endpoint is the endpoint of the node's interval,
        // and the maximal endpoints of its children.
        const_cast<unsigned int&>(nd_it.get_metadata()) =
        max((*nd_it)->second, max<unsigned int>(l_max_endpoint, r_max_endpoint));
    }
    
    virtual Const_Node_Iterator
    node_begin() const = 0;
    
    virtual Const_Node_Iterator
    node_end() const = 0;
    
    virtual
    ~intervals_node_update()
    { }
};

// The following function performs some operation sequence on a
// generic associative container supporting order statistics. It
// inserts some intervals, and checks for overlap.
template<class Cntnr>
void
some_op_sequence(Cntnr r_c)
{
    // Insert some entries.
    r_c.insert(make_pair(0, 100));
    r_c.insert(make_pair(150, 160));
    r_c.insert(make_pair(300, 1000));
    r_c.insert(make_pair(10000, 100000));
    r_c.insert(make_pair(200, 100200));
    
    // Test overlaps.
    
    // Overlaps 150 - 160
    assert(r_c.overlaps(make_pair(145, 165)) == true);
    // Overlaps 150 - 160
    assert(r_c.overlaps(make_pair(145, 155)) == true);
    assert(r_c.overlaps(make_pair(165, 175)) == false);
    assert(r_c.overlaps(make_pair(100201, 100203)) == false);
    
    // Erase an interval
    r_c.erase(make_pair(150, 160));
    
    // Test overlaps again.
    assert(r_c.overlaps(make_pair(145, 165)) == false);
    assert(r_c.overlaps(make_pair(165, 175)) == false);
    assert(r_c.overlaps(make_pair(0, 300000)) == true);
}
