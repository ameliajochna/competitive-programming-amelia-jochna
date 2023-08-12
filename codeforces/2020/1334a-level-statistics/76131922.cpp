#include <iostream>
using namespace std;

void solution() {
  int n, a, b, preva, prevb;
  bool correct = true;
  cin >> n;
  preva = 0;
  prevb = 0;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (correct) {
      if (preva > a || prevb > b || (preva == a && b > prevb) ||
          a - preva < b - prevb) {
        correct = false;
      }
    }
    preva = a;
    prevb = b;
  }
  if (correct)
    cout << "YES\n";
  else
    cout << "NO\n";
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
