#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    map<pair<int, int>, int> m;
    int cntk = 0, cntd = 0;
    for (auto x : s) {
      if (x == 'K')
        cntk++;
      else if (x == 'D')
        cntd++;
      int gcd = __gcd(cntk, cntd);
      cout << ++m[{cntk / gcd, cntd / gcd}] << ' ';
    }
    cout << '\n';
  }
}
