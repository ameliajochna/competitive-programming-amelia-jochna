#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solution() {
  vector<int> cnt(3);
  int j = 0, diff = 0;
  int best = INT_MAX;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    cnt[s[i] - 49]++;
    if (cnt[s[i] - 49] == 1) diff++;
    while (cnt[s[j] - 49] > 1) {
      cnt[s[j] - 49]--;
      j++;
    }
    if (diff == 3) best = min(i - j + 1, best);
  }
  if (best == INT_MAX)
    cout << 0 << '\n';
  else
    cout << best << '\n';
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
