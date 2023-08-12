#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;
typedef long double ld;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (a[i] - b[i]);
  }
  if (sum != 0) {
    cout << "-1\n";
    return;
  }
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    int diff = a[i] - b[i];
    // cout<<"DIFF: "<<i<<" "<<diff<<'\n';
    if (diff > 0) {
      for (int j = 0; j < diff; j++) {
        pos.push_back(i);
        // cout<<"ADD: "<<i<<'\n';
      }
    }
  }
  vector<pair<int, int> > ans;
  int pt = 0;
  for (int i = 0; i < n; i++) {
    int diff = a[i] - b[i];
    // cout<<"DIFF: "<<i<<" "<<diff<<'\n';
    if (diff < 0) {
      for (int j = 0; j < -diff; j++) {
        ans.push_back({pos[pt] + 1, i + 1});
        pt++;
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto p : ans) cout << p.st << " " << p.nd << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
