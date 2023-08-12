#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  int cur = 2;
  for (int i = 0; i < n - 1; i++) {
    cout << cur << " ";
    cur++;
  }
  cout << 1 << '\n';
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solution();
}
