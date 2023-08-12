#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  ll n;
  cin >> n;
  ll k = n + 2, sum = 0;
  vector<int> v(k);
  for (int i = 0; i < k; i++) {
    cin >> v[i];
    sum += v[i];
  }

  pair<ll, ll> maxval[2];
  maxval[0] = {0, 0};
  maxval[1] = {0, 0};
  for (int i = 0; i < k; i++)
    if (v[i] > maxval[0].first) maxval[0] = {v[i], i};
  for (int i = 0; i < k; i++)
    if (v[i] > maxval[1].first && i != maxval[0].second) maxval[1] = {v[i], i};

  // cout<<maxval[0].first<<" "<<maxval[0].second<<'\n';
  // cout<<maxval[1].first<<" "<<maxval[1].second<<'\n';
  for (int i = 0; i < k; i++) {
    ll cursum = sum - v[i];
    ll locmaxv, locind;
    if (maxval[0].second == i)
      locmaxv = maxval[1].first, locind = maxval[1].second;
    else
      locmaxv = maxval[0].first, locind = maxval[0].second;
    cursum -= locmaxv;
    // cout<<i<<" "<<locmaxv<<" "<<locind<<" "<<cursum<<'\n';
    if (locmaxv == cursum) {
      for (int j = 0; j < k; j++) {
        if (j != i && j != locind) cout << v[j] << " ";
      }
      cout << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
