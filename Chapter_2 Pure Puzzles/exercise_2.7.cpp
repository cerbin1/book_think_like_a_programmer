#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

/*******************************************
Try writing a program that lets the user specify
an input in binary, decimal, or hexadecimal,
and output in any of the three.
*******************************************/

string binaryToDecimal(string binaryNumberInput);
string binaryToHexadecimal(string binaryNumberInput);
string decimalToBinary(string decimalNumberInput);
string decimalToHexadecimal(string decimalNumberInput);
string hexadecimalToBinary(string hexadecimalNumberInput);
string hexadecimalToDecimal(string hexadecimalNumberInput);
string toHex(int decimalNumber);

enum BaseNumberalSystem { Binary = 1, Decimal = 2, Hexadecimal = 3 };

int main() {
  string binaryNumberInput = "11110001001000000";
  string decimalNumberInput = "123456";
  string hexadecimalNumberInput = "1E240";
  BaseNumberalSystem systems[] = {Binary, Decimal, Hexadecimal};

  for (int i = 0; i < sizeof(systems); i++) {

    BaseNumberalSystem baseSystem = systems[i];

    switch (baseSystem) {
    case Binary: {
      string decimalToBinaryOutput = decimalToBinary(decimalNumberInput);
      cout << "decimal to binary: " << decimalToBinaryOutput << "\n";
      if (decimalToBinaryOutput.compare("11110001001000000")) {
        throw runtime_error("error");
      }
      string hexadecimalToBinaryOutput =
          hexadecimalToBinary(hexadecimalNumberInput);
      cout << "hexadecimal to binary: " << hexadecimalToBinaryOutput << "\n";
      if (hexadecimalToBinaryOutput.compare("11110001001000000")) {
        throw runtime_error("error");
      }
      break;
    }
    case Decimal: {
      string binaryToDecimalOutput = binaryToDecimal(binaryNumberInput);
      cout << "binary to decimal: " << binaryToDecimalOutput << "\n";
      if (binaryToDecimalOutput.compare("123456")) {
        throw runtime_error("error");
      }
      string hexadecimalToDecimalOutput =
          hexadecimalToDecimal(hexadecimalNumberInput);
      cout << "hexadecimal to decimal: " << hexadecimalToDecimalOutput << "\n";
      if (hexadecimalToDecimalOutput.compare("123456")) {
        throw runtime_error("error");
      }
      break;
    }
    case Hexadecimal:
      string binaryToHexadecimalOutput = binaryToHexadecimal(binaryNumberInput);
      cout << "binary to hexadecimal: " << binaryToHexadecimalOutput << "\n";
      if (binaryToHexadecimalOutput.compare("1E240")) {
        throw runtime_error("error");
      }
      string decimalToHexadecimalOutput =
          decimalToHexadecimal(decimalNumberInput);
      cout << "decimal to hexadecimal: " << decimalToHexadecimalOutput << "\n";
      if (decimalToHexadecimalOutput.compare("1E240")) {
        throw runtime_error("error");
      }
      break;
    }
  }
}

string binaryToDecimal(string binaryNumberInput) {
  int decimal = 0;
  for (int i = binaryNumberInput.length() - 1, powerBase = 0; i >= 0;
       i--, powerBase++) {
    int nextBinaryDigit = binaryNumberInput.at(i) - '0';
    decimal += nextBinaryDigit * pow(2, powerBase);
  }
  return to_string(decimal);
}

