/**
 * \file cow.cpp
 * \author CS 70 Provided Code -- don't add to this file, make a new one.
 *
 * \brief Defines some minimal test classes for testing purposes, specifically
 *        HashableCow and OrderableCow.  Both are subclasses of a base class
 *        BaseCow, used for implementation inheritance, not substituability.
 */

#include "cow.hpp"

#include <ostream> // For std::ostream

// As an extra, we define an output operator for the Cow type.
//
// NOTE: Cow isn't *required* to have an output operator, but it is reasonable
// for the hash table to have a (non-required) debugging function that prints
// out the hash table.  To *use* such a function Cows need to have printing
// defined.

/// Output a Cow in visual form
std::ostream& operator<<(std::ostream& out, const BaseCow& printMe)
{
    for (size_t i = 0; i < printMe.numHats_; ++i)
        out << "        _====_\n";

    out << "         (__)\n"    // Shamelessly taken from Debian's (& Ubuntu's)
        << "         (oo)\n"    //    apt-get moo
        << "   /------\\/ \n"   // (apt has "super cow" powers)
        << "  / |    ||  \n"
        << " *  /\\---/\\  \n"
        << "    ~~   ~~  \n";
    return out;
}

BaseCow::BaseCow(size_t numHats)
    : numHats_(numHats)
{
    // Nothing (else) to do.
}


/// Hash function for HashableCows
size_t myhash(const HashableCow&)
{
    return 42;  // Really bad hash function. ;-)
}


/// Equality for HashableCow
bool operator==(const HashableCow& lhs, const HashableCow& rhs)
{
    return lhs.numHats_ == rhs.numHats_;
}


/// Less-than for OrderableCows
bool operator<(const OrderableCow& lhs, const OrderableCow& rhs)
{
    return lhs.numHats_ < rhs.numHats_;
}


