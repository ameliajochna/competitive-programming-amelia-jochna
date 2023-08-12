#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll maxans = -1e18;
  for (int i = max(n - 101, 0); i < n; i++) {
    for (int j = max(n - 101, 0); j < n; j++) {
      if (i == j) continue;
      ll cur = ll(i + 1) * (j + 1) - k * (a[i] | a[j]);
      maxans = max(maxans, cur);
    }
  }
  cout << maxans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
/*Ŕ

   6
   2 aa
   3 aba
   3 aaa
   6 abaaba
   5 aaaaa
   4 abba

 */
