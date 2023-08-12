#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
typedef long double ld;
int const shift = (1 << 19);
vector<int> a;
int segTree[2 * shift], n;

void update(int u, int val) {
  u += shift;
  segTree[u] = val;
  while (u) {
    u /= 2;
    segTree[u] = __gcd(segTree[2 * u], segTree[2 * u + 1]);
  }
}

int query(int l, int r) {
  l += shift, r += shift;
  int ans = segTree[l];
  ans = __gcd(ans, segTree[r]);
  while (l / 2 != r / 2) {
    if (r % 2 == 1) ans = __gcd(ans, segTree[r - 1]);
    if (l % 2 == 0) ans = __gcd(ans, segTree[l + 1]);
    r /= 2, l /= 2;
  }
  return ans;
}

bool check(int k) {
  // cout<<"SPRAWDZ K:"<<k<<'\n';
  for (int i = 0; i < n; i++) {
    // cout<<i<<" "<<i+k<<": "<<query(i, i+k)<<'\n';
    if (query(i, i + k) != 1) {
      return false;
    }
  }
  return true;
}

int binary_search() {
  int l = 0, r = n - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (check(l)) return l;
  return r;
}

void solution() {
  cin >> n;
  a.clear();
  a.resize(2 * n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int gcd = a[0];
  for (int i = 0; i < n; i++) gcd = __gcd(a[i], gcd);

  for (int i = 0; i < n; i++) a[i] /= gcd;

  for (int i = n; i < 2 * n; i++) a[i] = a[i - n];

  for (int i = 0; i < 2 * n; i++) update(i, a[i]);
  /*for(int i=1; i<4*n; i++){
      cout<<i<<" "<<segTree[i]<<'\n';
     }*/
  cout << binary_search() << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
