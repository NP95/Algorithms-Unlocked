#include "Headers/headers.h"

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


void solution(int argc, char* argv[], char* envp[])
{
    // Test a red-black tree.
    some_op_sequence(tree<
                     interval,
                     null_mapped_type,
                     less<interval>,
                     rb_tree_tag,
                     intervals_node_update>());
    
    // Test an ordered-vector tree.
    some_op_sequence(tree<
                     interval,
                     null_mapped_type,
                     less<interval>,
                     ov_tree_tag,
                     intervals_node_update>());
    
    // Test a splay tree.
    some_op_sequence(tree<
                     interval,
                     null_mapped_type,
                     less<interval>,
                     splay_tree_tag,
                     intervals_node_update>());
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
