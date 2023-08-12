#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt[2] = {0, 0};
  for (auto x : s) cnt[x - '0']++;
  if (cnt[0] % 2 == 1 || cnt[1] % 2 == 1 || s[0] == '0' || s[n - 1] == '0') {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  string a, b;
  a.resize(n), b.resize(n);
  int k = cnt[1] / 2;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') continue;
    if (k > 0)
      a[i] = '(', b[i] = '(';
    else
      a[i] = ')', b[i] = ')';
    k--;
  }
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') continue;
    if (flag)
      a[i] = '(', b[i] = ')';
    else
      a[i] = ')', b[i] = '(';
    flag = !flag;
  }
  cout << a << '\n';
  cout << b << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
/*

 */
