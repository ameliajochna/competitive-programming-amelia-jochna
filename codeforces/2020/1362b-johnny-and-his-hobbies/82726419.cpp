#include <bits/stdc++.h>
#define FOR(i, n)             \
  for (int i = 0; i < n; i++) \
    ;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool check(int &k, set<int> s, vector<int> &v, int &n) {
  // cout<<k<<" ";
  for (int i = 0; i < n; i++) {
    int tmp = (v[i] xor k);
    // cout<<tmp<<" ";
    if (s.count(tmp) == 0) return false;
    s.erase(tmp);
  }
  // cout<<'\n';
  return true;
}

void solution() {
  int n;
  cin >> n;
  set<int> s;
  vector<int> v(n);
  int maxval = -1;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    s.insert(e);
    v[i] = e;
    maxval = max(maxval, e);
  }
  for (int i = 1; i <= 1024; i++) {
    if (check(i, s, v, n)) {
      cout << i << "\n";
      return;
    }
  }
  cout << "-1\n";
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
