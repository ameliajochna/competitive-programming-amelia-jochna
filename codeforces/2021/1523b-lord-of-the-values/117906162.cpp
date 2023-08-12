#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<ll> v(n);

  for (int i = 0; i < n; i++) cin >> v[i];
  cout << ((n + 1) / 2) * 6 << '\n';
  for (int i = 1; i < n; i += 2) {
    cout << 1 << " " << i << " " << i + 1 << '\n';
    cout << 2 << " " << i << " " << i + 1 << '\n';
    cout << 2 << " " << i << " " << i + 1 << '\n';
    cout << 1 << " " << i << " " << i + 1 << '\n';
    cout << 2 << " " << i << " " << i + 1 << '\n';
    cout << 2 << " " << i << " " << i + 1 << '\n';
  }
  if (n % 2 == 1) {
    cout << 1 << " " << n - 1 << " " << n << '\n';
    cout << 2 << " " << n - 1 << " " << n << '\n';
    cout << 2 << " " << n - 1 << " " << n << '\n';
    cout << 1 << " " << n - 1 << " " << n << '\n';
    cout << 2 << " " << n - 1 << " " << n << '\n';
    cout << 2 << " " << n - 1 << " " << n << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solution();
}
