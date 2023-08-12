#include <bits/stdc++.h>
using namespace std;

int cnt[28];

void solve() {
  vector<int> c(28);
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) c[s[i] - 'a']++;
  for (int i = 0; i < 27; i++)
    if (c[i] != cnt[i]) {
      return;
    }
  cout << s << '\n';
}

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
  int t;
  cin >> t;
  while (t--) solve();
}
