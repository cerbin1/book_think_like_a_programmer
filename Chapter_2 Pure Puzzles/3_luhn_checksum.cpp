#include <iostream>

using namespace std;

/*******************************************
The Luhn formula is a widely used system for validating identification numbers.
Using the original number, double the value of every other digit. Then add the
values of the individual digits together (if a doubled value now has two digits,
add the digits indi- vidually). The identification number is valid if the sum is
divisible by 10. Write a program that takes an identification number of
arbitrary length and determines whether the number is valid under the Luhn
formula. The program must process each character before reading the next one.
*******************************************/

int getSumOfDigitsMultipliedByTwo(int digit);
int main() {
  int sumOfDigitsForEvenNumber = 0;
  int sumOfDigitsForOddNumber = 0;
  int numbersCount = 1;
  cout << "Enter number: ";
  char nextCharacter = cin.get();
  while (nextCharacter != 10) {
    int nextDigit = nextCharacter - '0';
    if (numbersCount % 2 == 0) {
      sumOfDigitsForOddNumber += nextDigit;
      sumOfDigitsForEvenNumber += getSumOfDigitsMultipliedByTwo(nextDigit);
    } else {
      sumOfDigitsForOddNumber += getSumOfDigitsMultipliedByTwo(nextDigit);
      sumOfDigitsForEvenNumber += nextDigit;
    }

    numbersCount++;
    nextCharacter = cin.get();
  }

  bool inputNumberEven = numbersCount % 2 == 0;
  cout << "The number was " << (inputNumberEven ? "even" : "odd") << ".\n";
  int finalSum =
      (inputNumberEven ? sumOfDigitsForEvenNumber : sumOfDigitsForOddNumber);
  cout << "Sum: " << finalSum << "\n";
  cout << "Checksum is: " << (finalSum % 10 == 0 ? "correct" : "incorrect")
       << "\n";
}

int getSumOfDigitsMultipliedByTwo(int digit) {
  if (digit < 5) {
    return digit * 2;
  } else {
    return 1 + (digit * 2 % 10);
  }
}
