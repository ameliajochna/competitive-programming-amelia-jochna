#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, k;
  cin >> n >> k;
  vector<int> a1(n), a2(n);
  cin >> a1[0];
  for (int i = 1; i < n; i++) {
    cin >> a1[i];
  }
  int ans = 1;
  while (true) {
    int curdiff = 1, cur = a1[0];
    bool change = false;
    for (int j = 1; j < n; j++) {
      if (a1[j] != a1[j - 1] && curdiff < k) {
        curdiff++;
        cur = a1[j];
        change = true;
      }
      a2[j] = a1[j] - cur;
    }
    bool cont = false;
    for (int i = 0; i < n; i++) {
      a1[i] = a2[i];
      if (a1[i] != 0) cont = true;
    }
    if (!change || !cont) break;
    ans++;
  }
  for (int i = 0; i < n; i++)
    if (a1[i] != 0) {
      cout << "-1\n";
      return;
    }
  cout << ans << '\n';
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solution();
}
