/**
 * \file stringhash.hpp
 * \brief Hash function for strings
 *
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#include "stringhash.hpp"
#include <iterator>

using std::string;


namespace {

size_t multnLengHash(const string& s)
{
    size_t hash = 69; // A random number
    for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
        hash = hash * 101 + *i;
    }
    return hash;
}

size_t multimodHash(const string& s)
{
    size_t hash = 0;
    for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
        hash += *i;
    }
    return (hash % 37) + (hash % 29) + (hash % 7);
}

size_t multnLengModHash(const string& s)
{
    size_t hash = 69;
    for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
        hash = hash * 101 + *i;
    }
    return (hash % 83) + (hash % 59) + (hash % 11);
}

}


size_t myhash(const string& str)
{
    return multnLengHash(str);
}


// You don't have to fully understand this code, but it is used to provide a
// table used by stringhash-test.cpp, all you need to do is list the name
// of your hash function (for printing) and the actual function name from
// above.
std::initializer_list<HashFunctionInfo> hashInfo = {
    {"multiplication and length hashing",     multnLengHash},
    {"taking mod of sum of letters hashing",     multimodHash},
    {"Combination of the above two hashing",     multnLengModHash}
};

