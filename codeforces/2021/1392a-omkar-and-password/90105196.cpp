#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, a;
  cin >> n;
  cin >> a;
  int ans = n;
  for (int i = 1; i < n; i++) {
    int e;
    cin >> e;
    // cout<<a<<" "<<e<<'\n';
    if (e != a) {
      ans = 1;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
