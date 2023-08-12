#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;

void solution() {
  ll a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "0 0\n";
    return;
  }
  ll diff = abs(a - b);
  if (diff <= __gcd(a, b)) {
    cout << __gcd(a, b) << " "
         << "0\n";
  } else
    cout << diff << " " << min(a % diff, diff - a % diff) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
