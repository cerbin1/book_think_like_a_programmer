#include <iostream>

using namespace std;

/*******************************************
Using the same rule as the shapes programs from earlier in the chapter (only
two output statements—one that outputs the hash mark and one that outputs
an end-of-line), write a program that produces the following shape:
#            #
 ##        ##
  ###    ###
   ########
   ########
  ###    ###
 ##        ##
#            #
*******************************************/

string halfASquare() {
  string result = "";
  int numberOfRows = 8;
  int numberOfSpacesOnStart[8] = {0, 1, 2, 3, 3, 2, 1, 0};
  int numberOfHashes[8] = {1, 2, 3, 4, 4, 3, 2, 1};
  int numberOfSpacesInMiddle[8] = {12, 8, 4, 0, 0, 4, 8, 12};

  for (int row = 0; row < numberOfRows; row++) {
    result += std::string(numberOfSpacesOnStart[row], ' ');
    result += std::string(numberOfHashes[row], '#');
    result += std::string(numberOfSpacesInMiddle[row], ' ');
    result += std::string(numberOfHashes[row], '#');
    result += "\n";
  }

  return result;
}

int main() {
  string result = halfASquare();
  if (result == "#            #\n ##        ##\n  ###    ###\n   ########\n   "
                "########\n  ###    ###\n ##        ##\n#            #\n") {
    cout << result;
  } else {
    throw runtime_error("error");
  }

  return 0;
}
