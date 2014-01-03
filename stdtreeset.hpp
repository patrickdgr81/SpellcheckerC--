/**
 * \file stdtreeset.hpp
 * \brief Provides AbstractSet<T>, a(n absract) set class template
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#ifndef STDTREESET_HPP_INCLUDED
#define STDTREESET_HPP_INCLUDED 1

#include "abstractset.hpp"
#include <iosfwd>
#include <set>

/**
 * \class StdTreeSet
 *
 * \brief A standard implementation of a Binary Search Tree.
 *
 * \details
 *   Exists as a comparison point for other Trees such as TreeSet.
 *   This class assumes that T has an Operator<.
 *   The showStatistics method prints
 *   No statistics available.
 */


 template <typename T>
 class StdTreeSet : public AbstractSet<T> {

 public:
    /// Put value into stdtreeset
    void insert(const T& insertee);
    
    /// Check for membership     
    bool exists(const T& findee) const;   

    /// Statistics output
    std::ostream& showStatistics(std::ostream& out) const;

    /// Size of set
    size_t size() const;



private:
    std::set<T> set_; 
 };

#include "stdtreeset-private.hpp"
#endif // STDTREESET_HPP_INCLUDED
