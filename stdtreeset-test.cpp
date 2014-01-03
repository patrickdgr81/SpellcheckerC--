/**
 * \file stdtreeset-test.cpp
 * \brief Tests for a stdtreeset.
 *
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#include "stdtreeset.hpp"

#define USE_HASHSET 1

#include <ostream> // For std::ostream
#include <cstddef> // For size_t
#include <gtest/gtest.h>
#include <iostream>

/*****************************************************
 * Functionality Tests
 *
 *      Functionality tests for StdTreeSet
 * ***************************************************/

//---------------
//  Size tests
//---------------

TEST(StdTreeSet, sizezero)
{
    StdTreeSet<int> nums;

    EXPECT_EQ(nums.size(), 0);
}

TEST(StdTreeSet, sizesingle)
{
    StdTreeSet<int> nums;
    nums.insert(25);

    EXPECT_EQ(nums.size(), 1);
}

TEST(StdTreeSet, sizedouble)
{
    StdTreeSet<int> nums;
    nums.insert(25);
    nums.insert(42);

    EXPECT_EQ(nums.size(), 2);
}

TEST(StdTreeSet, sizeMultiple)
{
    StdTreeSet<int> nums;
    for(int index = 0; index < 50; ++index) {
        nums.insert(index);
    }

    EXPECT_EQ(nums.size(), 50);
}

//---------------
//  Exists tests
//---------------

TEST(StdTreeSet, existszero)
{
    StdTreeSet<int> nums;

    EXPECT_EQ(nums.exists(25), false);
}

TEST(StdTreeSet, existssingle)
{
    StdTreeSet<int> nums;
    nums.insert(25);

    EXPECT_EQ(nums.exists(25), true);
}

TEST(StdTreeSet, existsdouble)
{
    StdTreeSet<int> nums;
    nums.insert(25);
    nums.insert(42);

    EXPECT_EQ(nums.exists(42), true);
}

TEST(StdTreeSet, existsMultiple)
{
    StdTreeSet<int> nums;
    for(int index = 0; index < 50; ++index) {
        nums.insert(index);
    }

    EXPECT_EQ(nums.exists(41), true);
}

//---------------
//  Insert tests
//---------------

TEST(StdTreeSet, insertMultiple)
{
    StdTreeSet<int> nums;
    for(int index = 1; index < 7; ++index) {
        nums.insert(index);
    }
    EXPECT_EQ(nums.exists(51), false);
    EXPECT_EQ(nums.exists(0), false);
    EXPECT_EQ(nums.exists(3), true);
    EXPECT_EQ(nums.exists(4), true);
    EXPECT_EQ(nums.exists(6), true);
}
