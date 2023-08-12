#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<vector<int> > v(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    v[i].resize(k);
    for (int j = 0; j < k; j++) cin >> v[i][j];
  }
  vector<pair<int, int> > maxloc;  // max local, indeks
  for (int i = 0; i < n; i++) {
    int cnt = 0, maxval = 1;
    for (int j = 0; j < v[i].size(); j++) {
      maxval = max(maxval, v[i][j] - cnt);
      cnt++;
    }
    maxloc.push_back({maxval, i});
  }

  sort(maxloc.begin(), maxloc.end());

  int cnt = 0, maxv = 1;
  for (int x = 0; x < n; x++) {
    int ind = maxloc[x].nd;
    for (int i = 0; i < v[ind].size(); i++) {
      maxv = max(maxv, v[ind][i] - cnt);
      cnt++;
    }
  }
  cout << maxv + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
