#include <iostream>
using namespace std;

void solution() {
  int n, k;
  cin >> n >> k;
  if (n % 2 == 0)
    cout << n + k * 2 << '\n';
  else {
    int d;
    for (int i = 2; i <= n; i++)
      if (n % i == 0) {
        d = i;
        break;
      }
    cout << n + d + 2 * (k - 1) << '\n';
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
