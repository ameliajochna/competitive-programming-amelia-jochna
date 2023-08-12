#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
typedef long long ll;

void solution() {
  ll n, k;
  cin >> n >> k;
  vector<ll> pref(n + 2);
  for (int i = 1; i <= n; i++) {
    ll tmp;
    cin >> tmp;
    pref[i] = pref[i - 1] + tmp;
  }
  for (int i = 0; i < k; i++) {
    ll tmp;
    cin >> tmp;
    ll l = 0, r = n;
    while (r - l > 1) {
      ll mid = (l + r) / 2;
      (pref[mid] >= tmp ? r : l) = mid;
    }
    // cout<<l<<" "<<r<<" "<<pref[l]<<" "<<pref[r]<<"\n";
    ll ans = (pref[r] < tmp ? r : l);
    // cout<<ans<<"\n";
    cout << ans + 1 << " " << tmp - pref[ans] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  // cin>>t;
  while (t--) solution();
  return 0;
}
