#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n / k >= m)
    cout << m << '\n';
  else
    cout << n / k - ((m - n / k - 1) / (k - 1) + 1) << '\n';
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
