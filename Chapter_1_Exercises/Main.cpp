#include <iostream> 
#include <string>
#include <set>
#include <algorithm>

void PrintTheResult(std::string & iTestString, bool iWasUnique)
{
    std::cout << iTestString;
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
THS 10/3/2020 Easiest way to check for uniqueness is to start filling out a set and see when 
the set shows that we have found a duplicate.
*/
void CheckIfStringHasAllUniqueCharacterWithExtraDataStructure(std::string & iTestString)
{
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

/*
THS 10/3/2020 If we aren't allowed to use a data structure we can use the fact that all 
characters are some ASCII value and sort them to check them pairwise for non-uniqueness.
*/
void CheckIfStringHasAllUniqueCharactersWithoutExtraDataStructure(std::string & iTestString)
{

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

void ReverseMyCStyleString(char iCStyleString[])
{

    std::cout << "String before: " << iCStyleString << std::endl;

}



int main()
{
#pragma region Exercise 1.1

    std::string testString = "Jennifer";
    CheckIfStringHasAllUniqueCharacterWithExtraDataStructure(testString);
    

    CheckIfStringHasAllUniqueCharactersWithoutExtraDataStructure(testString);
#pragma endregion
    
#pragma region Exercise 1.2

    char cStyleTestString[]{"abcd"};
    ReverseMyCStyleString(cStyleTestString);

#pragma endregion
    
    return 0;
}


