#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
#define pb push_back
using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<vector<int> > v(n);
  for (int i = 0; i < n; i++) {
    v[i].resize(5);
    for (int j = 0; j < 5; j++) cin >> v[i][j];
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == j) continue;
      int cnti = 0, cntj = 0, cntboth = 0;
      bool flag = true;
      for (int k = 0; k < n; k++) {
        if (v[k][i] && v[k][j])
          cntboth++;
        else if (v[k][i])
          cnti++;
        else if (v[k][j])
          cntj++;
        else
          flag = false;
      }
      if (!flag) continue;
      if (cnti <= (n / 2) && cntj <= (n / 2)) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
}
