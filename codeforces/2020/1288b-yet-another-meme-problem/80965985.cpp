#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  int A, B;
  cin >> A >> B;
  ll b = 0, cnt = -1;
  while (b <= B) {
    cnt++;
    b *= 10, b += 9;
  }
  cout << ll(A * cnt) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
