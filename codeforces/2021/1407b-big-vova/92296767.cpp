#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<bool> taken(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int gcd = *max_element(a.begin(), a.end());
  for (int j = 0; j < n; j++) {
    int best = 1, index = 0;
    for (int i = 0; i < n; i++) {
      if (!taken[i] && __gcd(gcd, best) <= __gcd(gcd, a[i]))
        best = a[i], index = i;
    }
    taken[index] = true;
    cout << best << " ";
    gcd = __gcd(gcd, best);
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solution();
}
