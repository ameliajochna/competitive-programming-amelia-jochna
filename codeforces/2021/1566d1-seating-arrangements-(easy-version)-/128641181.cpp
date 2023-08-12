#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n, m;
  cin >> n >> m;
  vector<int> v(m), org(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i];
    org[i] = v[i];
  }
  sort(v.begin(), v.end());
  map<int, int> mp;
  for (int i = 0; i < m; i++) mp[v[i]] = i;
  vector<int> s(m);
  for (int i = 0; i < m; i++) {
    s[i] = mp[org[i]];
    mp[org[i]]--;
    // cout<<i<<" "<<s[i]<<'\n';
  }
  int ans = 0;
  vector<bool> taken(m);
  for (int i = 0; i < m; i++) {
    int cur = s[i];
    for (int j = 0; j < cur; j++) {
      if (taken[j]) ans++;
    }
    taken[cur] = true;
  }
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
