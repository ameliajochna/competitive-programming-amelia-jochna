#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
typedef long double ld;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.begin(), b.end());
  map<int, pair<int, int> > m;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      m[a[i]].st++;
    } else
      m[a[i]].nd++;
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      m[b[i]].st--;
    else
      m[b[i]].nd--;
  }
  for (auto x : m) {
    if (x.nd.st != 0 || x.nd.nd != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
