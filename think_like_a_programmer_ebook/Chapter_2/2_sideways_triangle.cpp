#include <iostream>
using std::cin;
using std::cout;

using namespace std;

string sidewaysTriangle() {
  string result = "";

  for (int row = 1; row <= 7; row++) {
    for (int numberOfHashes = 4 - abs(row - 4); numberOfHashes > 0; numberOfHashes--) {
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

