#include <iostream>
using namespace std;
typedef long long ll;
void solution() {
  ll a, b, c;
  cin >> a >> b >> c;
  if (a >= c)
    cout << "-1 ";
  else
    cout << 1 << " ";
  if (b * a > c)
    cout << b << " ";
  else
    cout << -1 << " ";
  cout << '\n';
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
