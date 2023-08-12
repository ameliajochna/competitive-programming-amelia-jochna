#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int const maxN = 3e5 + 10;
vector<int> ind[maxN];
int a[maxN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ind[a[i]].push_back(i);
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int cnt = 40;
    int maxcnt = 0;
    while (cnt--) {
      int j = rng() % (r - l + 1) + l;
      int val = a[j];
      int pos = upper_bound(ind[val].begin(), ind[val].end(), r) -
                lower_bound(ind[val].begin(), ind[val].end(), l);
      maxcnt = max(maxcnt, pos);
    }
    if (maxcnt > (r - l + 2) / 2)
      cout << 2 * maxcnt - (r - l + 1) << '\n';
    else
      cout << 1 << '\n';
  }
}
