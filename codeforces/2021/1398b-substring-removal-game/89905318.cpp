#include <bits/stdc++.h>
using namespace std;

void solution() {
  string s;
  cin >> s;
  s = s + '0';
  int onecnt = 0;
  vector<int> a;
  for (int i = 0; i < s.size(); i++) {
    char e = s[i];
    if (e == '0') {
      if (onecnt != 0) {
        a.push_back(onecnt), onecnt = 0;
      }
    } else
      onecnt++;
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = a.size() - 1; i >= 0; i -= 2) ans += a[i];
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
