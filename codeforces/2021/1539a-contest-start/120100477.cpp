#include <bits/stdc++.h>
#define nd second
#define st first
using namespace std;
typedef long long ll;
int const maxN = 5e5 + 10, INF = 1e9;

void solution() {
  ll n, x, t;
  cin >> n >> x >> t;
  ll div = t / x, add = 0;
  if (div >= n)
    cout << ((n - 1) * n) / 2 << '\n';
  else
    cout << div * (n - div - 1) + div * (div + 1) / 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solution();
}
