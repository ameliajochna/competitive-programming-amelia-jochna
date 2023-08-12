#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solution() {
  int a, b, c, cnt = 0;
  cin >> a >> b >> c;
  if (a < b) swap(a, b);  // a>=b
  while (a <= c) {
    // cout<<a<<" "<<b<<'\n';
    b += a;
    if (a < b) swap(a, b);
    cnt++;
  }
  cout << cnt << '\n';
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
