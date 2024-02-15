#include <iostream>

using namespace std;

/*******************************************
Using the same rule as the shapes programs from earlier in the chapter (only
two output statements—one that outputs the hash mark and one that outputs
an end-of-line), write a program that produces the following shape:
########
 ######
  ####
   ##
*******************************************/

string halfASquare() {
  string result = "";

  for (int row = 1; row < 5; row++) {
    for (int numberOfSpaces = 1; numberOfSpaces < row; numberOfSpaces++) {
      result += ' ';
    }
    for (int numberOfHashes = 10 - row * 2; numberOfHashes >= 1;
         numberOfHashes--) {
      result += "#";
    }
    result += "\n";
  }

  return result;
}

int main() {
  string result = halfASquare();
  if (result == "########\n ######\n  ####\n   ##\n") {
    cout << result;
  } else {
    throw runtime_error("error");
  }

  return 0;
}
