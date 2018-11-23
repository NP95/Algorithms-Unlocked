#include "Headers/headers.h"

typedef tree <int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

// A PATRICIA trie with a prefix-search node-updator type. Note that
// since the node updator is trie_prefix_search_node_update, then the
// container includes its method prefix_range.
typedef null_mapped_type        mapped_type;
typedef string_trie_e_access_traits<>     cmp_fn;
typedef pat_trie_tag             tag_type;

typedef trie<string, mapped_type, cmp_fn, tag_type,
trie_prefix_search_node_update> trie_type;

// The following helper function takes a trie object and r_key, a
// const reference to a string, and prints all entries whose key
// includes r_key as a prefix.
void
print_prefix_match(const trie_type& t, const string& key)
{
    typedef trie_type::const_iterator         const_iterator;
    typedef pair<const_iterator, const_iterator>     pair_type;
    
    cout << "All keys whose prefix matches \"" << key << "\":" << endl;
    
    const pair_type match_range = t.prefix_range(key);
    for (const_iterator it = match_range.first; it != match_range.second; ++it)
    cout << *it << ' ';
    cout << endl;
}

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
