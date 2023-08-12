#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 0; i < 32; i++) {
    int cur = (1 << i);
    if (!(n & cur) && m & cur) ans |= cur;
  }
  // cout<<ans<<'\n';
  if ((n ^ ans) == m) {
    // max na najmniej znaczacej
    for (int i = 0; i < 32; i++) {
      int cur = (1 << i);
      if ((n ^ (ans | cur)) > m) {
        ans |= cur;
        break;
      }
    }
  }
  // cout<<ans<<'\n';
  for (int i = 31; i >= 0; i--) {
    int cur = (1 << i);
    if (ans & cur) {
      // czy jak sie zmieni tam na 0 to czy zostanie ta wlasciwosc
      if ((n ^ (ans ^ cur)) > m) ans ^= cur;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}

/*

   6
   2 aa
   3 aba
   3 aaa
   6 abaaba
   5 aaaaa
   4 abba

 */
