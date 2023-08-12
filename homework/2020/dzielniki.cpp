#include <iostream>
using namespace std;
typedef long long ll;
int const maxN = 2e6 + 10;
int count[maxN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int n, maxval = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    count[e]++;
    if (e > maxval) maxval = e;
  }
  long long sum = 0;
  for (int i = 1; i <= maxval; i++) {
    sum += (ll(count[i]) * ll(count[i] - 1));
    if (count[i] != 0) {
      for (int j = 2; i * j <= maxval; j++) {
        sum += ll(count[i]) * ll(count[i * j]);
      }
    }
  }
  cout << sum << '\n';
  return 0;
}
