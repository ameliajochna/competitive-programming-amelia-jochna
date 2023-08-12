#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, x;
  cin >> n >> x;
  if (n <= 2) {
    cout << 1 << "\n";
    return;
  }
  cout << ((n - 3) / x + 2) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
