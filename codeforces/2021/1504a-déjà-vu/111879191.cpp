#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  string s;
  cin >> s;
  bool ok = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != 'a') {
      ok = true;
    }
  }
  if (ok)
    for (int i = 0; i <= s.size(); i++) {
      // cout<<i<<" "<<s.size()-i-1<<" "<<s[s.size()-i-1]<<'\n';
      if ('a' != s[s.size() - i - 1]) {
        cout << "YES\n";
        for (int j = 0; j < i; j++) {
          cout << s[j];
        }
        cout << 'a';
        for (int j = i; j < s.size(); j++) {
          cout << s[j];
        }
        cout << '\n';
        return;
      }
    }
  cout << "NO\n";
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
