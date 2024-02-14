#include <iostream>

using namespace std;

/*******************************************
A message has been encoded as a text stream that is to be read character by
character. The stream contains a series of comma-delimited integers, each a
positive number capable of being represented by a C++ int. However, the
character represented by a particular integer depends on the current decoding
mode. There are three modes: uppercase, lowercase, and punctuation. In uppercase
mode, each integer represents an uppercase letter: The integer modulo 27
indicates the letter of the alphabet (where 1 = A and so on). So an input value
of 143 in uppercase mode would yield the letter H because 143 modulo 27 is 8 and
H is the eighth letter in the alphabet. The lowercase mode works the same but
with lowercase letters; the remainder of dividing the integer by 27 represents
the lowercase letter (1 = a and so on). So an input value of 56 in lowercase
mode would yield the letter b because 57 modulo 27 is 2 and b is the second
letter in the alphabet. In punctuation mode, the integer is instead considered
modulo 9, with the interpretation given by Table 2-3 below. So 19 would yield
an exclamation point because 19 modulo 9 is 1. At the beginning of each message,
the decoding mode is uppercase letters. Each time the modulo operation (by 27 or
9, depending on mode) results in 0, the decoding mode switches. If the current
mode is uppercase, the mode switches to lowercase letters. If the current mode
is lowercase, the mode switches to punctuation, and if it is punctuation, it
switches back to uppercase.
*******************************************/

string decodeNextNumber(int numbers);

int stringToNumber(string numberAsString);

enum Mode { UPPERCASE, LOWERCASE, PUNCTUATION };

Mode mode = UPPERCASE;

int main() {
  string numbers =
      "18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10,";
  string decodedMessage = "";
  string numberAsString = "";
  for (char &character : numbers) {
    if (character == ',') {
      int final = stringToNumber(numberAsString);
      decodedMessage += decodeNextNumber(final);
      numberAsString = "";
    } else {
      numberAsString += character;
    }
  }

  cout << "Decoded message: " << decodedMessage << "\n";
  if (decodedMessage == "Right? Yes!") {
  } else {
    throw runtime_error("error");
  }
}

int stringToNumber(string numberAsString) {
  char nextCharacter = numberAsString[0];
  int number = (nextCharacter - '0');
  for (int i = 1; i < numberAsString.size(); i++) {
    nextCharacter = numberAsString[i];
    number = number * 10 + (nextCharacter - '0');
  }
  return number;
}

string decodeNextNumber(int number) {
  string uppercaseCharacters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I",
                                  "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                                  "S", "T", "U", "V", "W", "X", "Y", "Z"};

  string lowercaseCharacters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i",
                                  "j", "k", "l", "m", "n", "o", "p", "q", "r",
                                  "s", "t", "u", "v", "w", "x", "y", "z"};

  string punctuationCharacters[] = {"!", "?", ",", ".", " ", ";", "\"", "'"};

  switch (mode) {
    int result;
  case UPPERCASE:
    result = number % 27;
    if (result == 0) {
      mode = LOWERCASE;
      return "";
    } else {
      return uppercaseCharacters[result - 1];
    }
    break;

  case LOWERCASE:
    result = number % 27;
    if (result == 0) {
      mode = PUNCTUATION;
      return "";
    } else {
      return lowercaseCharacters[result - 1];
    }
    break;

  case PUNCTUATION:
    result = number % 9;
    if (result == 0) {
      mode = UPPERCASE;
      return "";
    } else {
      return punctuationCharacters[result - 1];
    }
    break;
  }
  return "error";
}
