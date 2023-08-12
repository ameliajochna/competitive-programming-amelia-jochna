#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << (n / 2 - 1) << '\n';
  } else {
    cout << ((n - 1) / 2) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();

  return 0;
}
