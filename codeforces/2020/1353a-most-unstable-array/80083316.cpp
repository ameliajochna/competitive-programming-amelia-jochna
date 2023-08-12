#include <iostream>
using namespace std;

void solution() {
  int n, m;
  cin >> n >> m;
  if (n <= 1)
    cout << 0 << '\n';
  else if (n == 2)
    cout << m << "\n";
  else
    cout << 2 * m << '\n';
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
