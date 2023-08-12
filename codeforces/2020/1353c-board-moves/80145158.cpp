#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solution() {
  long long n, sum = 0;
  cin >> n;
  for (int i = n; i > 1; i -= 2) sum += ll(4) * (i - 1) * (i / 2);
  cout << sum << '\n';
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
