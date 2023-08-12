#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  string s;
  int n;
  cin >> n;
  cin >> s;
  string s1 = s;
  sort(s1.begin(), s1.end());
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != s1[i]) cnt++;
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
