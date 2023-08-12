#include <iostream>
using namespace std;
int const maxN = 300000 + 10;
long long a[maxN], b[maxN];
void solution() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i] >> b[i];
  long long min_b = 1e18, ans = 0;
  for (long long i = 0; i < n; ++i) {
    b[i] = min(b[i], a[(i + 1) % n]);
    min_b = min(min_b, b[i]);
    ans += a[i] - b[i];
  }
  ans += min_b;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  long long t;
  cin >> t;
  while (t--) solution();
  return 0;
}
