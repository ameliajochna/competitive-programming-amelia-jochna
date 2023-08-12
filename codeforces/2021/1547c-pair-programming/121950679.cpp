#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int k, n, m;
  cin >> k >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int pn = 0, pm = 0;
  vector<int> ans;
  bool change = true;
  while (change) {
    change = false;
    while (pn < n) {
      // cout<<"PN: "<<pn<<" "<<a[pn]<<'\n';
      if (a[pn] == 0) {
        ans.push_back(0);
        pn++;
        change = true;
        k++;
      } else if (a[pn] <= k) {
        ans.push_back(a[pn]);
        pn++;
        change = true;
      } else
        break;
    }

    while (pm < m) {
      // cout<<"PM: "<<pm<<" "<<b[pm]<<'\n';
      if (b[pm] == 0) {
        ans.push_back(0);
        pm++;
        change = true;
        k++;
      } else if (b[pm] <= k) {
        ans.push_back(b[pm]);
        pm++;
        change = true;
      } else
        break;
    }
  }
  // for(auto x:ans)
  //         cout<<x<<" ";
  // cout<<'\n';

  if (ans.size() == n + m) {
    for (auto x : ans) cout << x << " ";
    cout << '\n';
  } else
    cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
