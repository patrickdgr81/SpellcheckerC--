/**
 * \file stringhash.hpp
 * \brief Declare of functions in myspell
 *
 * \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
 */

#include "stringhash.hpp"
#include "treeset.hpp"
#include "abstractset.hpp"
#include "hashset.hpp"
#include "stdtreeset.hpp"
#include "stdhashset.hpp"

/**
 * \brief Used to spellcheck user input against dictionary
 *
 * \details This is used by the main method found in myspell.cpp
 *          to check user input against an imported dictionary, both
 *          of which are HashSet data members. 
 */
class mySpell {

    public:

    mySpell();

    /// Abstract Set where dictionary is read into
    AbstractSet<string>* Dictionary;
    /// Abstract Set where user input is read into
    AbstractSet<string>* inputedWords;

    /// a char array of the alphabet
    static constexpr char alphabet[] =
     {'a' , 'b', 'c', 'd', 'e', 'f',
     'g' , 'h' , 'i', 'j', 'k', 'l',
     'm', 'n', 'o', 'p', 'q', 'r', 's',
     't', 'u', 'v', 'w', 'x', 'y', 'z' };


    /**
     * \brief formatOutput function for myspell
     *
     * \details Checks possible correct spellings and outputs them correctly.
     */
    void formatOutput(string& missSpelledWord);

};
