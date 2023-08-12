#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n, k;
  cin >> n >> k;
  long long suma = 0, sumb = 0;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    suma += a[i];
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int i = 0, j = n - 1;
  k = min(n, k);
  while (a[i] < b[j] && k > 0) {
    suma -= a[i];
    suma += b[j];
    i++;
    j--;
    k--;
  }
  cout << suma << "\n";
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
