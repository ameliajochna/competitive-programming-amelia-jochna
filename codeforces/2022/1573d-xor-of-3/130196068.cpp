#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;
set<pair<int, int> > s;
map<int, int> m;
vector<int> v, seq;
int n;

void fix(pair<int, int> p) {
  int a = p.st, b = p.nd;
  if (a - 1 >= 0 && v[a - 1] == 1) {
    int cur = a - 1;
    if (m.find(cur) != m.end()) {
      int u = cur, v = m[cur];
      m.erase(u);
      m.erase(v);
      if (u > v) swap(u, v);
      s.insert({u, v});
    }
  }
  if (b + 1 < n && v[b + 1] == 1) {
    int cur = b + 1;
    if (m.find(cur) != m.end()) {
      int u = cur, v = m[cur];
      m.erase(u);
      m.erase(v);
      if (u > v) swap(u, v);
      s.insert({u, v});
    }
  }
}

void change_to_zero(pair<int, int> p) {
  int a = p.st, b = p.nd;
  if (a == b - 1) {  // 011 or 110
    if (a - 1 >= 0 && v[a - 1] == 0)
      seq.push_back(a - 1);  // 011
    else
      seq.push_back(a);  // 110
    return;
  }
  if (a == b - 2) {  // 101
    seq.push_back(a);
    return;
  }
  if ((b - a) % 2 == 0) {
    int cur = a;
    while (cur != b) {
      seq.push_back(cur);
      cur += 2;
    }
    cur -= 2;
    while (cur != a) {
      cur -= 2;
      seq.push_back(cur);
    }
    return;
  }

  // ogolna sytuacja: 10...01
  if (a - 1 >= 0 &&
      v[a - 1] == 0) {  // 010...01 -> przesuwamy od lewej do prawej
    int cur = a;
    while (v[cur + 1] == 0 && v[cur + 2] == 0) {
      seq.push_back(cur);
      seq.push_back(cur - 1);
      cur += 2;
    }
    if (cur == b - 1)
      seq.push_back(cur - 1);
    else if (cur == b - 2)
      seq.push_back(cur);
    return;
  } else {
    int cur = b;
    while (v[cur - 1] == 0 && v[cur - 2] == 0) {
      seq.push_back(cur - 2);
      seq.push_back(cur - 1);
      cur -= 2;
    }
    seq.push_back(a);
    return;
  }
}

void solution() {
  s.clear();
  m.clear();
  v.clear();
  seq.clear();

  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int prev = -1;

  for (int i = 0; i < n; i++) {
    if (v[i] == 0) continue;

    if (prev == -1)
      prev = i;
    else {
      bool poss = false;
      if (prev == i - 2 && v[i - 1] == 0)
        s.insert({prev, i});
      else if ((i - prev) % 2 == 0)
        s.insert({prev, i});
      else if (prev != i - 2 && ((prev - 1 >= 0 && v[prev - 1] == 0) ||
                                 (i + 1 < n && v[i + 1] == 0)))
        s.insert({prev, i});
      else
        m[prev] = i, m[i] = prev;
      prev = -1;
    }
  }
  while (!s.empty()) {
    pair<int, int> cur = *s.begin();
    s.erase(s.begin());
    change_to_zero(cur);
    v[cur.st] = 0;
    v[cur.nd] = 0;
    fix(cur);
  }
  for (int i = 0; i < n; i++)
    if (v[i] != 0) {
      cout << "NO\n";
      return;
    }

  cout << "YES\n" << seq.size() << '\n';
  for (auto x : seq) cout << x + 1 << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
