#include "BinarySearchTree.h"

namespace BST_NS {

    BinarySearchTree() {
        root(NULL);
        tree_size(0);
    }

    BinarySearchTree(const BinarySearchTree& other) {
        makeEmpty();
        copyTree(other.root, root); //wrong fix this
        tree_size = other.tree_size;
    }

    virtual ~BinarySearchTree() {
        
    }
    template<class T>
    void insert(T item) {
        TreeNode<T> *newNode = new TreeNode(item);
        if(newNode < ) {

        }
    }
    template<class T>
    void remove(T item) {
        
    }
    template<class T>
    bool inTree(T item) const {

    }

    BinarySearchTree& operator=(const BinarySearchTree other) {

    }

    void makeEmpty() {

    }

    void preOrderShow() const {

    }

    void inOrderShow() const {

    }

    void postOrderShow() const {

    }

    int size() const {

    }

    int height() {

    }
    
} // namespace BST_NS