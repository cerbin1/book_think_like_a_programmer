#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

/*******************************************
Generalize the code for the previous exercise tomake a program that converts
from any number base-16 or less to any other number base. So, for example,
the program could convert from base-9 to base-4.
*******************************************/

int toNumber(char character);
string convertNumberFromOneBaseSystemToAnother(int baseSystemFrom,
                                               int baseSystemTo, string number);

int main() {
  const int BINARY = 2;
  const int DECIMAL = 10;
  string inputNumbers[] = {"11110001001000000",
                           "20021100110",
                           "132021000",
                           "12422311",
                           "2351320",
                           "1022634",
                           "361100",
                           "207313",
                           "123456",
                           "84833",
                           "5B540",
                           "44268",
                           "32DC4",
                           "268A6",
                           "1E240"};

  for (int i = 0, baseSystem = BINARY; i < size(inputNumbers);
       baseSystem++, i++) {
    string result = convertNumberFromOneBaseSystemToAnother(baseSystem, DECIMAL,
                                                            inputNumbers[i]);
    cout << "Result: " << result << "\n";
    assert(result == "123456");
  }
}

string convertNumberFromOneBaseSystemToAnother(int baseSystemFrom,
                                               int baseSystemTo,
                                               string number) {
  int decimal = 0;
  for (int i = number.length() - 1, powerBase = 0; i >= 0; i--, powerBase++) {
    char nextCharacter = number.at(i);
    int nextDigitOrNumber = toNumber(nextCharacter);
    decimal += nextDigitOrNumber * pow(baseSystemFrom, powerBase);
  }
  return to_string(decimal);
}

int toNumber(char character) {
  switch (character) {
  case 'A':
    return 10;
  case 'B':
    return 11;
  case 'C':
    return 12;
  case 'D':
    return 13;
  case 'E':
    return 14;
  case 'F':
    return 15;
  default:
    return character - '0';
  }
}
