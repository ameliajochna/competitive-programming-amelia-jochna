#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n), vis(1001), ans;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 0; i--) {
    if (!vis[a[i]]) {
      ans.push_back(a[i]);
      vis[a[i]] = true;
    }
  }
  cout << ans.size() << "\n";
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  // cin>>t;
  while (t--) solution();
  return 0;
}
