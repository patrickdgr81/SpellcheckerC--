/**
 * \file treeset-test.cpp
 * \brief Tests for a treeset.
 *
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#include "treeset.hpp"

#define USE_TREESET 1

 #include "generic-set-tests.cpp"
#include <stdlib.h>
#include <ostream> // For std::ostream
#include <cstddef> // For size_t
#include <gtest/gtest.h>

using namespace std;
/*****************************************************
 * Functionality Tests
 *
 *      Functionality tests for TreeSet
 * ***************************************************/


//---------------
//  Size tests
//---------------

TEST(TreeSet, sizezero)
{
    TreeSet<int> nums;

    EXPECT_EQ(nums.size(), 0);
}

TEST(TreeSet, sizesingle)
{
    TreeSet<int> nums;
    nums.insert(25);

    EXPECT_EQ(nums.size(), 1);
}

TEST(TreeSet, sizedouble)
{
    TreeSet<int> nums;
    nums.insert(25);
    nums.insert(42);

    EXPECT_EQ(nums.size(), 2);
}

TEST(TreeSet, sizeMultiple)
{
    TreeSet<int> nums;
    for(int index = 0; index < 50; ++index) {
        nums.insert(index);
    }

    EXPECT_EQ(nums.size(), 50);
}

//---------------
//  Exists tests
//---------------

TEST(TreeSet, existszero)
{
    TreeSet<int> nums;

    EXPECT_EQ(nums.exists(25), false);
}

TEST(TreeSet, existssingle)
{
    TreeSet<int> nums;
    nums.insert(25);

    EXPECT_EQ(nums.exists(25), true);
}

TEST(TreeSet, existsdouble)
{
    TreeSet<int> nums;
    nums.insert(25);
    nums.insert(42);

    EXPECT_EQ(nums.exists(42), true);
}

TEST(TreeSet, existsMultiple)
{
    TreeSet<int> nums;
    for(int index = 0; index < 50; ++index) {
        nums.insert(index);
    }

    EXPECT_EQ(nums.exists(41), true);
}

//---------------
//  Insert tests (insert also tested elsewhere)
//---------------

TEST(TreeSet, insertMultiple)
{
    TreeSet<int> nums;
    for(int index = 1; index < 7; ++index) {
        nums.insert(index);
    }
    EXPECT_EQ(nums.exists(51), false);
    EXPECT_EQ(nums.exists(0), false);
    EXPECT_EQ(nums.exists(3), true);
    EXPECT_EQ(nums.exists(4), true);
    EXPECT_EQ(nums.exists(6), true);
}

//---------------
//  Print tests
//---------------

TEST(TreeSet, heightzero)
{
    TreeSet<int> nums;
    nums.print(cout);
    EXPECT_EQ(nums.height(), 0);
}

TEST(TreeSet, heightsingle)
{
    TreeSet<int> nums;
    nums.insert(25);
    nums.print(cout);
    EXPECT_EQ(nums.height(), 1);
}

TEST(TreeSet, heightdouble)
{
    TreeSet<int> nums;
    nums.insert(25);
    nums.insert(42);
    nums.print(cout);
    EXPECT_EQ(nums.height(), 2);
}

TEST(TreeSet, printTest)
{
    TreeSet<int> nums;
    srand(time(NULL));
    for(int index = 0; index < 100; ++index) {
        nums.insert(index);
    }
    nums.print(cout);
    EXPECT_EQ(nums.exists(41), true);
}

//---------------
//  Show statistics Test
//---------------

TEST(ShowStats, empty)
{
    TreeSet<int> nums;
    nums.showStatistics(cout);
    EXPECT_EQ(nums.height(), 0);
}

TEST(ShowStats, nonEmpty)
{
    TreeSet<int> nums;
    nums.insert(25);
    nums.insert(42);
    nums.showStatistics(cout);
    EXPECT_EQ(nums.height(), 2);
}
