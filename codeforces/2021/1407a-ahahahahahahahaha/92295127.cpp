#include <bits/stdc++.h>
using namespace std;

void solution() {
  int cnt[2] = {0, 0};
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  if (cnt[0] >= cnt[1]) {
    cout << n / 2 << '\n';
    for (int i = 0; i < n / 2; i++) cout << 0 << " ";
    cout << '\n';
  } else {
    cout << cnt[1] - cnt[1] % 2 << '\n';
    for (int i = 0; i < cnt[1] - cnt[1] % 2; i++) cout << 1 << " ";
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solution();
}
