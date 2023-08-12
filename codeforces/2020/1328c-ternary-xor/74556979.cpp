#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio();
  cin.tie();
  cout.tie();
  int t, n;
  cin >> t;
  for (int q = 0; q < t; q++) {
    cin >> n;
    string number;
    cin >> number;
    string n1, n2;
    bool bigger = false;
    for (int i = 0; i < n; i++) {
      if (number[i] == '1') {
        if (bigger) {
          n1 += '0';
          n2 += '1';
        } else {
          bigger = true;
          n1 += '1';
          n2 += '0';
        }
      } else if (number[i] == '0') {
        n1 += '0';
        n2 += '0';
      } else if (number[i] == '2') {
        if (!bigger) {
          n1 += '1';
          n2 += '1';
        } else {
          n1 += '0';
          n2 += '2';
        }
      }
    }
    cout << n2 << "\n" << n1 << '\n';
  }
  return 0;
}
