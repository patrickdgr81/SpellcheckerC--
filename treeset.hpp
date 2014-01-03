/**
 * \file treeset.hpp
 * \brief Provides AbstractSet<T>, a(n absract) set class template
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#ifndef TREESET_HPP
#define TREESET_HPP 1

#include "abstractset.hpp"
#include <iosfwd>
#include <set>

/**
 * \class TreeSet
 *
 * \brief A Randomized Binary Search Tree.
 *
 * \details
 *  This class implements the AbstractSet<T> interface using a
 *  randomized binary search tree.  It assumes that the type T
 *  supports operator<.  We do NOT assume that it supports operator>
 *  or operator== (we can live with just operator<, and it would be
 *  unnecessary to require the other functions).
 */


 template <typename T>
 class TreeSet : public AbstractSet<T> {
 public:
    /**
     * \brief Default constructor
     * \details constructor initializes the hashset and sets the number
     *          of buckets to starting size
     */
    TreeSet();

    /**
     * \brief Default destructor       
     */

    ~TreeSet();

    /**
     * \brief see if findee exists      
     */

    bool exists(const T& findee) const override;

    /**
     * \brief add insertee to tree     
     */

    void insert(const T& insertee) override;

    /**
     * \brief show relevant statistics of tree structure     
     */
    std::ostream& showStatistics(std::ostream& out) const;

    /**
     * \brief check the size of the tree   
     */
    size_t size() const override;

    /**
     * \brief Recursively print tree       
     */
    std::ostream& print(std::ostream& out) const;

    /**
     * \brief returns height of the tree      
     */
    int height() const;

/**
 * \struct Node
 * \brief A Node contains a value_ and pointers to the left and
 *  right branches.
 *
 * \details
 *   Our node also contains some other helper functions for 
 *   rotating and height calculating. Besides, the exists and
 *   inserts functions are also implimented here.
 */

 private:
    struct Node {
            T     value_;
            Node* right_;
            Node* left_;
            size_t nodeSize_;
            Node();
            Node(const T& value) ;
    };

    Node* root_;
    /**
     * \brief puts insertee at root and still ensures tree is binary     
     */
    void insertAtRoot(Node*& here, const T& insertee);

    /**
     * \brief rotates the entire tree right from the given node   
     */
    void rightRotate(Node*& top);

    /**
     * \brief rotates the entire tree left from the given node   
     */
    void leftRotate(Node*& top);

    /**
     * \brief find the longest branch of the tree 
     */
    int maxHeight(Node* here, int tempHeight) const;

    /**
     * \brief helper to find correct location to insert in binary tree    
     */

    void insertAtLocation(Node*& here, const T& value);

    /**
     * \brief helper to find check if value exists in tree  
     */
    bool existsAtLocation(Node* here, const T& value) const;

    /**
     * \brief helper to output debugging info about the tree
     */
    std::ostream& printNode(Node* here, std::ostream& out) const;

    /**
     * \brief helper to delete node for the detructor
     */
    void deleteNode(Node* here);

    size_t size_;///number of items stored in hash table
    size_t height_;///maximum height of the tree

};
#include "treeset-private.hpp"
#endif // PREDICTOR_HPP



