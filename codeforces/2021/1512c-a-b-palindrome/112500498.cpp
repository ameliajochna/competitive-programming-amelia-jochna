#include <bits/stdc++.h>
using namespace std;

void solution() {
  int a, b;  // a-zero, b-jeden
  cin >> a >> b;
  string s, ans;
  cin >> s;
  ans = s;
  int n = s.size(), cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != '?') {
      if (s[n - i - 1] != '?' && s[i] != s[n - i - 1]) {
        cout << "-1\n";
        return;
      }
      if (s[i] == '0')
        a--;
      else
        b--;
      continue;
    }
    if (s[n - i - 1] == '1') {
      ans[i] = '1';
      b--;
    } else if (s[n - i - 1] == '0') {
      ans[i] = '0';
      a--;
    } else {
      cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] != '?') continue;
    if (i == (n - i - 1)) {
      if (b % 2 == 1) {
        ans[i] = '1';
        b--;
      } else if (a % 2 == 1) {
        ans[i] = '0';
        a--;
      } else {
        cout << "-1\n";
        return;
      }
    }
    if (a >= 2) {
      ans[i] = '0';
      ans[n - i - 1] = '0';
      a -= 2;
    } else if (b >= 2) {
      ans[i] = '1';
      ans[n - i - 1] = '1';
      b -= 2;
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (ans[i] == '?' || (ans[i] != ans[n - i - 1])) ok = false;
  }
  if (a == 0 && b == 0 && ok)
    cout << ans << '\n';
  else
    cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
