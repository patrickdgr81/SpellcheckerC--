/**
 * \file hashset-private.hpp
 * \brief Implementation file for the HashSet<T> template.
 *
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */
#include <cstddef>
#include <climits>
#include <cassert>

using namespace std;

/**
 * \brief Hashset Template
 */

//---------------------------------------------------------------
//                      Requred Functions
//---------------------------------------------------------------

//Deault constructor.
template <typename T>
HashSet<T>::HashSet()
    : buckets_(new list<T>[STARTING_BUCKETS]), numBuckets_(STARTING_BUCKETS),
      size_(0), reallocations_(0), collisions_(0), maximal_(0)
{
    // Nothing else to do
}

//Destructor that leaves the object in a sane (empty) state.
template <typename T>
HashSet<T>::~HashSet<T>()
{
    delete [] buckets_;

}

//Size of the Hashset.
template <typename T>
size_t HashSet<T>::size() const
{
    return size_;
}

//Insert an object into the Hashset.
template <typename T>
void HashSet<T>::insert(const T& insertee)
{
    //Get the proper bucket
    size_t bucket = myhash(insertee) % numBuckets_;

    if (!buckets_[bucket].empty()) {
        ++collisions_;
    }

    buckets_[bucket].push_back(insertee);
    ++size_;

    if (buckets_[bucket].size() > maximal_) {
        ++maximal_;
    }

    //Larger than expected load factor
    if ((size_ + 0.0)/ numBuckets_ > MAX_LOAD) {
        resizeAndCopy();
        ++reallocations_;
    }
}

//Check if the object exists in the Hashset.
template <typename T>
bool HashSet<T>::exists(const T& obj) const
{
    size_t bucket = myhash(obj) % numBuckets_;
    for (bucket_it i = buckets_[bucket].begin(); 
         i !=buckets_[bucket].end(); ++i) {
        if (*i == obj) {
            return true;
        }
    }
    return false;
}

template <typename T>
std::ostream& HashSet<T>::showStatistics(std::ostream& out) const
{
    out << reallocations() 
        << " expansions, load factor " 
        << (size()+0.0) / buckets()
        << ", " 
        << collisions() 
        << " collisions, longest run " 
        << maximal();
    return out;
}

//Number of the buckets in the Hashset.
template <typename T>
size_t HashSet<T>::buckets() const
{
    return numBuckets_;
}

//Number of times the hash table has resized itself.
template <typename T>
size_t HashSet<T>::reallocations() const
{
    return reallocations_;
}

//Number of times of collisions.
template <typename T>
size_t HashSet<T>::collisions() const
{
    return collisions_;
}

//Length of the longest chain.
template <typename T>
size_t HashSet<T>::maximal() const
{
    return maximal_;
}


//---------------------------------------------------------------
//                      Helper Functions
//---------------------------------------------------------------

//Copy the HashSet into a bigger HashSet.
template <typename T>
void HashSet<T>::resizeAndCopy()
{
    list<T>* oldBuckets = buckets_;
    list<T>* newBuckets = new list<T>[numBuckets_ * 2];

    buckets_ = newBuckets;

    //Reset quantities.
    collisions_ = 0;
    maximal_ = 0;
    size_ = 0;
    numBuckets_ = numBuckets_ * 2;

    //Insert elemonts back into the new list.
    for (size_t i = 0; i < numBuckets_/2; ++i) {
        while (!oldBuckets[i].empty()) {
            insert(oldBuckets[i].back());
            oldBuckets[i].pop_back();
        }
    }
    delete[] oldBuckets;
}
