#include <algorithm>
#include <iostream>

using namespace std;

/*******************************************
If you like the Luhn formula problem, try writing a program for a different
check-digit system, like the 13-digit ISBN system. The program take an
identification number without its check digit and generate the check digit.
*******************************************/

int generateCheckDigit(string isbnWithoutCheckDigit);
int main() {
  string isbnWithoutCheckDigit = "978-83-7181-510-";
  isbnWithoutCheckDigit.erase(std::remove(isbnWithoutCheckDigit.begin(),
                                          isbnWithoutCheckDigit.end(), '-'),
                              isbnWithoutCheckDigit.end());

  int checkDigit = generateCheckDigit(isbnWithoutCheckDigit);

  if (checkDigit == 2) {
    cout << "Check digit: " << checkDigit;
  } else {
    throw runtime_error("error");
  }
}

int generateCheckDigit(string isbnWithoutCheckDigit) {
  int sum = 0;
  for (int i = 1; i <= isbnWithoutCheckDigit.length(); i++) {
    int nextDigit = isbnWithoutCheckDigit.at(i - 1) - '0';
    if (i % 2 == 0) {
      sum += nextDigit * 3;
    } else {
      sum += nextDigit;
    }
  }

  return 10 - (sum % 10);
}
