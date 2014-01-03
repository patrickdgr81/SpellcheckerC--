/**
 * \file std::stringhash.hpp
 * \author CS 70 Provided Code.
 *
 * \brief Hash function for std::strings
 */

#ifndef STRINGHASH_HPP_INCLUDED
#define STRINGHASH_HPP_INCLUDED 1

#include <cstddef>
#include <string>

 /**
 * \brief Hashes a string.
 *
 * \details
 *   This function takes in a string and then returns the correct hash
 *   value.  The hash function returns an integer that can span the
 *   full range of unsigned ints.
 *
 * \returns Hash value of the string.
 */
size_t myhash(const std::string& str);

/**
 * Describes a hash function for the stringhash-test code.
 */
struct HashFunctionInfo {
    std::string name_;
    size_t (*func_)(const std::string& str);
};

/**
 * Table for the stringhash-test code.
 */
extern std::initializer_list<HashFunctionInfo> hashInfo;


#endif //* STRINGHASH_HPP_INCLUDED
