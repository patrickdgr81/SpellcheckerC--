/**
 * \file stdhashset-cow-test.cpp
 * \author CS 70 Provided Code -- don't add to this file, make a new one.
 *
 * \brief Tests a stdhashset to ensure that it is properly generic and doesn't
 *        contain any hidden dependencies on being a hashtable of strings.
 *        Does not extensively test StdHashSet functionality.
 */

// Don't put any includes before this one!  (Otherwise it won't be as good a
// test of whether the stdhashset is self sufficient.)  If you make another
// test file, it'll be okay to add other includes, like stringhash.hpp, but
// don't do that here.
#include "stdhashset.hpp"
#include "cow.hpp"

// Explicitly instantiate the entire templated class (normally C++ is lazy
// and only instantiates the things it needs as it needs them, here we make
// it do everything.)

template class StdHashSet<HashableCow>;

// The simple tests are in cow-tests.hpp; to allow the code to be shared
// it expects us to define cow_t and cowset_t to be the classes we want to
// test.

typedef HashableCow           cow_t;
typedef StdHashSet<HashableCow>  cowset_t ;

#include "cow-tests.hpp"

// We don't provide a definition of main because the code is linked against
// -lgtest_main which provides a simple main function that runs all the
// tests.
