#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  bool lt0 = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) lt0 = true;
  }
  if (lt0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  cout << "101\n";
  for (int i = 0; i <= 100; i++) {
    cout << i << " ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solution();
}
