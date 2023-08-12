#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
#define pb push_back
using namespace std;
typedef long long ll;

void solve() {
  int n;
  string s1, s2;
  cin >> n;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    int v1 = s1[i] - '0', v2 = s2[i] - '0';
    if (v1 == 1 && v2 == 1) {
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
  while (t--) solve();
}
