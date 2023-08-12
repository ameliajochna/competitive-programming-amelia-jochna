#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, n)          \
  for (int i = a; i < n; i++) \
    ;
typedef long long ll;
typedef pair<int, int> pii;

void solution() {
  ll a, b;
  cin >> a >> b;  // a<b
  if (a > b) swap(a, b);
  if (b % a != 0)
    cout << "-1" << '\n';
  else if (a == b)
    cout << '0' << '\n';
  else {
    b = b / a;
    ll counter = 0, ans = 0;
    while (b > 1 && b % 2 == 0) {
      b /= 2;
      counter++;
    }
    if (b != 1) {
      cout << "-1\n";
      return;
    }
    if (counter >= 3) {
      ans += counter / 3;
      counter -= ans * 3;
    }
    if (counter >= 2) {
      int tmp = counter / 2;
      ans += tmp;
      counter -= tmp * 2;
    }
    ans += counter;
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
