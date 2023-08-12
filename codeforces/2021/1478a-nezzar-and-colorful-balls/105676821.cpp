#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define ll long long

void solution() {
  int n;
  cin >> n;
  vector<int> cnt(n + 5);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    cnt[tmp]++;
    ans = max(ans, cnt[tmp]);
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
  return 0;
}
