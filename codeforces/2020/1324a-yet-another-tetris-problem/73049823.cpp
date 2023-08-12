#include <bits/stdc++.h>
using namespace std;
int t, n, a;
bool printed;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int i = 0; i < t; i++) {
    printed = false;
    cin >> n;
    cin >> a;
    int mod = a % 2;
    for (int j = 1; j < n; j++) {
      cin >> a;
      if (a % 2 != mod && !printed) {
        cout << "NO" << '\n';
        printed = true;
      }
    }
    if (!printed)
      cout << "YES"
           << "\n";
  }

  return 0;
}
