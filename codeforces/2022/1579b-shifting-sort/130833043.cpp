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
  vector<int> v(n);
  multiset<pii> s;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    s.insert({v[i], i});
  }
  int cur = 0;
  vector<pii> ans;
  while (!s.empty()) {
    pii a = *s.begin();
    s.erase(s.begin());
    int l = cur, r = a.nd;
    if (l < r) {
      ans.push_back({l, r});
      int prev = v[r];
      for (int i = l; i <= r; i++) {
        if (i != r) {
          s.erase({v[i], i});
          s.insert({v[i], i + 1});
        }
        int tmpprev = v[i];
        v[i] = prev;
        prev = tmpprev;
      }
      // cout<<l<<" "<<r<<'\n';
      /*for(int i=0; i<n; i++){
          cout<<v[i]<<" ";
         } cout<<'\n';*/
    }
    cur++;
  }

  cout << sz(ans) << '\n';
  for (auto x : ans) {
    cout << x.st + 1 << " " << x.nd + 1 << " " << x.nd - x.st << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
