#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  vector<int> a(4);
  int minn = INT_MAX;
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
    minn = min(a[i], minn);
  }
  cin >> a[3];
  int cnt = 0;
  for (auto e : a)
    if (e % 2 == 1) cnt++;
  if (minn == 0) {
    if (cnt > 1)
      cout << "No\n";
    else
      cout << "Yes\n";
    return;
  }
  if (cnt <= 1 || cnt >= 3)
    cout << "Yes\n";
  else
    cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
