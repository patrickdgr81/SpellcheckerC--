/**
* \file myspell.cpp
* \brief implementation of myspell
*
* \Author: Lu Wenhao, Wang Xiaotian (wlu-xwang)
*/

#include "myspell.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstddef>

using namespace std;

//Member variable definition.
constexpr char mySpell::alphabet[];

//Default Dictionary constructor.
mySpell::mySpell():
    Dictionary{}, inputedWords{}
{
    //nothing else to do
}

//Main function for the myspell.
int main(int arc, const char* argv[])
{
    mySpell language {};
    if (arc == 1) {
        cerr << "No Dictionary Found" << endl;
        exit (EXIT_FAILURE);
    }
    int index = 2; //arc is 1 if no flags
    bool debugging = false;
    char type = 'H';
    //process inputs
    while (index != arc + 1) {
        //check flags, which all begin with -
        if (argv[index-1][0] == '-') {
            if (argv[index-1][1] == 'd' && argv[index-1][2] == '\0') {
                debugging = true;
            } else if (argv[index-1][1] == 'h' && argv[index-1][2] == '\0') {
                type = 'h';
            } else if (argv[index-1][1] == 'T' && argv[index-1][2] == '\0') {
                type = 'T';
            } else if (argv[index-1][1] == 'H' && argv[index-1][2] == '\0') {
                type = 'H';
            } else if (argv[index-1][1] == 't' && argv[index-1][2] == '\0') {
                type = 't';
            }
            else {
                cerr << "Unrecognized Flag" << endl;
                exit (EXIT_FAILURE);
            }
        }
        //if it was not a flag, we assume the input was
        //the dictionary    
        else {
            if (type == 'h') {
                language.Dictionary = new HashSet<string>();
                language.inputedWords = new HashSet<string>();
            } 
            if (type == 't') {
                language.Dictionary = new TreeSet<string>();
                language.inputedWords = new TreeSet<string>();
            } 
            if (type == 'T') {
                language.Dictionary = new StdTreeSet<string>();
                language.inputedWords = new StdTreeSet<string>();
            } 
            if (type == 'H') {
                language.Dictionary = new StdHashSet<string>();
                language.inputedWords = new StdHashSet<string>();
            } 
            
            ifstream readFile(argv[index-1]);
            if (readFile.is_open()) {
                string line;
                while(readFile.good()) {
                    //read lines into dictionary
                    getline(readFile,line);
                    language.Dictionary->insert(line);
                }
                readFile.close();
            } else {
                cerr << "Problem loading dictionary" << endl;
                exit (EXIT_FAILURE);
            }
        }
        ++index;
    }

    //if we are debugging, cut the output below
    if (debugging == true) {
        language.Dictionary->showStatistics(cerr);
    }

    //current word being handled
    string strTemp;
    //current character being handled
    char nextCharacter;
    size_t lastChar;
    //get input from user and spellcheck every word 
    while (cin.get(nextCharacter)) {

        if (isspace(nextCharacter)) {
            //if the word is spelled incorrectly and not already 
            //spelled incorrectly, we check possible errors and output it
            if (!language.Dictionary->exists(strTemp) && 
                !language.inputedWords->exists(strTemp)) {
                //make sure the word is valid by removing symbols
                while(!isalpha(strTemp.at(0))) {
                    if (strTemp.length() == 1) {
                        break;
                    }
                    strTemp = strTemp.substr(1,strTemp.length());
                }
                size_t length = strTemp.length();
                if (isalpha(strTemp.at(0))) {
                    lastChar = 1;
                    //ignore all symbols at end of word
                    while(!isalpha(strTemp.at(length - lastChar))) {
                        ++lastChar;
                    }
                    strTemp = strTemp.substr(0,length - lastChar + 1);
                    if (!language.Dictionary->exists(strTemp) && 
                    !language.inputedWords->exists(strTemp)) {
                        language.formatOutput(strTemp);
                    }
                }       
            }
            //make sure we don't recheck the same word and clear tempString
            language.inputedWords->insert(strTemp);
            strTemp.clear();
        } else if (isalpha(nextCharacter)) {
            strTemp.push_back(tolower(nextCharacter));
        } else {
            strTemp.push_back(nextCharacter);
        }
    }
    return 0;
}

//Checks possible correct spellings and outputs them nicely.
 void mySpell::formatOutput(string& missSpelledWord)
 {
    string outputString = missSpelledWord + ": ";
    string tempWord;
    for(size_t index = 0; index != missSpelledWord.length(); ++index) {
        //reset tempWord to the inputed misspelled word
        tempWord = missSpelledWord;
        //checks by replacing each letter with every possible letter
        for(size_t eachLetter = 0; eachLetter < 25; ++eachLetter) {
            tempWord.at(index) = alphabet[eachLetter];
            if (Dictionary->exists(tempWord)) {
                outputString += tempWord + " ";
            }
        }
    }
    cout << outputString << endl;
 }
