#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<pair<int, int> > s(n);
  vector<int> extra(n);
  for (int i = 0; i < n; i++) cin >> s[i].first >> s[i].second;
  for (int i = 0; i < n; i++) cin >> extra[i];
  int curtime = s[0].first + extra[0];
  for (int i = 0; i < n - 1; i++) {
    // cout<<i<<": "<<curtime<<'\n';
    int tmp = (s[i].second - s[i].first + 1) / 2;
    curtime += tmp;
    curtime = max(curtime, s[i].second);
    // cout<<i<<": "<<curtime<<'\n';
    curtime += s[i + 1].first - s[i].second + extra[i + 1];
  }
  cout << curtime << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
