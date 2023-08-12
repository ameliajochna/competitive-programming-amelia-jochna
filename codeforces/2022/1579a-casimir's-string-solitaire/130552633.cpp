#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
using namespace std;
typedef long long ll;

void solution() {
  string s;
  cin >> s;
  vector<int> cnt(3);
  for (auto x : s) {
    cnt[x - 'A']++;
  }
  if (cnt[0] + cnt[2] == cnt[1]) {
    cout << "YES\n";
  } else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
