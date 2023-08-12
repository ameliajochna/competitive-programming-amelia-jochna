#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int mina = a[0];
  for (int i = n - 2; i >= 0 && k > 0; i--) {
    if (a[i] > 0) {
      a[n - 1] += a[i], a[i] = 0, k--;
      mina = 0;
    }
  }
  cout << a[n - 1] - mina << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
