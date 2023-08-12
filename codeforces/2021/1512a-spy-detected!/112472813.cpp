#include <bits/stdc++.h>
using namespace std;

void solution() {
  map<int, pair<int, int> > m;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x].first++;
    m[x].second = i;
  }
  for (auto x : m) {
    if (x.second.first == 1) {
      cout << x.second.second + 1 << '\n';
    }
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
