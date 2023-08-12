#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
using namespace std;
typedef long long ll;
int const maxN = 11, maxM = 19;
bool f[maxN][maxM];
bool cnt[maxN][maxM];

void solution() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool bln = false;
      char c;
      cin >> c;
      if (c == '*') bln = true;
      f[i][j] = bln;
      cnt[i][j] = false;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!f[i][j]) continue;

      pii pos1 = {i - 1, j - 1}, pos2 = {i - 1, j + 1};
      pii s1 = pos1, s2 = pos2;
      int len = 0;
      while (pos1.st >= 0 && pos1.nd >= 0 && pos2.st >= 0 && pos2.nd < m &&
             f[pos1.st][pos1.nd] && f[pos2.st][pos2.nd]) {
        len++;
        pos1.st--;
        pos1.nd--;
        pos2.st--;
        pos2.nd++;
      }
      // cout<<"START: "<<i<<" "<<j<<'\n';
      // cout<<pos1.st<<" "<<pos1.nd<<"\n";
      // cout<<pos2.st<<" "<<pos2.nd<<'\n';
      // cout<<"LEN: "<<len<<'\n';
      if (len >= k) {
        cnt[i][j] = true;
        while (s1.st >= 0 && s1.nd >= 0 && s2.st >= 0 && s2.nd < m &&
               f[s1.st][s1.nd] && f[s2.st][s2.nd]) {
          cnt[s1.st][s1.nd] = true;
          cnt[s2.st][s2.nd] = true;
          s1.st--;
          s1.nd--;
          s2.st--;
          s2.nd++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (f[i][j] && !cnt[i][j]) {
        cout << "NO\n";
        return;
      }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
/*
   1
   3 3 2
 *.*
   .*.
   ...

 */
