#include <iostream>

using namespace std;

/*******************************************
Write a program that uses only two output statements, cout << "#" and cout <<
"\n", to produce a pattern of hash symbols shaped like half of a perfect 5 x 5
square (or a right triangle):
#####
####
###
##
#
*******************************************/

string halfASquare() {
  string result = "";

  for (int row = 1; row <= 5; row++) {
    for (int numberOfHashes = 6 - row; numberOfHashes >= 1; numberOfHashes--) {
      result += "#";
    }
    result += "\n";
  }

  return result;
}

int main() {
  string result = halfASquare();
  if (result == "#####\n####\n###\n##\n#\n") {
    cout << result;
  } else {
    throw runtime_error("error");
  }

  return 0;
}
