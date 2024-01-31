#include <iostream>

using namespace std;
int getSumOfDigitsMultipliedByTwo(int digit);
int main()
{
    int sumOfDigitsForEvenNumber = 0;
    int sumOfDigitsForOddNumber = 0;
    int numbersCount = 1;
    cout << "Enter number: ";
    char nextCharacter = cin.get();
    while (nextCharacter != 10)
    {
        int nextDigit = nextCharacter - '0';
        if (numbersCount % 2 == 0)
        {
            sumOfDigitsForOddNumber += nextDigit;
            sumOfDigitsForEvenNumber += getSumOfDigitsMultipliedByTwo(nextDigit);
        }
        else
        {
            sumOfDigitsForOddNumber += getSumOfDigitsMultipliedByTwo(nextDigit);
            sumOfDigitsForEvenNumber += nextDigit;
        }

        numbersCount++;
        nextCharacter = cin.get();
    }

    bool inputNumberEven = numbersCount % 2 == 0;
    cout << "The number was " << (inputNumberEven ? "even" : "odd") << ".\n";
    int finalSum = (inputNumberEven ? sumOfDigitsForEvenNumber : sumOfDigitsForOddNumber);
    cout << "Sum: " << finalSum << "\n";
    cout << "Checksum is: " << (finalSum % 10 == 0 ? "correct" : "incorrect") << "\n";
}

int getSumOfDigitsMultipliedByTwo(int digit)
{
    if (digit < 5)
    {
        return digit * 2;
    }
    else
    {
        return 1 + (digit * 2 % 10);
    }
}

// g++ luhn_checksum.cpp
// ./a.out
