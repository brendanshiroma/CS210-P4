#include "BinarySearchTree.h"

namespace BST_NS {

    // Default Constructor
    template<class T>
    BinarySearchTree<T>::BinarySearchTree() : root(nullptr), tree_size(0) {}

    // Copy Constructor
    template<class T>
    BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) {
        root = copyTree(other.root);
        tree_size = other.tree_size;
    }

    // Destructor
    template<class T>
    BinarySearchTree<T>::~BinarySearchTree() {
        makeEmpty();
    }

    // Insert an item into the tree
    template<class T>
    void BinarySearchTree<T>::insert(T item) {
        if (root == nullptr) {
            root = new TreeNode<T>(item, nullptr, nullptr);
            tree_size++;
        } else {
            TreeNode<T>* curr = root;
            while (true) {
                if (item < curr->data) {
                    if (curr->leftLink == nullptr) {
                        curr->leftLink = new TreeNode<T>(item, nullptr, nullptr);
                        tree_size++;
                        break;
                    } else {
                        curr = curr->leftLink;
                    }
                } else {
                    if (curr->rightLink == nullptr) {
                        curr->rightLink = new TreeNode<T>(item, nullptr, nullptr);
                        tree_size++;
                        break;
                    } else {
                        curr = curr->rightLink;
                    }
                }
            }
        }
    }

    // Remove an item from the tree
    template<class T>
    void BinarySearchTree<T>::remove(T item) {
        if (root == nullptr)
            return;

        TreeNode<T>* parent = nullptr;
        TreeNode<T>* curr = root;

        while (curr != nullptr && curr->data != item) {
            parent = curr;
            if (item < curr->data)
                curr = curr->leftLink;
            else
                curr = curr->rightLink;
        }

        if (curr == nullptr)
            return;

        // Case 1: Node has no children
        if (curr->leftLink == nullptr && curr->rightLink == nullptr) {
            if (parent == nullptr) {
                delete root;
                root = nullptr;
            } else if (parent->leftLink == curr) {
                delete parent->leftLink;
                parent->leftLink = nullptr;
            } else {
                delete parent->rightLink;
                parent->rightLink = nullptr;
            }
            tree_size--;
        }
        // Case 2: Node has one child
        else if (curr->leftLink == nullptr) {
            if (parent == nullptr) {
                root = curr->rightLink;
            } else if (parent->leftLink == curr) {
                parent->leftLink = curr->rightLink;
            } else {
                parent->rightLink = curr->rightLink;
            }
            delete curr;
            tree_size--;
        } else if (curr->rightLink == nullptr) {
            if (parent == nullptr) {
                root = curr->leftLink;
            } else if (parent->leftLink == curr) {
                parent->leftLink = curr->leftLink;
            } else {
                parent->rightLink = curr->leftLink;
            }
            delete curr;
            tree_size--;
        }
        // Case 3: Node has two children
        else {
            TreeNode<T>* successor = curr->rightLink;
            TreeNode<T>* successorParent = curr;

            while (successor->leftLink != nullptr) {
                successorParent = successor;
                successor = successor->leftLink;
            }

            if (successorParent != curr) {
                successorParent->leftLink = successor->rightLink;
            } else {
                successorParent->rightLink = successor->rightLink;
            }

            curr->data = successor->data;
            delete successor;
            tree_size--;
        }
    }

    // Check if an item exists in the tree
    template<class T>
    bool BinarySearchTree<T>::inTree(T item) const {
        TreeNode<T>* curr = root;
        while (curr != nullptr) {
            if (curr->data == item) {
                return true;
            } else if (item < curr->data) {
                curr = curr->leftLink;
            } else {
                curr = curr->rightLink;
            }
        }
        return false;
    }

    // Assignment operator overload
    template<class T>
    BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree other) {
        if (this != &other) {
            makeEmpty();
            root = copyTree(other.root);
            tree_size = other.tree_size;
        }
        return *this;
    }

    // Empty the tree
    template<class T>
    void BinarySearchTree<T>::makeEmpty() {
        deleteTreeHelper(root);
        root = nullptr;
        tree_size = 0;
    }

    // Pre-Order Traversal
    template<class T>
    void BinarySearchTree<T>::preOrderShow() const {
        preOrderHelper(root);
    }

    // In-Order Traversal
    template<class T>
    void BinarySearchTree<T>::inOrderShow() const {
        inOrderHelper(root);
    }

    // Post-Order Traversal
    template<class T>
    void BinarySearchTree<T>::postOrderShow() const {
        postOrderHelper(root);
    }

    // Return the size of the tree
    template<class T>
    int BinarySearchTree<T>::size() const {
        return tree_size;
    }

    // Calculate the height of the tree
    template<class T>
    int BinarySearchTree<T>::height() {
        return treeHeight(root);
    }

    // Helper function to copy a tree
    template<class T>
    TreeNode<T>* copyTree(TreeNode<T>* node) {
        if (node == nullptr)
            return nullptr;
        else
            return new TreeNode<T>(node->data, copyTree(node->leftLink), copyTree(node->rightLink));
    }

    // Helper function to delete a tree
    template<class T>
    void deleteTreeHelper(TreeNode<T>* &node) {
        if (node != nullptr) {
            deleteTreeHelper(node->leftLink);
            deleteTreeHelper(node->rightLink);
            delete node;
            node = nullptr;
        }
    }

    // Helper function for pre-order traversal
    template<class T>
    void preOrderHelperHelper(TreeNode<T>* node) const {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrderHelper(node->leftLink);
            preOrderHelper(node->rightLink);
        }
    }

    // Helper function for in-order traversal
    template<class T>
    void inOrderHelper(TreeNode<T>* node) const {
        if (node != nullptr) {
            inOrderHelper(node->leftLink);
            std::cout << node->data << " ";
            inOrderHelper(node->rightLink);
        }
    }

    // Helper function for post-order traversal
    template<class T>
    void postOrderHelper(TreeNode<T>* node) const {
        if (node != nullptr) {
            postOrderHelper(node->leftLink);
            postOrderHelper(node->rightLink);
            std::cout << node->data << " ";
        }
    }

    // Helper function to calculate the height of the tree
    template<class T>
    int treeHeight(TreeNode<T>* node) {
        if (node == nullptr)
            return -1;
        else
            return 1 + std::max(treeHeight(node->leftLink), treeHeight(node->rightLink));
    }

} // namespace BST_NS