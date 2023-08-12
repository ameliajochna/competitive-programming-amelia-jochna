#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n), cnt(105);
  for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
  int used = 0, mex = 0, j = 0;
  for (int i = 0; i < 105; i++) {
    if (cnt[i] > 0)
      mex = i + 1;
    else
      break;
  }
  for (int i = 0; i < 101; i++) {
    if (cnt[i] < 2) {
      mex += i;
      break;
    }
  }
  cout << mex << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
