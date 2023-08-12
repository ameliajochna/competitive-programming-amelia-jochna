#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  map<int, vector<int> > ind;
  for (int i = 0; i < n; i++) cin >> a[i], ind[a[i]].push_back(i);
  vector<bool> taken(n);
  for (auto v : ind) {
    for (int i = 0; i < v.second.size(); i++) {
      int value = v.second[i];
      taken[value] = false;
    }
    if (2 * v.first == t) {
      for (int i = 0; i < v.second.size(); i++) {
        int value = v.second[i];
        if (i % 2 == 0)
          taken[value] = true;
        else
          taken[value] = false;
      }
    } else if (ind.find(t - v.first) != ind.end()) {
      int sec = t - v.first;
      for (int i = 0; i < ind[sec].size(); i++) {
        int value = ind[sec][i];
        taken[value] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << taken[i] << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
