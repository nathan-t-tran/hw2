#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    string completedWord = "";
    set<string> wordSet;
    int size = rawWords.size();

    //cout << "beginning of parser" << endl;

    for (int i = 0; i < size; i++) //loops throw rawWords
    {
        if (rawWords[i] >= 'a' && rawWords[i] <= 'z') //checks if the character is a normal leter
        {
            //cout << "current char: " << rawWords[i] << endl;

            completedWord.push_back(rawWords[i]); //adds it to the completed word
            //cout << "completedWord: " << completedWord << endl;
        }
        else // if it is a punctuation or space
        {
            //cout << "completedWord: " << completedWord << endl;
            if (completedWord.size() >= 2)
            {
                //cout << "Inserted completedWord: " << completedWord << endl;
                wordSet.insert(completedWord); //inserts word into word set
            }
            completedWord = ""; //resets completed word
        }
    }
    
    if (completedWord.size() >= 2)
    {
        wordSet.insert(completedWord); //when it is just the end of the string
    }

    return wordSet;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
