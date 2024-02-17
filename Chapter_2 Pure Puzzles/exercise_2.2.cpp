#include <iostream>

using namespace std;

/*******************************************
Using the same rule as the shapes programs from earlier in the chapter (only
two output statements—one that outputs the hash mark and one that outputs
an end-of-line), write a program that produces the following shape:
   ##
  ####
 ######
########
########
 ######
  ####
   ##
*******************************************/

string halfASquare() {
  string result = "";
  int numberOfRows = 8;
  int numberOfSpacesInRow[8] = {3, 2, 1, 0, 0, 1, 2, 3};
  int numberOfHashesInRow[8] = {2, 4, 6, 8, 8, 6, 4, 2};

  for (int row = 0; row < numberOfRows; row++) {
    result += std::string(numberOfSpacesInRow[row], ' ');
    result += std::string(numberOfHashesInRow[row], '#');
    result += "\n";
  }

  return result;
}

int main() {
  string result = halfASquare();
  if (result ==
      "   ##\n  ####\n ######\n########\n########\n ######\n  ####\n   ##\n") {
    cout << result;
  } else {
    throw runtime_error("error");
  }

  return 0;
}