string binaryToHexadecimal(string binaryNumberInput) {
  string hexadecimal = "";
  string nextSequenceOfBinary = "";
  for (int i = binaryNumberInput.length() - 1; i >= 0; i--) {
    nextSequenceOfBinary += binaryNumberInput.at(i);

    if (nextSequenceOfBinary.size() == 4 || i == 0) {
      if (nextSequenceOfBinary.size() < 4) {
        nextSequenceOfBinary += string(4 - nextSequenceOfBinary.size(), '0');
      }
      reverse(nextSequenceOfBinary.begin(), nextSequenceOfBinary.end());

      if (nextSequenceOfBinary == "0000") {
        hexadecimal.insert(0, "0");
      } else if (nextSequenceOfBinary == "0001") {
        hexadecimal.insert(0, "1");
      } else if (nextSequenceOfBinary == "0010") {
        hexadecimal.insert(0, "2");
      } else if (nextSequenceOfBinary == "0011") {
        hexadecimal.insert(0, "3");
      } else if (nextSequenceOfBinary == "0100") {
        hexadecimal.insert(0, "4");
      } else if (nextSequenceOfBinary == "0101") {
        hexadecimal.insert(0, "5");
      } else if (nextSequenceOfBinary == "0110") {
        hexadecimal.insert(0, "6");
      } else if (nextSequenceOfBinary == "0111") {
        hexadecimal.insert(0, "7");
      } else if (nextSequenceOfBinary == "1000") {
        hexadecimal.insert(0, "8");
      } else if (nextSequenceOfBinary == "1001") {
        hexadecimal.insert(0, "9");
      } else if (nextSequenceOfBinary == "1010") {
        hexadecimal.insert(0, "A");
      } else if (nextSequenceOfBinary == "1011") {
        hexadecimal.insert(0, "B");
      } else if (nextSequenceOfBinary == "1100") {
        hexadecimal.insert(0, "C");
      } else if (nextSequenceOfBinary == "1101") {
        hexadecimal.insert(0, "D");
      } else if (nextSequenceOfBinary == "1110") {
        hexadecimal.insert(0, "E");
      } else if (nextSequenceOfBinary == "1111") {
        hexadecimal.insert(0, "F");
      }
      nextSequenceOfBinary = "";
    }
  }
  return hexadecimal;
}

string decimalToBinary(string decimalNumberInput) {
  string binary = "";

    int decimal = stoi(decimalNumberInput);
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

string decimalToHexadecimal(string decimalNumberInput) {
  string hexadecimal = "";

  int decimal = stoi(decimalNumberInput);
  int power;
  for (int i = 0; i < 1000; i++) {
    if (pow(16, i) > decimal) {
      power = i - 1;
      break;
    }
  }

  while (power >= 0) {
    int nextPower = pow(16, power);
    if (nextPower > decimal) {
      hexadecimal += "0";
    } else {
      int result = decimal / nextPower;
      hexadecimal += toHex(result);
      decimal -= nextPower * result;
    }
    power--;
  }

  return hexadecimal;
}

string toHex(int hexDigit) {
  if (hexDigit > 9) {
    switch (hexDigit) {
    case 10:
      return "A";
    case 11:
      return "B";
    case 12:
      return "C";
    case 13:
      return "D";
    case 14:
      return "E";
    case 15:
      return "F";
    }
  } else {
    return to_string(hexDigit);
  }
  return "ERROR";
}

string hexadecimalToBinary(string hexadecimalNumberInput) {
  string binary = "";

  for (int i = 0; i < hexadecimalNumberInput.length(); i++) {
    switch (hexadecimalNumberInput[i]) {
    case '0':
      binary += "0000";
      break;
    case '1':
      binary += "0001";
      break;
    case '2':
      binary += "0010";
      break;
    case '3':
      binary += "0011";
      break;
    case '4':
      binary += "0100";
      break;
    case '5':
      binary += "0101";
      break;
    case '6':
      binary += "0110";
      break;
    case '7':
      binary += "0111";
      break;
    case '8':
      binary += "1000";
      break;
    case '9':
      binary += "1001";
      break;
    case 'A':
      binary += "1010";
      break;
    case 'B':
      binary += "1011";
      break;
    case 'C':
      binary += "1100";
      break;
    case 'D':
      binary += "1101";
      break;
    case 'E':
      binary += "1110";
      break;
    case 'F':
      binary += "1111";
      break;
    }
  }

  binary.erase(0, binary.find_first_not_of('0'));

  return binary;
}

short hexaCharToNumber(char hexaDigit) {
  switch (hexaDigit) {
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
    return hexaDigit - '0';
  }
}

string hexadecimalToDecimal(string hexadecimalNumberInput) {
  int decimal = 0;
  for (int i = hexadecimalNumberInput.length() - 1, powerBase = 0; i >= 0;
       i--, powerBase++) {
    int nextHexaDigit = hexadecimalNumberInput.at(i);
    decimal += hexaCharToNumber(nextHexaDigit) * pow(16, powerBase);
  }
  return to_string(decimal);
}
