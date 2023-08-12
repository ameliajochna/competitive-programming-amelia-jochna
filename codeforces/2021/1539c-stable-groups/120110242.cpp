#include <bits/stdc++.h>
#define nd second
#define st first
using namespace std;
typedef long long ll;

void solution() {
  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  ll grpcnt = 1;
  vector<ll> v;
  for (int i = 0; i < n - 1; i++) {
    ll subs = a[i + 1] - a[i];
    if (subs > x) v.push_back(subs / x - (subs % x == 0)), grpcnt++;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++)
    if (k >= v[i]) k -= v[i], grpcnt--;
  cout << grpcnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solution();
}
