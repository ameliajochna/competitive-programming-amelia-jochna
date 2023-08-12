#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int k;
  cin >> k;
  int lim = 0;
  for (int i = 1; i <= k; i++) {
    if (i * i > k) break;
    lim = i;
  }
  k -= lim * lim;
  if (k == 0) {
    cout << lim << " " << 1 << '\n';
  } else if (k <= lim + 1) {
    cout << k << " " << lim + 1 << "\n";
  } else {
    k -= lim + 1;
    cout << lim + 1 << " " << lim - k + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
