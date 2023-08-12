#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  ll l, r;
  cin >> l >> r;
  if ((r + 2) / 2 < l)
    cout << r % l << '\n';
  else
    cout << r % ((r + 2) / 2) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
