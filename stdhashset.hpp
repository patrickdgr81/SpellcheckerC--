/**
 * \file stdhashset.hpp
 * \brief Provides AbstractSet<T>, a(n absract) set class template
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#ifndef STDHASHSET_HPP
#define STDHASHSET_HPP 1

#include <cstddef>
#include <unordered_set>
#include <iostream>
#include "abstractset.hpp"


/**
 * \class StdHashSet
 *
 * \brief A standard implementation of a Hash Table.
 *
 * \details
 *   This class assumes that a hashing function \n
 *   size_t myhash(const T& item) \n
 *   exists for the template argument type T.
 *   Exists as comparison point for HashSet.
 *   The showStatistics method prints
 *   No statistics available.
 */


template <typename T>
class StdHashSet : public AbstractSet<T> {
public:
    /// Put value into stdhashset
    void insert(const T& insertee);

    /// Check for membership  
    bool exists(const T& findee) const;

    /// Statistics output
    std::ostream& showStatistics(std::ostream& out) const;

    /// Size of set
    size_t size() const;

    std::ostream& print(std::ostream& out) const;

private:
    /**
     * \class MyHash
     * \brief Allows use of myhash as a hash function.
     * \details MyHash objects are functors. (from instruction)
     */
    class MyHash {
    public:
        size_t operator()(const T& value) const
        {
            return myhash(value);
        }
    };

    std::unordered_set<T,MyHash> set_;
};
#include "stdhashset-private.hpp"
#endif // STDHASHSET_HPP
