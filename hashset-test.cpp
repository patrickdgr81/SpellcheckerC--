/**
 * \file hashset-test.cpp
 * \brief Tests a hashset to ensure that it is properly generic and doesn't
 *        contain any hidden dependencies on being a hashtable of strings.
 *        Does not extensively test HashSet functionality.
 *
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */
#include "stringhash.hpp"
#include "hashset.hpp"

#define USE_HASHSET 1
#include "generic-set-tests.cpp"

#include <ostream> // For std::ostream
#include <cstddef> // For size_t
#include <gtest/gtest.h>
 
/*****************************************************
 * Functionality Tests
 *
 *      Functionality tests for HashSet
 * ***************************************************/

//Test for constructor and its default number of buckets.
 TEST(constructor, defaultNumberBuckts)
{
    HashSet<string> strHash {};
    EXPECT_EQ(strHash.buckets(),17);
}

//Test for constructor and its default size.
TEST(constructor, defaultSize)
{
    HashSet<string> strHash {};
    EXPECT_EQ(strHash.size(),0);
}

//Test for constructor and function maximal().
TEST(constructor, defaultMaximum)
{
    HashSet<string> strHash {};
    EXPECT_EQ(strHash.maximal(),0);
}

//Test for default onstructor and function maximal().
TEST(constructor, typeInt)
{
    HashSet<string> intHash {};
    EXPECT_EQ(intHash.maximal(),0);
}

//Test for function insert() and size().
TEST(insert, sizeUpdates)
{
    HashSet<string> strHash {};
    strHash.insert("mcdonalds");
    strHash.insert("tuna");
    strHash.insert("bacon");
    EXPECT_EQ(strHash.size(),3);
}

//Test for function insert() and size() with multiple insertion.
TEST(insert, sizeUpdatesLong)
{
    HashSet<string> testStr {};
    string s;
    for(size_t index = 0; index < 40; ++index)
    {
        s += "b";
        testStr.insert(s);
    }
    EXPECT_EQ(testStr.size(),40);
}

//Test for function insert() and exists(), which checks for positive answer.
TEST(insertExists, basicTest)
{
    HashSet<string> testStr {};
    testStr.insert("mcdonalds");
    testStr.insert("tuna");
    testStr.insert("bacon");
    EXPECT_EQ(testStr.exists("bacon"),true);
}

//Test for function insert() and exists(), which checks for negative answer.
TEST(insertExists, false)
{
    HashSet<string> testStr {};
    testStr.insert("mcdonalds");
    testStr.insert("tuna");
    testStr.insert("bacon");
    EXPECT_EQ(testStr.exists("Hello"),false);
}

//Test for function insert() and exists() with multiple insertion, and positive
//answer.
TEST(insertExists, long)
{
    HashSet<string> testStr {};
    string s = "a";
    string t = "x";
    for(size_t index = 0; index < 50; ++index)
    {
        s += "b";
        t += "y";
        testStr.insert(s);
    }
    EXPECT_EQ(testStr.exists("abbbbbb"), true);
}
//sanity check for empty hashset
TEST(exists, empty)
{
    HashSet<string> testStr {};
    EXPECT_EQ(testStr.exists("anything"), false);
}

//Test for function insert() and exists() with multiple insertion, and negative
//answer.
TEST(insertExists, longFalse)
{
    HashSet<string> testStr {};
    string s = "a";
    for(size_t index = 0; index < 20; ++index)
    {
        s += "b";
        testStr.insert(s);
    }
    EXPECT_EQ(testStr.exists("abbbbbba"),false);
}

//Test for function reallocations() and insert().
TEST(reallocations, long)
{
    HashSet<string> testStr {};
    string s = "a";
    for(size_t index = 0; index < 14; ++index)
    {
        s += "b";
        testStr.insert(s);
    }
    EXPECT_EQ(testStr.reallocations(),0);
}
