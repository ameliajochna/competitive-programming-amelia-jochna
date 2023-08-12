#include <iostream>
using namespace std;
void solution() {
  long long x, y, a, b;
  cin >> x >> y;
  cin >> a >> b;
  if (x > y) swap(x, y);
  long long case1 = a * (y - x) + b * x;
  long long case2 = a * (x + y);
  if (case1 > case2)
    cout << case2 << '\n';
  else
    cout << case1 << '\n';
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
