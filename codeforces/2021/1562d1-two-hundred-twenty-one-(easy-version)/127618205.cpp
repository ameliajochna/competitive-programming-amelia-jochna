#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n, q;
  cin >> n >> q;
  vector<int> pref(n + 1);
  int cur = 1;
  for (int i = 1; i <= n; i++) {
    char c;
    int tmp;
    cin >> c;
    if (c == '+')
      tmp = 1;
    else
      tmp = -1;
    pref[i] = pref[i - 1] + (tmp * cur);
    cur *= (-1);
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int bal = abs(pref[r] - pref[l - 1]);
    if (bal == 0)
      cout << "0\n";
    else if ((r - l + 1) % 2 == 0)
      cout << "2\n";
    else
      cout << "1\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
