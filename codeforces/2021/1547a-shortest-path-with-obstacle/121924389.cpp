#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  pii a, b, f;
  cin >> a.st >> a.nd >> b.st >> b.nd >> f.st >> f.nd;
  if (a.st == b.st) {
    if (f.st == a.st && f.nd > min(a.nd, b.nd) && f.nd < max(a.nd, b.nd))
      cout << abs(b.nd - a.nd) + 2 << '\n';
    else
      cout << abs(b.nd - a.nd) << '\n';
  } else if (a.nd == b.nd) {
    if (f.nd == a.nd && f.st > min(a.st, b.st) && f.st < max(a.st, b.st))
      cout << abs(b.st - a.st) + 2 << '\n';
    else
      cout << abs(b.st - a.st) << '\n';
  } else
    cout << abs(b.nd - a.nd) + abs(b.st - a.st) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
