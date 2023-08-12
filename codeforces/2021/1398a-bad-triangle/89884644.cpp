#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int b = 0, c = 1, d = n - 1;
  if (a[b] + a[c] <= a[d])
    cout << b + 1 << " " << c + 1 << " " << d + 1 << '\n';
  else
    cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
