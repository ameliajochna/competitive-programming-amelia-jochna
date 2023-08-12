#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  int _max = max(max(a, b), c);
  int min_pos;
  if (a == _max)
    min_pos = _max - b - c - 1;
  else if (b == _max)
    min_pos = _max - a - c - 1;
  else
    min_pos = _max - a - b - 1;

  int max_pos = max(a - 1, 0) + max(b - 1, 0) + max(c - 1, 0);
  if (m >= min_pos && m <= max_pos)
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
}
