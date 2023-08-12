#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void solution() {
  set<pair<pii, pii> > s;
  string path;
  int x = 0, y = 0, px, py, sum = 0;
  cin >> path;
  for (int i = 0; i < path.size(); i++) {
    char a = path[i];
    px = x, py = y;
    if (a == 'S')
      x++;
    else if (a == 'W')
      y++;
    else if (a == 'N')
      x--;
    else if (a == 'E')
      y--;
    pii start = {px, py};
    pii end = {x, y};
    if (start > end) swap(start, end);
    if (s.count({start, end}) > 0)
      sum++;
    else
      sum += 5;
    s.insert({start, end});
  }
  cout << sum << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
