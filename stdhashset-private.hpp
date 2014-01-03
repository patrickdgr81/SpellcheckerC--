/**
 * \file abstractset.hpp
 * \brief Provides AbstractSet<T>, a(n absract) set class template
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

using namespace std;


template <typename T>
size_t StdHashSet<T>::size() const
{
    return set_.size();
}

template <typename T>
void StdHashSet<T>::insert(const T& insertee)
{
    set_.insert(insertee);
}

template <typename T>
bool StdHashSet<T>::exists(const T& obj) const
{
    if (set_.count(obj) == 1) {
        return true;
    }
    return false;
}

template <typename T>
std::ostream& StdHashSet<T>::showStatistics(std::ostream& out) const
{
    return out << "No statistics available." << std::endl;
}
