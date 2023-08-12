#include <iostream>
using namespace std;

int main() {
  string in;
  cin >> in;
  if ((in[in.length() - 1] - 30) % 2 == 0)
    cout << "0";
  else
    cout << "1";
  return 0;
}
