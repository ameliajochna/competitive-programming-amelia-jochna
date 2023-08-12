#include <bits/stdc++.h>
using namespace std;

void solution() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (min({a, b}) + min({d, c}) == max({a, b}) && max({a, b}) == max({d, c}))
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
  return 0;
}
