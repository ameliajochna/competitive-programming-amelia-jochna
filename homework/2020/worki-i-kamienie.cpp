#include <iostream>
using namespace std;
const int maxN = 100004;
int ranga[maxN], rep[maxN];

int Find(int v) {
  if (v == rep[v]) return v;
  return rep[v] = Find(rep[v]);
}

void Union(int u, int v) {
  u = Find(u);
  v = Find(v);
  if (ranga[u] < ranga[v]) {
    rep[u] = rep[v];
  } else if (ranga[u] > ranga[v]) {
    rep[v] = rep[u];
  } else {
    rep[v] = rep[u];
    ranga[u]++;
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) rep[i] = i;
  for (int i = 0; i < q; i++) {
    int type, a, b;
    cin >> type >> a >> b;
    if (type == 0) {
      if (Find(a) == Find(b))
        cout << "Tak\n";
      else
        cout << "Nie\n";
    } else if (type == 1) {
      Union(a, b);
    }
  }
  return 0;
}
