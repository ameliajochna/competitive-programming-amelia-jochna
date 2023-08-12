#include <bits/stdc++.h>
using namespace std;
int const maxN = 200001;
bool vis[maxN];
int n, a[maxN], maxval;
vector<pair<int, int> > ans;

void clean() {
  maxval = 0;
  while (!ans.empty()) ans.pop_back();
}

bool perm(int start, int end) {
  for (int i = 0; i <= n; i++) vis[i] = false;
  for (int i = start; i < end; i++) {
    if (vis[a[i]] || a[i] > end - start) return false;
    vis[a[i]] = true;
  }
  for (int i = 1; i <= end - start; i++)
    if (!vis[i]) return false;
  return true;
}

void solution() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (maxval < a[i]) maxval = a[i];
  }
  if (perm(0, maxval) && perm(maxval, n)) ans.push_back({maxval, n - maxval});
  if (perm(0, n - maxval) && perm(n - maxval, n)) {
    if ((!ans.empty() && ans[0].first != n - maxval) || ans.empty())
      ans.push_back({n - maxval, maxval});
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << '\n';
  clean();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
