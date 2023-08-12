#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int a[2][2];
    for (int j = 0; j < 2; j++)
      for (int q = 0; q < 2; q++) cin >> a[j][q];
    if (a[1][0] == a[0][1]) cnt++;
  }
  if (m % 2 == 1)
    cout << "NO\n";
  else if (cnt >= 1)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
