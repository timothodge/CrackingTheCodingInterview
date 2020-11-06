
#include "Chapter1Exercises.h"


int main()
{
#pragma region Exercise 1.1

    std::string testString = "Jennifer";
    CheckIfStringHasAllUniqueCharacterWithExtraDataStructure(testString);


    CheckIfStringHasAllUniqueCharactersWithoutExtraDataStructure(testString);
#pragma endregion

#pragma region Exercise 1.2

    char cStyleTestString[]{"abcd"};
    ReverseMyCStyleString(cStyleTestString, 4);

#pragma endregion

    return 0;
}


