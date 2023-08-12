#include <bits/stdc++.h>
using namespace std;
using lf = long double;
using ll = long long;
using cll = const ll;
using cint = const int;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int const maxN = (int)1e6 + 10;
int n, l[maxN], r[maxN];

int main() {
  fast cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

  map<int, int> m;
  int len = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    while (!m.empty() && (*m.begin()).st < l[i]) {
      cnt += (*m.begin()).nd;
      m.erase(m.begin());
    }
    while (!m.empty() && (*m.rbegin()).st > r[i]) {
      int tmp = (*m.rbegin()).nd;
      m.erase((*m.rbegin()).st);
      cur -= tmp;
    }

    // wstaw cnt+1 razy l[i]
    m[l[i]] += cnt + 1;
    cur++;

    /*cout<<i<<": \n";
       for(auto p:m)
        cout<<p.st<<" "<<p.nd<<'\n';
       cout<<"CNT: "<<cur<<'\n';*/
    len = max(cur, len);
  }
  cout << len << '\n';
}
