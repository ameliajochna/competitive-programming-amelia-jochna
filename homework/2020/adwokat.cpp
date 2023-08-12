#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const inf = 80000010;
int n, m;
struct triplet {
  int h1, h2, ind;
};
vector<triplet> meeting[21];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    triplet sched;
    int day;
    cin >> sched.h1 >> sched.h2 >> day;
    sched.ind = i;
    meeting[day].push_back(sched);
  }
  for (int i = 1; i <= m; i++) {
    int minend = inf, maxstart = 0, minendin, maxstartin;
    for (int j = 0; j < meeting[i].size(); j++) {
      triplet cur = meeting[i][j];
      if (cur.h1 > maxstart) {
        maxstart = cur.h1;
        maxstartin = cur.ind;
      }
      if (cur.h2 < minend) {
        minend = cur.h2;
        minendin = cur.ind;
      }
    }
    if (maxstart > minend && maxstartin != minendin) {
      cout << "TAK"
           << " " << minendin << " " << maxstartin << '\n';
    } else {
      cout << "NIE" << '\n';
    }
  }
}
