#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef __int128_t bint;
typedef long long ll;

struct F {
  bint a, b;
  F(bint a = 0, bint b = 1) : a(a), b(b) {}
  void reduce() {
    bint tmp = __gcd(a, b);
    a = a / tmp, b = b / tmp;
  }
  bool operator>=(const F &x) const { return a * x.b >= x.a * b; }
  bool operator<=(const F &x) const { return a * x.b <= x.a * b; }
  bool operator>(const F &x) const { return a * x.b > x.a * b; }
  bool operator==(const F &x) const { return (a == x.a && b == x.b); }
};

const F operator+(const F &x, const F &y) {
  bint a1 = x.a, b1 = x.b, a2 = y.a, b2 = y.b;
  F add = F(a1 * b2 + a2 * b1, b1 * b2);
  add.reduce();
  return add;
}

const F operator-(const F &x, const F &y) { return x + F(-y.a, y.b); }

const F operator/(const F &x, const F &y) { return F(x.a * y.b, y.a * x.b); }

const F operator*(const F &x, const F &y) { return F(x.a * y.a, x.b * y.b); }

bool operator<(const F &x, const F &y) {
  return (y.b == 0 || x.a * y.b < x.b * y.a);
}

int const maxN = (int)1e5 + 10;

int n, d[maxN], lst[maxN], fst[maxN], ans, pt;
F pos[maxN], tpos[maxN], ot[maxN];
F speed[maxN], tohit[maxN], postime[maxN];
bool washit[maxN];  // w jakim czasie 0 "wjedzie" w i-ty
set<pair<F, int> > hitorder;

inline F calcposition(F const &t, int const &i) {
  return pos[i] + (t - tpos[i]) * speed[i];
}

inline void updateposition(F const &t, int const &i) {
  pos[i] = calcposition(t, i);
  tpos[i] = t;
}

F timetohit(
    int const &i1, int const &i2,
    F const &t) {  // ile potrzeba czasu zeby i1 zderzylo sie z i2 liczac od t
  F p1 = calcposition(t, i1), p2 = calcposition(t, i2);
  F s = p2 - F(d[i2]) - p1;
  if (s == 0 &&
      (postime[i1].a != 0 || (postime[i1] == 0 && speed[i1] >= speed[i2])))
    return F(0);

  if (s <= 0 || speed[i1] <= speed[i2])  // nie zderza sie nigdy
    return F(0, 0);

  F v = speed[i1] - speed[i2];
  return s / v;
}

F timetoovertake(int const &i) {
  F pos0 = speed[0] * tpos[i];
  if (pos0 > pos[i]) return F(-1, 0);
  if (speed[i] >= speed[0]) return F(0, 0);
  F s = pos[i] - F(d[i]) - pos0, v = speed[0] - speed[i];
  return s / v;
}

void fill() {
  for (int i = 1; i <= n; i++) lst[i] = i, fst[i] = i;
  for (int i = 1; i <= n; i++) ot[i] = timetoovertake(i);
  for (int i = 1; i < n; i++) {
    tohit[i] = timetohit(i, i + 1, F(0));
    if (tohit[i].b != 0) hitorder.insert({tohit[i], i});
  }
}

void hit(F const &t, int const &i) {
  int nxt = fst[i + 1];
  washit[i + 1] = true;
  int beg = lst[i];
  lst[nxt] = beg;
  lst[i + 1] = beg;
  fst[beg] = nxt;

  updateposition(t, beg);
  speed[beg] = speed[i + 1];

  if (!washit[beg]) {
    F tmp = timetoovertake(beg);
    if (tmp.b == 0)
      ot[beg] = tmp;
    else
      ot[beg] = t + tmp;
  }

  if (beg == 1) return;

  int prev = beg - 1;

  auto tmp = hitorder.find({tohit[prev], prev});
  if (tmp != hitorder.end()) hitorder.erase(tmp);

  auto tth = timetohit(prev, beg, t);

  if (tth.b != 0) {
    tohit[prev] = t + tth;
    hitorder.insert({tohit[prev], prev});
  }
}

bool overtake(F const &t, int const &i) {  // autko wyprzedza i-te auto
  if (washit[i] || t.b == 0) return false;
  F p1 = calcposition(t, i - 1), p2 = calcposition(t, i);
  F dist = p2 - p1;
  return (dist >= F(d[0] + d[i]) || i == 1);
}

void passing() {
  ans += overtake(ot[pt], pt);
  pt++;
}

void collision() {
  F t = (*hitorder.begin()).st;
  int ind = (*hitorder.begin()).nd;
  hitorder.erase(hitorder.begin());
  hit(t, ind);
}

int calcans() {
  fill();

  pt = 1;
  while (pt <= n) {  // zderzenie czy wyprzedzanie???
    F curot = ot[pt];
    if (hitorder.empty())
      passing();
    else {
      if (curot.a == -1 || washit[pt])
        pt++;
      else if (curot.a == 0 && curot.b == 0)
        collision();
      else if (curot.a == 0 && curot.b == 1)
        passing();
      else {
        F settop = (*hitorder.begin()).st;
        if (settop <= curot)
          collision();
        else if (curot < settop)
          passing();
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int a, b;
  cin >> n >> d[0] >> a >> b;
  speed[0].a = a;
  speed[0].b = b;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p >> d[i] >> a >> b;
    pos[i].a = p;
    speed[i].a = a;
    speed[i].b = b;
  }
  cout << calcans();
  return 0;
}
