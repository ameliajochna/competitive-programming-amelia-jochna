#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> ans;
  int power = 1;
  while (n > 0) {
    while (n % 10 == 0) {
      n = n / 10;
      power *= 10;
    }
    ans.push_back((n % 10) * power);
    n /= 10;
    power *= 10;
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t, sum = 0;
  cin >> t;
  while (t--) solve();

  return 0;
}
