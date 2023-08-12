#include <bits/stdc++.h>
using namespace std;
int n, m, q;
set<pair<int, int> > s;

void newrect(int x, int y) {
  auto it = s.find({x, y});
  if (it == s.end())
    s.insert({x, y});
  else
    s.erase(it);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    newrect(x2, y2);
    if (x1 == 1 && y1 == 1) {
      cout << s.size() << '\n';
      continue;
    } else if (x1 == 1)
      newrect(x2, y1 - 1);
    else if (y1 == 1)
      newrect(x1 - 1, y2);
    else {
      newrect(x2, y1 - 1);
      newrect(x1 - 1, y2);
      newrect(x1 - 1, y1 - 1);
    }
    cout << s.size() << '\n';
  }
}
