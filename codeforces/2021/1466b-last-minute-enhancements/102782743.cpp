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
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    m[tmp]++;
  }
  int cnt = 0;
  for (auto x : m) {
    cnt++;
    if (x.nd > 1) m[x.st + 1]++;
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
