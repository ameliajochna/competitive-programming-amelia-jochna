#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int, vector<int> > ind;
  for (int i = 1; i <= n; i++) cin >> a[i], ind[a[i]].push_back(i);
  vector<int> ans(n + 1, INT_MAX);
  for (auto x : ind) {
    int diff = max(x.second[0], n + 1 - x.second[x.second.size() - 1]);
    // cout<<x.first<<" "<<"r "<<x.second[0]<<"
    // "<<n+1-x.second[x.second.size()-1]<<"\n";
    for (int i = 0; i < x.second.size() - 1; i++) {
      diff = max(diff, x.second[i + 1] - x.second[i]);
      // cout<<diff<<" ";
    }
    // cout<<'\n';
    // cout<<x.first<<"\n";
    // cout<<diff<<" "<<ans[diff]<<'\n';
    if (diff <= n) ans[diff] = min(ans[diff], x.first);
  }
  int minunt = INT_MAX;
  for (int i = 1; i <= n; i++) {
    minunt = min(ans[i], minunt);
    if (minunt == INT_MAX)
      cout << "-1 ";
    else
      cout << minunt << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
