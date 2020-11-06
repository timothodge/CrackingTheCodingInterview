#include <iostream> 
#include <string>
#include <set>
#include <algorithm>


inline void PrintTheResult(std::string & iTestString, bool iWasUnique)
{
    std::cout << "Test string: "  << iTestString;
    if(false == iWasUnique)
    {
        std::cout << " Was not unique!";
    }       
    else
    {
        std::cout << " Was unique!";
    }
    std::cout << std::endl;
}

/*
THS 10/3/2020 If we aren't allowed to use a data structure we can use the fact that all 
characters are some ASCII value and sort them to check them pairwise for non-uniqueness.
*/
inline void CheckIfStringHasAllUniqueCharactersWithoutExtraDataStructure(std::string & iTestString)
{

    std::cout << "Check a string for all unique characters without using an additional data structure." << std::endl;
    std::cout << "assuming that the string is made of ascii characters you can do an std::sort and get them to be sorted by ascii value." << std::endl;
    std::cout << "Then just check if the string has any adjacent elements that are the same." << std::endl;
    std::cout << std::endl;
     bool wasUnique = true;
    std::string iTestStringBeforeSort = iTestString;
    std::sort(iTestString.begin(), iTestString.end());


    //THS 10/3/2020 Important to not run up to  actual end of list!
    for(int ii = 0; ii < iTestString.size() - 1; ii++)
    {
        char currentValue = iTestString.at(ii);
        char nextValue = iTestString.at(ii + 1);

        if(currentValue == nextValue)
        {
            wasUnique = false;
            break;
        }
        //else check the next pair of characters.
    }

    PrintTheResult(iTestString, wasUnique);

}

/*
THS 10/3/2020 Easiest way to check for uniqueness is to start filling out a set and see when 
the set shows that we have found a duplicate.
*/
inline void CheckIfStringHasAllUniqueCharacterWithExtraDataStructure(std::string & iTestString)
{
    //Explanation.
    std::cout << "************************Exercise 1.1***********************************" << std::endl;
    std::cout << "Check a string for all unique characters using an additional data structure." << std::endl;
    std::cout << "Using an std::set we can check the capacity before and after and see if we ever have less in the set than in the string at the current time." << std::endl;
    std::cout << "If you remember insert in std::set will return an std::pair<std::set<T>::iterator, bool> and the bool tells you if insert was successful or not." << std::endl;
    std::cout << std::endl;
    bool wasUnique = true;

    std::set<char> setOfCharacters = std::set<char>();

    for(int ii = 0; ii < iTestString.size(); ii++)
    {
        std::pair<std::set<char>::iterator, bool> result = setOfCharacters.insert(iTestString[ii]);
        
        if(false == result.second)
        {
            result.second;
            wasUnique = false;
            break;
        }
        //else continue looking for non-uniqueness.

    }

    PrintTheResult(iTestString, wasUnique);
}
inline void ReverseMyCStyleString(char iCStyleString[], int iSizeOfString)
{
    std::cout << "************************Exercise 1.2***********************************" << std::endl;
    std::cout << "Write code to reverse a C-Style string. (C-String means that \"abcd\" is represented" << std::endl;
    std::cout << "five characters, including a null character.)" << std::endl;


    std::cout << "String before: " << iCStyleString << std::endl;

    int index = 0;
    for(int ii = iSizeOfString; ii > 0; ii--)
    {
        char temp = iCStyleString[index];
        iCStyleString[index] = iCStyleString[ii];
        iCStyleString[ii] = temp; 
    }
    

        std::cout << "String after: " << iCStyleString << std::endl;

    


}