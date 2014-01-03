/**
 * \file stdhashset-test.cpp
 * \brief Tests for a stdhashset.
 *
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#include "stringhash.hpp"
#include "stdhashset.hpp"

#define USE_STDHASHSET 1

#include <ostream> // For std::ostream
#include <cstddef> // For size_t
#include <gtest/gtest.h>

/*****************************************************
 * Functionality Tests
 *
 *      Functionality tests for StdHashSet
 * ***************************************************/

//---------------
//  Size tests
//---------------

TEST(StdHashSet, sizeZero)
{
    StdHashSet<string> strHash {};
    EXPECT_EQ(strHash.size(),0);
}

TEST(StdHashSet, sizeSingle)
{
    StdHashSet<string> strHash {};
    strHash.insert("mcdonalds");
    EXPECT_EQ(strHash.size(),1);
}

TEST(StdHashSet, sizeDouble)
{
    StdHashSet<string> strHash {};
    strHash.insert("mcdonalds");
    strHash.insert("tuna");
    EXPECT_EQ(strHash.size(),2);
}

TEST(StdHashSet, sizeMultiple)
{
    StdHashSet<string> strHash {};
    string s;
    for(size_t index = 0; index < 40; ++index)
    {
        s += "b";
        strHash.insert(s);
    }
    EXPECT_EQ(strHash.size(),40);
}

//---------------
//  Exists tests
//---------------

TEST(StdHashSet, existsZero)
{
    StdHashSet<string> strHash {};
    EXPECT_EQ(strHash.exists("anything"), false);
}

TEST(StdHashSet, existsSingleT)
{
    StdHashSet<string> strHash {};
    strHash.insert("anything");
    EXPECT_EQ(strHash.exists("anything"), true);
}

TEST(StdHashSet, existsSingleF)
{
    StdHashSet<string> strHash {};
    strHash.insert("mcdonalds");
    EXPECT_EQ(strHash.exists("anything"), false);
}

TEST(StdHashSet, existsDouble)
{
    StdHashSet<string> strHash {};
    strHash.insert("mcdonalds");
    strHash.insert("tuna");
    EXPECT_EQ(strHash.exists("anything"), false);
    EXPECT_EQ(strHash.exists("tuna"), true);
}

TEST(StdHashSet, existsTripleT)
{
    StdHashSet<string> strHash {};
    strHash.insert("mcdonalds");
    strHash.insert("tuna");
    strHash.insert("bacon");
    EXPECT_EQ(strHash.exists("bacon"),true);
}

TEST(StdHashSet, existsTripleF)
{
    StdHashSet<string> strHash {};
    strHash.insert("mcdonalds");
    strHash.insert("tuna");
    strHash.insert("bacon");
    EXPECT_EQ(strHash.exists("Hello"),false);
}

TEST(StdHashSet, existsMultipleT)
{
    StdHashSet<string> strHash {};
    string s = "a";
    string t = "x";
    for(size_t index = 0; index < 50; ++index)
    {
        s += "b";
        t += "y";
        strHash.insert(s);
    }
    EXPECT_EQ(strHash.exists("abbbbbb"), true);
}

TEST(StdHashSet, existsMultipleF)
{
    StdHashSet<string> strHash {};
    string s = "a";
    for(size_t index = 0; index < 20; ++index)
    {
        s += "b";
        strHash.insert(s);
    }
    EXPECT_EQ(strHash.exists("abbbbbba"),false);
}

//---------------
//  Insert tests
//---------------

TEST(StdHashSet, insertMultipleT)
{
    StdHashSet<string> strHash {};
    string s = "a";
    for(size_t index = 0; index < 5; ++index)
    {
        s += "b";
        strHash.insert(s);
    }
    for(size_t index = 0; index < 5; ++index)
    {
        s += "c";
        strHash.insert(s);
    }
    for(size_t index = 0; index < 5; ++index)
    {
        s += "z";
        strHash.insert(s);
    }
    EXPECT_EQ(strHash.exists("abbbbbccccczzzzz"),true);
}

TEST(StdHashSet, insertMultipleF)
{
    StdHashSet<string> strHash {};
    string s = "a";
    for(size_t index = 0; index < 5; ++index)
    {
        s += "b";
        strHash.insert(s);
    }
    for(size_t index = 0; index < 5; ++index)
    {
        s += "c";
        strHash.insert(s);
    }
    for(size_t index = 0; index < 5; ++index)
    {
        s += "z";
        strHash.insert(s);
    }
    EXPECT_EQ(strHash.exists("abbbbbcaccczzzzz"),false);
}




