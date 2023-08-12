#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  ll maxans = 0;
  for (int i = 0; i < n - 1; i++) {
    maxans = max(maxans, ll(v[i]) * v[i + 1]);
  }
  for (int i = n - 1; i > 0; i--) maxans = max(maxans, ll(v[i]) * v[i - 1]);
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
