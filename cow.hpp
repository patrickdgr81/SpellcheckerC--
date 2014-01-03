/**
 * \file cow.hpp
 * \author CS 70 Provided Code -- don't add to this file, make a new one.
 *
 * \brief Declares some minimal test classes for testing purposes, specifically
 *        HashableCow and OrderableCow.  Both are subclasses of a base class
 *        BaseCow, used for implementation inheritance, not substituability.
 */

#include <iosfwd>  // for std::ostream (just declarations)
#include <cstddef> // For size_t

/**
 * \class BaseCow
 * \brief
 *   Test class which implements basic cow functinality.
 * \remarks
 *   As this class just a minimal test class.
 */
class BaseCow {
public:
    /// Non-default constructor.
    // (Classes used with hash tables aren't required to have a default
    //  constructor.)
    explicit BaseCow(size_t numHats);

protected:
    size_t numHats_;   ///< How many hats does our Cow have?

    // Give external functions friend access
    friend std::ostream& operator<<(std::ostream& out, const BaseCow& printMe);
};


// As an extra, we define an output operator for the Cow type.
//
// NOTE: Cow isn't *required* to have an output operator, but it is reasonable
// for the hash table to have a (non-required) debugging function that prints
// out the hash table.  To *use* such a function Cows need to have printing
// defined.

/// Output a BaseCow in visual form
std::ostream& operator<<(std::ostream& out, const BaseCow& printMe);



/**
 * \class HashableCow
 * \brief
 *   Test class which implements hashable cow functinality.
 * \remarks
 *   As this class just a minimal test class.
 */
class HashableCow : public BaseCow {
public:
    using BaseCow::BaseCow;     // inherit constructors from BaseCow
    friend bool operator==(const HashableCow& lhs, const HashableCow& rhs);
};

// Classes used with hash tables must also have an equality operator.
// Here, I've defined it as a non-member function.

/// Equality for HashableCows
bool operator==(const HashableCow& lhs, const HashableCow& rhs);


/// Hash function for HashableCows
size_t myhash(const HashableCow&);


/**
 * \class OrderableCow
 * \brief
 *   Test class which implements hashable cow functinality.
 * \remarks
 *   As this class just a minimal test class.
 */
class OrderableCow : public BaseCow {
    using BaseCow::BaseCow;     // inherit constructors from BaseCow
public:
    friend bool operator<(const OrderableCow& lhs, const OrderableCow& rhs);
};

// Classes used with trees tables must a less-than operator.
// Here, I've defined it as a non-member function.

/// Less-than for OrderableCows
bool operator<(const OrderableCow& lhs, const OrderableCow& rhs);

