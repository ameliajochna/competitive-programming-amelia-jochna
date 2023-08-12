#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0, ans = 0;
  for (auto c : s) {
    if (c == 'x')
      cnt++;
    else
      ans += max(0, cnt - 2), cnt = 0;
  }
  ans += max(0, cnt - 2);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  // cin>>t;
  while (t--) solution();
  return 0;
}
