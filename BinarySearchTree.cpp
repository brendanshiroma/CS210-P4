/**
 * @file BinarySearchTree.cpp
 * @author <Brendan Shiroma> <129846870>
 * @brief This is the cpp file HashTable.cpp
 * @date 2024-04-30
 */
#include "BinarySearchTree.h"

namespace BST_NS {

        /**
         * @brief Construct a new Binary Search Tree object, copying off another tree
         * 
         * @note initializes the root to copy the other tree's root, and sets size to other 
         *       tree's size
         * @note however if other tree is empty, root is nullptr, and size is 0
        */
        template<class T>
        BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) {
            if (other.root == nullptr) {
                root = nullptr;
                tree_size = 0;
            } else {
                root = new TreeNode<T>(*other.root); // create a new root node with the same value as other's root
                copyNodes(root, other.root); // recursively copy the rest of the nodes with helper function
                tree_size = other.tree_size;
            }
        }

        /**
         * @brief deletes all nodes in Binary Search Tree
        */
        template<class T>
        BinarySearchTree<T>::~BinarySearchTree() {
            makeEmpty();
        }

        /**
         * @brief inserts item into tree properly following BST rules
         * 
         * @param item generic object to be inserted into tree
        */
        // Insert an item into the tree
        template<class T>
        void BinarySearchTree<T>::insert(T item) {
            if (root == nullptr) { //if the tree is empty, set the root to the 
                root = new TreeNode<T>(item, nullptr, nullptr);
                tree_size++;
            } else {
                TreeNode<T>* curr = root;
                while (true) {
                    if (item < curr->data) { // if item value is less than current, traverse left subtree
                        if (curr->leftLink == nullptr) { // if left child is null, set left child to new node
                            curr->leftLink = new TreeNode<T>(item, nullptr, nullptr);
                            tree_size++;
                            break;
                        } else {
                            curr = curr->leftLink; // keep traversing
                        }
                    } else { // value is greater than current, traverse right subtree
                        if (curr->rightLink == nullptr) { // if right child is null, set right child to new node
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

        /**
         * @brief removes a specified item from the tree
         * 
         * @param item generic object to be removed
         * 
         * @note need to restructure tree after removal
        */
        template<class T>
        void BinarySearchTree<T>::remove(T item) {
            if (root == nullptr) // If the tree is empty, there's nothing to remove
                return;
            TreeNode<T>* parent = nullptr; 
            TreeNode<T>* curr = root; 
            // Traverse through the tree to find the node to remove and its parent
            while (curr != nullptr && curr->data != item) {
                parent = curr; // Update parent pointer
                if (item < curr->data)
                    curr = curr->leftLink;
                else
                    curr = curr->rightLink;
            }
            if (curr == nullptr) { // If the item isn't found, return
                return;
            }
            // Node has no children
            if (curr->leftLink == nullptr && curr->rightLink == nullptr) { 
                if (parent == nullptr) { // If the node is the root
                    delete root;
                    root = nullptr;
                } else if (parent->leftLink == curr) { // If the node is a left child
                    delete parent->leftLink;
                    parent->leftLink = nullptr;
                } else { // If the node is a right child
                    delete parent->rightLink;
                    parent->rightLink = nullptr;
                }
                tree_size--; // Decrement tree size
            }
            // Node has one child
            else if (curr->leftLink == nullptr) { // If the node has only a right child
                if (parent == nullptr) {
                    root = curr->rightLink;
                } else if (parent->leftLink == curr) {
                    parent->leftLink = curr->rightLink;
                } else {
                    parent->rightLink = curr->rightLink;
                }
                delete curr;
                tree_size--;
            } else if (curr->rightLink == nullptr) { // If the node has only a left child
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
            // Node has two children
            else {
                TreeNode<T>* successor = curr->rightLink; // Find the successor node
                TreeNode<T>* successorParent = curr;
                while (successor->leftLink != nullptr) { // Traverse left to find the leftmost node in the right subtree
                    successorParent = successor;
                    successor = successor->leftLink;
                }
                if (successorParent != curr) {
                    successorParent->leftLink = successor->rightLink;
                } else {
                    successorParent->rightLink = successor->rightLink;
                }
                curr->data = successor->data; // Replace current node with its successor
                delete successor;
                tree_size--;
            }
        }


        /**
         * @brief checks if target is in BST
         * 
         * @param item generic item to be checked if in tree
         * 
         * @return true if found, false otherwise
        */
        template<class T>
        bool BinarySearchTree<T>::inTree(T item) const {
            TreeNode<T>* curr = root;
            while (curr != nullptr) { // traverses through tree
                if (curr->data == item) { 
                    return true;
                } else if (item < curr->data) { // if item is less than curr, traverse left subtree
                    curr = curr->leftLink;
                } else { // traverse right sub tree
                    curr = curr->rightLink;
                }
            }
            return false;
        }

        /**
         * @brief assigns the contents of another BST to the current BST
         * 
         * @param other the Binary Search Tree object whose nodes to assign
         * 
         * @return a reference to the current BST instance after assignment
         */
        template<class T>
        BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree other) {
            if (this != &other) {
                makeEmpty();
                if (other.root != nullptr) {
                    root = new TreeNode<T>(*other.root); // Create a new root node with the same value as other's root
                    copyNodes(root, other.root); // Recursively copy the rest of the nodes
                } else {
                    root = nullptr;
                }
                tree_size = other.tree_size;
            }
            return *this;
        }
 
        /**
         * @brief emptys all the nodes in the tree
         * 
         * @note uses helper method to recursively delete the nodes
         * @note sets the root back to nullptr and size to 0
        */
        template<class T>
        void BinarySearchTree<T>::makeEmpty() {
            deleteTreeHelper(root);
            root = nullptr; 
            tree_size = 0;
        }
        
        /**
         * @brief prints an array in pre-Order
         * 
         * @note uses helper method that recursively adds nodes in correct order
        */
        template<class T>
        void BinarySearchTree<T>::preOrderShow() const {
            preOrderHelper(root);
        }

        /**
         * @brief prints an array in in-Order
         * 
         * @note uses helper method that recursively adds nodes in correct order
        */
        // In-Order Traversal
        template<class T>
        void BinarySearchTree<T>::inOrderShow() const {
            inOrderHelper(root);
        }

        
        /**
         * @brief prints an array in post-Order
         * 
         * @note uses helper method that recursively adds nodes in correct order
        */
        // Post-Order Traversal
        template<class T>
        void BinarySearchTree<T>::postOrderShow() const {
            postOrderHelper(root);
        }

        /**
         * @brief returns the size of the tree
         * 
         * @return the size of the tree
        */
        template<class T>
        int BinarySearchTree<T>::size() const {
            return tree_size;
        }

        /**
         * @brief returns height of the tree
         * 
         * @note uses helper method that uses recursion to find the largest height in the tree
        */
        template<class T>
        int BinarySearchTree<T>::height() {
            return treeHeight(root);
        }

    private:
        /**
         * @brief helper method to all the nodes in a tree recursively 
         * 
         * @param node node to be copied
         * 
         * @note uses recursion to traverse through the whole tree and all the 
         *       left and right subtrees of each node
         * 
         * @return the new tree with the copied nodes
        */
        template<class T>
        TreeNode<T>* copyTree(TreeNode<T>* node) {
            if (node == nullptr)
                return nullptr;
            else
                return new TreeNode<T>(node->data, copyTree(node->leftLink), copyTree(node->rightLink));
        }

        /**
         * @brief helper method to delete a tree recursively
         * 
         * @param node address of node to start deleting from
         * 
         * @note traverses through whole tree and recursively goes through all nodes
        */
        template<class T>
        void deleteTreeHelper(TreeNode<T>* node) {
            if (node != nullptr) {
                deleteTreeHelper(node->leftLink);
                deleteTreeHelper(node->rightLink);
                delete node;
                node = nullptr;
            }
        }

        /**
         * @brief helper function to traverse in pre-Order
         * 
         * @param node the node to start the traversal
         * 
         * @note prints out the data, then recursively goes through left and right subtrees
        */
        template<class T>
        void preOrderHelper(TreeNode<T>* node) {
            if (node != nullptr) {
                std::cout << node->data << " ";
                preOrderHelper(node->leftLink);
                preOrderHelper(node->rightLink);
            }
        }

        /**
         * @brief helper function to traverse in in-Order
         * 
         * @param node the node to start the traversal
         * 
         * @note recursively goes through left subtree, then prints, then right subtree
        */
        template<class T>
        void inOrderHelper(TreeNode<T>* node) {
            if (node != nullptr) {
                inOrderHelper(node->leftLink);
                std::cout << node->data << " ";
                inOrderHelper(node->rightLink);
            }
        }

        /**
         * @brief helper function to traverse in post-Order
         * 
         * @param node the node to start the traversal
         * 
         * @note recursively goes through left subtree, then right subtree, then prints
        */
        template<class T>
        void postOrderHelper(TreeNode<T>* node){
            if (node != nullptr) {
                postOrderHelper(node->leftLink);
                postOrderHelper(node->rightLink);
                std::cout << node->data << " ";
            }
        }

        /**
         * @brief helper function to calculate height of the tree
         * 
         * @param node the node to start the traversal (the root)
         * 
         * @note if the node is null, there is no tree
         * @note else recursively find the max height by traversing through left and right subtrees
        */
        template<class T>
        int treeHeight(TreeNode<T>* node) {
            if (node == nullptr)
                return -1;
            else
                return 1 + std::max(treeHeight(node->leftLink), treeHeight(node->rightLink));
        }

        /**
         * @brief helper function that recursively copies the nodes of a binary search tree
         * 
         * @param current the current node in the new binary search tree being constructed
         * @param otherNode the node in the binary search tree being copied from
         * 
         * @note traverses through bst, and when encounters a node, creates a copy of the node
         *       and recursively copies left and right subtrees
        */
        template<class T>
        void copyNodes(TreeNode<T>*& current, const TreeNode<T>* otherNode) {
            if (otherNode->left != nullptr) {
                current->left = new TreeNode<T>(*otherNode->left); // Copy left child
                copyNodes(current->left, otherNode->left); // Recursively copy its left subtree
            }
            if (otherNode->right != nullptr) {
                current->right = new TreeNode<T>(*otherNode->right); // Copy right child
                copyNodes(current->right, otherNode->right); // Recursively copy its right subtree
            }
        }
} // namespace BST_NS