#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  if (n % 4 != 0)
    cout << "NO\n";
  else {
    cout << "YES\n";
    int prev = 0;
    int last;
    for (int i = 0; i < n / 2; i++) {
      cout << prev + 2 << " ";
      prev += 2;
    }
    int cur = 1;
    for (int i = 0; i < n / 2 - 1; i++) {
      cout << cur << " ";
      cur += 2;
    }
    cout << prev + (n / 2) - 1 << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
