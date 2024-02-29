#include <iostream>

using namespace std;

/*******************************************
Design your own: Think up your own symmetrical pattern of hash marks,
and see whether you can write a program to produce it that follows the
shapes rule:
########
 ######
  ####
   ##
  ####
 ######
########
*******************************************/

string hourglass() {
  string result = "";

  int hashes = 8;
  for (int row = 0; row < 7; row++) {
    int spaces = row < 3 ? row : 6 - row;
    for (int numberOfSpaces = 0; numberOfSpaces < spaces; numberOfSpaces++) {
      result += ' ';
    }
    for (int numberOfHashes = abs(hashes); numberOfHashes >= 1;
         numberOfHashes--) {
      result += "#";
    }
    result += "\n";
    hashes -= 2;
    if (row == 3) {
      hashes -= 4;
    }
  }
  return result;
}

int main() {
  string result = hourglass();
  cout << result;
  if (result ==
      "########\n ######\n  ####\n   ##\n  ####\n ######\n########\n") {
    cout << "ok";
  } else {
    throw runtime_error("error");
  }

  return 0;
}
