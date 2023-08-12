#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int const MOD = 1e9 + 7;

void solution() {
  int n, k;
  cin >> n >> k;
  ll ans = 1;
  for (int i = 0; i < k; i++) {
    ans *= n;
    ans %= MOD;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
