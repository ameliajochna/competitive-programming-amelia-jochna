#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt[2] = {0, 0};
  for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i] % 2]++;
  if (cnt[0] % 2 == 0 && cnt[1] % 2 == 0)
    cout << "YES\n";
  else {
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++)
      if (a[i + 1] - a[i] == 1) {
        cout << "YES\n";
        return;
      }
    cout << "NO\n";
  }
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
