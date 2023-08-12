#include <iostream>
using namespace std;
int n, b, a;
int main(int argc, char **argv) {
  cin >> n;
  a = 0;
  for (int j = n; j > 0; j--) {
    cin >> b;
    a = a + b;
    cout << a << " ";
  }
  return 0;
}
