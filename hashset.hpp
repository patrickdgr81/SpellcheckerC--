/**
 * \file hashset.hpp
 * \brief Declares the hashset template.
 *
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#ifndef HASHSET_HPP
#define HASHSET_HPP 1

#include "abstractset.hpp"
#include <cstddef>
#include <list>
#include <iostream>


/// The number of buckets we decide to start with.
static const size_t STARTING_BUCKETS = 17;

/// The max load factor for the hash table.
static const double MAX_LOAD = 0.9;

/**
 * \class HashSet
 *
 * \brief
 *  A set class template using hash tables.
 */

template <typename T>
class HashSet: public AbstractSet<T> {
public:


    /**
     * \brief Default constructor
     * \details constructor initializes the hashset and sets the number
     *          of buckets to starting size
     */
    HashSet();

    /**
     * \brief Default destructor       
     */

    ~HashSet();
    
    /**
     * \brief how many elements are in hashtable
     */
    size_t size() const override;
    
    /**
     * \brief insert T into hashtable
     * \details inserts type T into hashtable, if bucket has something in
     *          it, still add to that bucket using separate chaining
     */

    void insert(const T&) override;

    /**
     * \brief check if T is in hashtable         
     */

    bool exists(const T&) const override;

    /**
     * \brief Some debugging outputs        
     */

    std::ostream& showStatistics(std::ostream& out) const;

    /**
     * \brief returns number of buckets in hashtable  
     */

    size_t buckets() const;

    /**
     * \brief returns number of times the hashtable has resized
     */

    size_t reallocations() const;

    /**
     * \brief returns number of collisions
     */

    size_t collisions() const;

    /**
     * \brief returns number of times the hashtable has resized
     */

    size_t maximal() const;

    typedef typename std::list<T>::iterator bucket_it;

private:
    /// Private copy constructor
    HashSet(const HashSet& orig);
    /// Private assignment operator
    HashSet& operator=(const HashSet& rhs);

    /// Copy the HashSet into a bigger HashSet
    void resizeAndCopy();

    std::list<T>* buckets_;
    size_t numBuckets_;///number of buckets
    size_t size_;///number of items stored in hash table
    size_t reallocations_;///number of times hash table has resized
    size_t collisions_;///number of times inserted in nonempty bucket
    size_t maximal_;///largest number of elements in single bucket
};


#include "hashset-private.hpp"
#endif // PREDICTOR_HPP
