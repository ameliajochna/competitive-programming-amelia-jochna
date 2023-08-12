#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
using namespace std;
typedef long long ll;
int const maxN = 11, maxM = 2e5 + 10;
int n, m, mxsum = 0, mxsuf[maxN], a[maxN][maxM], sz[maxN];
vector<int> answer, tmp;
set<vector<int> > bld;

void gen(int ind = 0, int sum = 0) {
  if (ind == n) {
    if (mxsum < sum && bld.find(tmp) == bld.end()) {
      mxsum = sum;
      answer = tmp;
    }
    return;
  }

  for (int i = sz[ind] - 1; i >= 0; i--)
    if (sum + a[ind][i] + mxsuf[ind] > mxsum) {
      tmp.push_back(i + 1);
      gen(ind + 1, sum + a[ind][i]);
      tmp.pop_back();
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> sz[i];
    for (int j = 0; j < sz[i]; j++) cin >> a[i][j];
  }

  cin >> m;
  vector<int> b(n);
  for (int i = 0; i < m; i++) {
    for (auto &x : b) cin >> x;
    bld.insert(b);
  }

  for (int i = n - 2; i >= 0; i--)
    mxsuf[i] = mxsuf[i + 1] + a[i + 1][sz[i + 1] - 1];

  gen();
  for (int i = 0; i < n; i++) cout << answer[i] << " ";
  cout << '\n';
  return 0;
}
