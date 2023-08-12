#include <iostream>
using namespace std;
void solution() {
  int x, y;
  cin >> x >> y;
  if (x == 1 || y == 1 || (x == 2 && y == 2))
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
