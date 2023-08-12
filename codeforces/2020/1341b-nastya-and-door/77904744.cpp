#include <bits/stdc++.h>
using namespace std;
int const maxN = 2e5;
void solution() {
  int n, k, maxcnt = 0, cnt = 0, maxl = 0;
  cin >> n >> k;
  vector<int> mnt(n);
  for (int i = 0; i < n; i++) cin >> mnt[i];
  for (int i = 1; i < k - 1; i++)
    if (mnt[i - 1] < mnt[i] && mnt[i + 1] < mnt[i]) cnt++;
  maxcnt = cnt;
  for (int i = 1; i <= n - k; i++) {
    if (mnt[i - 1] < mnt[i] && mnt[i + 1] < mnt[i]) cnt--;
    if (mnt[i + k - 3] < mnt[i + k - 2] && mnt[i + k - 2] > mnt[i + k - 1])
      cnt++;
    if (maxcnt < cnt) {
      maxcnt = cnt;
      maxl = i;
    }
  }
  cout << maxcnt + 1 << " " << maxl + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
