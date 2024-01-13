#include <iostream>
using std::cin;
using std::cout;

using namespace std;

string halfASquare() {
    string result = "";

  for(int row = 1; row <= 5; row++) {
      for(int i = 6 - row; i >= 1; i--) {
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
        throw runtime_error ("error");
    }

    return 0;
}

