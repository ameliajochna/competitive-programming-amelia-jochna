#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
typedef pair<int, int> pii;

int const maxM = 2010;

int m, p, n;
int food[maxM][maxM], head[maxM][maxM], t;
bool smth[maxM][maxM];
deque<pii> dq;
vector<int> eaten;
pii pos;

void move(char dir) {
  pii chg;
  if (dir == 'P')
    chg = {0, 1};
  else if (dir == 'L')
    chg = {0, -1};
  else if (dir == 'G')
    chg = {-1, 0};
  else if (dir == 'D')
    chg = {1, 0};
  pii tmp = {pos.st + chg.st, pos.nd + chg.nd};

  if (smth[tmp.st][tmp.nd]) {  // waz zjada
    eaten.push_back(food[tmp.st][tmp.nd]);
    smth[tmp.st][tmp.nd] = false;
  } else {
    pii rmv = dq.back();
    head[rmv.st][rmv.nd] = 0;
    dq.pop_back();
  }
  pos = tmp;
  dq.push_front(pos);
  head[pos.st][pos.nd] = t;
}

int query(int x, int y) {
  if (head[x][y] == 0) return -1;
  int tmp = head[x][y];

  int sz = (int)eaten.size();
  return eaten[sz - t + tmp];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();

  cin >> m >> p >> n;
  for (int i = 0; i < p; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    food[x][y] = c;
    smth[x][y] = true;
  }

  pos = {1, 1};
  dq.push_front(pos);
  eaten.push_back(0);
  head[1][1] = 1;
  t = 2;
  for (int i = 0; i < n; i++) {
    char type;
    cin >> type;
    if (type == 'Z') {
      int x, y;
      cin >> x >> y;
      cout << query(x, y) << '\n';
    } else {
      move(type);
      t++;
    }
  }
  return 0;
}
