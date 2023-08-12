#include <bits/stdc++.h>
using namespace std;

void solution() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (max({a, b, c})) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
