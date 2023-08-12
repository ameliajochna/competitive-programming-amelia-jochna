#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, k;
  string s;
  int cnt[2] = {0, 0};
  cin >> n >> k >> s;
  for (int i = 0; i < k; i++) {
    int tmp = -1;
    for (int j = i; j < n; j += k) {
      if (s[j] == '?') continue;
      if (tmp != -1 && s[j] - '0' != tmp) {
        cout << "NO\n";
        return;
      }
      tmp = s[j] - '0';
    }
    if (tmp != -1) cnt[tmp]++;
  }
  // cout<<cnt[0]<<" "<<cnt[1]<<'\n';
  if (max(cnt[0], cnt[1]) > k / 2) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solution();
}
