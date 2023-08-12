#include <iostream>
using namespace std;

void solution() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  if (n * (a + b) >= c - d && n * (a - b) <= c + d)
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
}
