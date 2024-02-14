#include <iostream>

using namespace std;

/*******************************************
Write a program that uses only two output statements, cout << "#" and cout <<
"\n", to produce a pattern of hash symbols shaped like a sideways triangle:
#
##
###
####
###
##
#
*******************************************/

string sidewaysTriangle() {
  string result = "";

  for (int row = 1; row <= 7; row++) {
    for (int numberOfHashes = 4 - abs(row - 4); numberOfHashes > 0;
         numberOfHashes--) {
      result += "#";
    }
    result += "\n";
  }

  return result;
}

int main() {
  string result = sidewaysTriangle();
  cout << result;
  if (result == "#\n##\n###\n####\n###\n##\n#\n") {
  } else {
    throw runtime_error("error");
  }

  return 0;
}
