#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define pb push_back
using namespace std;
typedef long long ll;
int const maxN = 1010;
int n, m;
char a[maxN][maxN];
vector<int> ans;

bool check(string &s) {
  vector<vector<bool> > vis(n);
  for (int i = 0; i < n; i++) vis[i].resize(m);

  int len = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j]) continue;
      // check horizontally
      bool flag = false;
      if (j + len <= m) {
        flag = true;
        for (int k = j; k < j + len; k++)
          if (a[i][k] != s[k - j] || vis[i][k]) {
            flag = false;
            break;
          }

        if (flag) {
          for (int k = j; k < j + len; k++) vis[i][k] = true;
        }
      }
      // check vertically
      if (!flag && i + len <= n) {
        flag = true;
        for (int k = i; k < i + len; k++)
          if (a[k][j] != s[k - i] || vis[k][j]) {
            flag = false;
            break;
          }
        if (flag) {
          for (int k = i; k < i + len; k++) vis[k][j] = true;
        }
      }
      if (!flag) return false;
    }
  }
  return true;
}

void gen() {
  vector<int> poslen;
  int nm = n * m, minnm = min(n, m);
  for (int i = 1; i <= max(n, m); i++)
    if (n % i == 0 || m % i == 0) poslen.pb(i);
  string hor, ver;
  int prev = -1;
  for (int i = 0; i < poslen.size(); i++) {
    bool skip = false;
    for (int j = prev + 1; j < poslen[i]; j++) {
      hor = hor + a[0][j];
      ver = ver + a[j][0];
    }
    prev = poslen[i] - 1;
    if (check(hor) || check(ver)) ans.push_back(poslen[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  gen();
  cout << ans.size() << '\n';
  for (auto k : ans) cout << k << " ";
}
