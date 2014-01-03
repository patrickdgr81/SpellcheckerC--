/**
 * \file abstractset.hpp
 * \brief Provides AbstractSet<T>, a(n absract) set class template
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#include <iostream>
#include <set>
#include <stdlib.h>
#include <time.h>       /* time */
using namespace std;

template <typename T>
TreeSet<T>::Node::Node(const T& value)
:value_(value), right_(nullptr), left_(nullptr), nodeSize_(1)
{
    //nothing else to do
}

template <typename T>
TreeSet<T>::TreeSet()
    :  root_(), size_(0), height_(0)
{
    //nothing else to do
}

//Destructor that leaves the object in a sane (empty) state.
template <typename T>
TreeSet<T>::~TreeSet<T>()
{
    deleteNode(root_);
}

//Size of the Treeset.
template <typename T>
size_t TreeSet<T>::size() const
{
    return size_;
}

//Insert an object into the Treeset.
template <typename T>
void TreeSet<T>::insert(const T& insertee)
{
    insertAtLocation(root_,insertee);
    ++size_;
}

//check if value exists in tree
template <typename T>
bool TreeSet<T>::exists(const T& findee) const
{
    return existsAtLocation(root_, findee);
}

//print out entire tree, starting from left node
template <typename T>
std::ostream& TreeSet<T>::print(std::ostream& out) const
{
    return printNode(root_, out);
}

//prints out the height of the tree
template <typename T>
std::ostream& TreeSet<T>::showStatistics(std::ostream& out) const
{
    out << "Nodes " << size_ << " height " << height();
    return out;
}

//returns the longest path in the tree
template <typename T>
int TreeSet<T>::height() const
{
    return maxHeight(root_,0);
}

////Private helper functions

template <typename T>
void TreeSet<T>::insertAtRoot(Node*& here, const T& insertee)
{
    //if location is null, insert node
    if (here == nullptr) {
        here = new Node(insertee); 
    //otherwise, traverse down the tree and insert at that
    //location. Then rotate to make that node the root
    } else if (insertee < here->value_) {
        ++here->nodeSize_;
        insertAtRoot(here->left_, insertee); 
        rightRotate(here);
    } else {
        ++here->nodeSize_;
        insertAtRoot(here->right_, insertee); 
        leftRotate(here);
    } 
}

/**
 * Rotates the tree to the left.
 * \param top is b in the diagram.
 *
 *        b                       d
 *       / \                     / \
 *      /   \                   /   \
 *     A     d       ==>       b     E
 *          / \               / \
 *         /   \             /   \
 *        C     E           A     C
 */
template <typename T>
void TreeSet<T>::leftRotate(Node*& top)
{
    assert(top != nullptr);
    assert(top->right_ != nullptr);

    Node* b = top;
    Node* d = b->right_;        // d is b's right child
    b->right_ = d->left_;       // C becomes right child of b
    d->left_ = b;               // b becomes left child of d
    top = d;                    // top is now d

    b->size_ -= sizeNode(d->right_) + 1;
    d->size_ += sizeNode(b->left_)  + 1;
}


/**
 * Rotates the tree to the right.
 * \param top is d in the diagram.
 *
 *           d                 b
 *          / \               / \
 *         /   \             /   \
 *        b     E    ==>    A     d
 *       / \                     / \
 *      /   \                   /   \
 *     A     C                 C     E
 */
template <typename T>
void TreeSet<T>::rightRotate(Node*& top)
{
    assert(top != nullptr);
    assert(top->left_ != nullptr);

    Node* d  = top;
    Node* b  = d->left_;        // b is d's left child
    d->left_ = b->right_;       // C becomes left child of d
    b->right_ = d;              // d becomes right child of b
    top = b;                    // top is now b

    d->size_ -= sizeNode(b->left_)  + 1;
    b->size_ += sizeNode(d->right_) + 1;
}

template <typename T>
void TreeSet<T>::insertAtLocation(Node*& here, const T& value)
{
    int randVal = rand();
    size_t sizeCurrentNode;
    if (here != nullptr) {
        sizeCurrentNode = here->nodeSize_;
    }
    //if location is null, we can just add it
    if (here == nullptr) {
        here = new Node(value);
    }        
    //find the correct path down the tree and roll the dice to see
    //if we insert at current root instead
    else if (value < here->value_) {
        ++here->nodeSize_;
        if (randVal % (sizeCurrentNode + 1) == 0) {
            insertAtRoot(here->left_, value);
        }
        else {
            insertAtLocation(here->left_, value);
        }
    }
    else {
        ++here->nodeSize_;
        if (randVal % (sizeCurrentNode + 1) == 0) {
            insertAtRoot(here->right_, value);
        }
        else {
            insertAtLocation(here->right_, value);
        }
    }
}

template <typename T>
bool TreeSet<T>::existsAtLocation(Node* here, const T& value) const
{
    //follow path down the tree to correct location to
    //see if value exists
    if (here == nullptr) {
        return false;
    }
    else if (value < here->value_) {
        return existsAtLocation(here->left_, value); 
    }   
    else if (here->value_ < value) {
        return existsAtLocation(here->right_, value);
    } 
    return true;
}

template <typename T>
int TreeSet<T>::maxHeight(Node* here, int tempHeight) const
{
    
    if (here == NULL)
        return tempHeight;
    else {
        ++tempHeight;
        int leftHeight = maxHeight(here->left_, tempHeight);
        int rightHeight = maxHeight(here->right_, tempHeight);
        if (leftHeight > rightHeight) {
            return leftHeight;
        }
        return rightHeight;
        
    }
    

}

template <typename T>
std::ostream& TreeSet<T>::printNode(Node* here, std::ostream& out) const
{   
    //print out the tree recursively starting from the leftmost children
    if (here == nullptr) {
        out << "-";
        return out;
    }
    out << "(";
    printNode(here->left_, out);
    out << ", " << here->value_ << ", ";
    printNode(here->right_, out);
    out << ")";
    
    return out;
}


//helper function for destructor.
template <typename T>
void TreeSet<T>::deleteNode(Node* here)
{
    //recursively go through tree and delete each node
    if (here == nullptr)
        return;

    deleteNode(here->left_);
    deleteNode(here->right_);
    delete here;
}
