#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solution() {
  int n;
  cin >> n;
  if (n <= 3) {
    cout << -1 << '\n';
    return;
  }
  int add = (n % 2 == 0 ? 1 : 0);
  for (int i = n - add; i > 0; i -= 2) cout << i << " ";
  cout << 4 << " " << 2 << " ";
  for (int i = 6; i <= n; i += 2) cout << i << " ";
  cout << '\n';
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
