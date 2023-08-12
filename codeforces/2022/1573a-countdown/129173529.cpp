#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  int pos = 0;
  for (int i = 0; i < s.size(); i++) {
    cnt += s[i] - '0';
    if (s[i] != '0') pos++;
  }
  cnt += pos - (s[s.size() - 1] != '0');
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
