#include <bits/stdc++.h>
#define nd second
#define st first
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int const inf = 1e9;
void solution() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int prev = -inf, next = 0, cnt = 0;
  while (next < s.size() && s[next] == '0') next++;
  if (next == s.size()) next = inf;
  for (int i = 0; i < s.size(); i++) {
    if (next < i) {
      next++;
      while (next < s.size() && s[next] == '0') next++;
      if (next == s.size()) next = inf;
    }
    if (s[i] == '0') {
      if (i - prev > k && next - i > k) {
        s[i] = '1';
        cnt++;
        prev = i;
      }
    } else
      prev = i;
  }
  cout << cnt << "\n";
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
