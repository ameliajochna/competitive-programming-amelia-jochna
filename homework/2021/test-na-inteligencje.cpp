#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

int const maxM = 1e6 + 10;
int m;
vector<int> ind[maxM];

int binsearch(int val, int prev) {
  if (ind[val].size() == 0) return -1;
  vector<int> &cur = ind[val];
  int l = 0, r = ind[val].size() - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    (cur[mid] > prev ? r : l) = mid;
  }
  if (cur[l] > prev)
    return cur[l];
  else if (cur[r] > prev)
    return cur[r];
  else
    return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> m;
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    ind[tmp].pb(i);
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int prev = -1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      if (ok) prev = binsearch(tmp, prev);
      if (prev < 0) ok = false;
    }
    if (ok)
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
  return 0;
}
