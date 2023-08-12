#include <bits/stdc++.h>
using namespace std;

void solution() {
  string s;
  cin >> s;
  int ind = -1, n = s.size();
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '1' && s[i + 1] == '1' && ind == -1) ind = i;
  }

  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '0' && s[i + 1] == '0' && ind != -1 && ind < i) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
