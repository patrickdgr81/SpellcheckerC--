/**
 * \file abstractset.hpp
 * \brief Provides AbstractSet<T>, a(n absract) set class template
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#ifndef ABSTRACTSET_HPP_INCLUDED
#define ABSTRACTSET_HPP_INCLUDED 1

#include <iosfwd>

/**
 * \class AbstractSet
 * \brief A Set that allows for multiple implementations.
 *
 * \details
 *   AbstractSet is used when we might want a HashSet or a TreeSet
 *   (for examples), but don't know at compile time which we'll end up
 *   using.
 */

template <typename T>
class AbstractSet {
public:
    
    /// Destructor
    virtual ~AbstractSet() {
        // nothing to do
    }

    ///< Add to set
    virtual void insert(const T& insertee) = 0;
    
    ///< Check for membership     
    virtual bool exists(const T& findee) const = 0;   

    /// Statistics output
    virtual std::ostream& showStatistics(std::ostream& out) const = 0;

    ///< Size of set
    virtual size_t size() const = 0;

};


#endif // ABSTRACTSET_HPP_INCLUDED
