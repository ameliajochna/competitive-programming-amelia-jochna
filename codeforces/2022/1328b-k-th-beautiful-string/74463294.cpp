#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio();
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n, k, counter = 1;
    cin >> n >> k;
    int i = n - 2;
    while (counter <= k) {
      counter += n - 1 - i;
      i--;
    }
    i++;
    counter = counter - (n - 1 - i);
    int sec_b = n;
    for (int j = 0; j < i; j++) {
      cout << "a";
    }
    cout << "b";
    while (counter != k) {
      sec_b--;
      counter++;
    }
    for (int j = i + 1; j < sec_b - 1; j++) {
      cout << "a";
    }
    cout << "b";
    for (int j = sec_b + 1; j <= n; j++) cout << "a";
    cout << '\n';
  }

  return 0;
}
