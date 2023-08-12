#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<bool> ex(55);
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ex[a[j] - a[i]] = true;
    }
  }
  int cnt = 0;
  for (auto a : ex) {
    if (a) cnt++;
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
