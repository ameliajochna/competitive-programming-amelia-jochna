#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> min, plus;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
    if (a >= 0)
      plus.push_back(a);
    else
      min.push_back(a);
  }
  if (sum == 0) {
    cout << "NO\n";
    return;
  }
  if (sum > 0) {
    sort(plus.begin(), plus.end());
    reverse(plus.begin(), plus.end());
    cout << "YES\n";
    for (auto a : plus) cout << a << " ";
    for (auto a : min) cout << a << " ";
  } else {
    sort(plus.begin(), plus.end());
    reverse(plus.begin(), plus.end());
    cout << "YES\n";
    for (auto a : min) cout << a << " ";
    for (auto a : plus) cout << a << " ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
