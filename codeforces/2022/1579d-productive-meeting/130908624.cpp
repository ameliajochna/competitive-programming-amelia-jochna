#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  priority_queue<pii> pq;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    if (val > 0) pq.push({val, i});
  }
  vector<pii> ans;
  while (pq.size() > 1) {
    pii p1 = pq.top();
    pq.pop();
    pii p2 = pq.top();
    pq.pop();
    ans.push_back({p1.nd, p2.nd});
    if (p1.st - 1 > 0) pq.push({p1.st - 1, p1.nd});
    if (p2.st - 1 > 0) pq.push({p2.st - 1, p2.nd});
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x.st + 1 << " " << x.nd + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
/*
   1
   3 3 2
 *.*
   .*.
   ...

 */
