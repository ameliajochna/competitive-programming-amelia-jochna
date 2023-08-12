#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

int different(vector<int> v) {
  for (int i = 'a'; i <= 'z'; i++) {
    bool git = true;
    for (int j = 0; j < v.size(); j++) {
      if (v[j] == i) git = false;
    }
    if (git) return i;
  }
}

void solve() {
  int n;
  string s;
  cin >> s;
  n = s.size();
  s = ".." + s + "....";
  int cnt = 0;
  for (int i = 3; i < n + 2; i++) {
    if (s[i] == s[i - 1] || s[i] == s[i - 2]) {
      s[i] = char(different({s[i - 2], s[i - 1], s[i], s[i + 1], s[i + 2]}));
      cnt++;
    }
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
