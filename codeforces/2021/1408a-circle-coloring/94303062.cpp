#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  int prev = a[0], first = a[0];
  cout << first << " ";
  for (int i = 1; i < n - 1; i++) {
    if (a[i] != prev) {
      cout << a[i] << " ";
      prev = a[i];
    } else if (b[i] != prev) {
      cout << b[i] << " ";
      prev = b[i];
    } else if (c[i] != prev) {
      cout << c[i] << " ";
      prev = c[i];
    }
  }
  if (a[n - 1] != prev && a[n - 1] != first)
    cout << a[n - 1];
  else if (b[n - 1] != prev && b[n - 1] != first)
    cout << b[n - 1];
  else if (c[n - 1] != prev && c[n - 1] != first)
    cout << c[n - 1];
  cout << '\n';
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solution();
}
