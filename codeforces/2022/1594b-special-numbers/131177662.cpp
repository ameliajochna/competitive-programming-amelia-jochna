#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
using namespace std;
typedef long long ll;

void solution() {
  int n, k;
  cin >> n >> k;
  vector<int> bn;
  while (k) {
    bn.push_back(k % 2);
    k /= 2;
  }
  ll cur = 1, sum = 0, MOD = 1e9 + 7;
  for (int i = 0; i < sz(bn); i++) {
    // cout<<bn[i]<<" ";
    sum += (cur * bn[i]);
    sum %= MOD;
    cur *= n;
    cur %= MOD;
  }
  cout << sum << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
