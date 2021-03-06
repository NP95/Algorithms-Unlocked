#include "Headers/headers.h"

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
public:
    balanced_set (void) noexcept {
        std::cerr << "AVL Tree __static_initialization__." << std::endl;
        root = nullptr;
    }
    ~balanced_set (void) noexcept {
        std::cerr << "AVL Tree __static_destruction__." << std::endl;
    }
    bool insert_key (const T value);
    bool delete_key (const T value);
    void print_tree_balance ();
};

template <typename T>
int balanced_set<T>::height (nodeptr<T> n)
{
    if(n == nullptr){
        std::cerr << "Null value reference. " << std::endl;
        return -1;
    }
    return (1 + std::max(height(n->left), height(n->right)));
}

template <typename T>
void balanced_set<T>::setbalance (nodeptr<T> n)
{
    n->balance = height(n->right) - height(n->left);
}

template <typename T>
void balanced_set<T>::printbalance (nodeptr<T> n)
{/* Inorder print balance */
    if(n != nullptr){
        printbalance (n->left);
        std::cout << n->balance << ", ";
        printbalance (n->right);
    }
}

template <typename T>
void balanced_set<T>::print_tree_balance ()
{
    printbalance(root);
    std::cout << std::endl;
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
