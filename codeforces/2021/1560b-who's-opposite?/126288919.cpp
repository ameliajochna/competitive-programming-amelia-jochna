#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) swap(a, b);
  int n = 2 * (b - a);
  if (c > n || a > n || b > n) {
    cout << "-1\n";
    return;
  }
  if (c > n / 2) {
    cout << c - n / 2 << '\n';
  } else {
    cout << c + n / 2 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
