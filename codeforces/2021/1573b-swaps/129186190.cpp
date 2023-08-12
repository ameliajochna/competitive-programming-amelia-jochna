#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<int> posa(2 * n + 1), posb(2 * n + 1, 1e9), va(n), vb(n);
  for (int i = 0; i < n; i++) {
    cin >> va[i];
    posa[va[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> vb[i];
    posb[vb[i]] = i;
  }

  vector<int> sufmin(2 * n + 2, 1e9);

  for (int i = 2 * n; i >= 0; i--) {
    sufmin[i] = min(sufmin[i + 1], posb[i]);
  }
  int ans = 1e9;
  for (int i = 1; i <= 2 * n; i += 2) {
    ans = min(ans, posa[i] + sufmin[i]);
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
