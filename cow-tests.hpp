/**
 * \file cow-tests.hpp
 * \author CS 70 Provided Code -- don't add to this file, make a new one.
 *
 * \brief Tests a set class to ensure that it is properly generic and doesn't
 *        contain any hidden dependencies on being a hashtable of strings.
 *        Does not extensively test HashSet functionality.
 */

#include <gtest/gtest.h>

/// Test insert and exists for cows, this code assume you have defined
/// typedefs for cow_t and cowset_t to be the types you want to test.
TEST(cowTestSuite, basicTests)
{
    cow_t    mabel{3};
    cowset_t cowSet;

    EXPECT_FALSE(cowSet.exists(mabel));
    cowSet.insert(mabel);
    EXPECT_TRUE(cowSet.exists(mabel));

}
