/**
 * \file abstractset.hpp
 * \brief Provides AbstractSet<T>, a(n absract) set class template
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#include <iostream>


template <typename T>
size_t StdTreeSet<T>::size() const
{
    return set_.size();
}

template <typename T>
void StdTreeSet<T>::insert(const T& insertee)
{
    set_.insert(insertee);
}

template <typename T>
bool StdTreeSet<T>::exists(const T& findee) const
{
    //returns true if findee is in the treeset
    return set_.find(findee) != set_.end();
}

template <typename T>
std::ostream& StdTreeSet<T>::showStatistics(std::ostream& out) const
{
    return out << "No statistics available." << std::endl;
}
