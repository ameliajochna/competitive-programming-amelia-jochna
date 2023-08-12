#include <bits/stdc++.h>
#define FOR(i, n)             \
  for (int i = 0; i < n; i++) \
    ;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solution() {
  long long n, sum = 0;
  cin >> n;
  while (n) {
    sum += n;
    n /= 2;
  }
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
