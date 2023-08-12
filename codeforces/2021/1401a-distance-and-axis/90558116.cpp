#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, k;
  cin >> n >> k;
  if (n == 0)
    cout << k;
  else if (k == 0) {
    if (n % 2 == 0)
      cout << 0;
    else
      cout << 1;
  } else if (n == k)
    cout << 0;
  else if (n < k)
    cout << k - n;
  else if (n > k) {
    if (n % 2 == k % 2)
      cout << 0;
    else
      cout << 1;
  } else
    cout << 0;
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
