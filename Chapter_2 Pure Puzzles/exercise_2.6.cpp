#include <cmath>
#include <iostream>
#include <string>

using namespace std;

/*******************************************
If you’ve learned about binary numbers and how to convert from decimal
to binary and the reverse, try writing programs to do those conversions with
unlimited length numbers (but you can assume the numbers are small
enough to be stored in a standard C++ int).
*******************************************/

string binaryToDecimal(string binaryNumber);
string decimalToBinary(string decimalNumber);
int main() {
  string decimalNumber = "123456";
  string binaryNumber = "11110001001000000";

  string decimal = binaryToDecimal(binaryNumber);
  string binary = decimalToBinary(decimalNumber);

  cout << "Decimal: " << decimal << "\n";
  if (decimal.compare("123456")) {
    throw runtime_error("error");
  }

  cout << "Binary: " << binary << "\n";
  if (binary.compare("11110001001000000")) {
    throw runtime_error("error");
  }
}

string binaryToDecimal(string binaryNumber) {
  int decimal = 0;
  for (int i = binaryNumber.length() - 1, asd = 0; i >= 0; i--, asd++) {
    int digit = binaryNumber.at(i) - '0';
    decimal += digit * pow(2, asd);
  }
  return to_string(decimal);
}

string decimalToBinary(string decimalNumber) {
  string binary = "";

  int decimal = stoi(decimalNumber);
  int power;
  for (int i = 0; i < 1000; i++) {
    if (pow(2, i) > decimal) {
      power = i - 1;
      break;
    }
  }

  while (power >= 0) {
    int nextPower = pow(2, power);
    if (nextPower > decimal) {
      binary += "0";
    } else {
      binary += "1";
      decimal -= nextPower;
    }
    power--;
  }

  return binary;
}
