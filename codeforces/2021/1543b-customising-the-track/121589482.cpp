#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  ll sum = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
  ll pertruck = sum / n;
  ll left = sum - pertruck * n;
  cout << (n - left) * left << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
