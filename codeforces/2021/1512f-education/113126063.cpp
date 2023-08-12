#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, cost;
  cin >> n >> cost;
  vector<ll> a(n), b(n - 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) cin >> b[i];
  ll cur = 0, dayscnt = 0;
  ll bestans = 1e9;
  for (int i = 0; i < n;
       i++) {  // zakladam ze ostatnie stanowisko na ktorym skoncze to i-te
    // ile dni zeby kupic komputer na aktualnym stanowisku
    ll cnt = ceil(double(cost - cur) / a[i]);
    // cout<<"na stanowisku "<<i<<": "<<cnt<<'\n';
    // porownanie odp
    bestans = min(bestans, dayscnt + cnt);

    // przejscie na nastepne stanowisko
    ll tw = max(0LL, ll(ceil(double(b[i] - cur) / a[i])));
    dayscnt += tw + 1;
    ll all = tw * a[i];
    // cout<<tw<<" "<<a[i]<<" "<<all<<'\n';
    cur = (all + cur - b[i]);
    // cout<<"przejscie! "<<i<<" -> "<<i+1<<" dni: "<<tw+1<<" suma:
    // "<<dayscnt<<" dobytek: "<<cur<<'\n';
  }
  cout << bestans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
