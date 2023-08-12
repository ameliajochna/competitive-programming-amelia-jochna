#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solution() {
  int n;
  cin >> n;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (int(sqrt(tmp)) * int(sqrt(tmp)) != tmp) ok = true;
  }
  if (ok)
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
