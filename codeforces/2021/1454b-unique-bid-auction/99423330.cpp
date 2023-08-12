#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  map<int, pair<int, int> > m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    m[a] = {m[a].first + 1, i};
  }
  int ind = -2, val = INT_MAX;
  for (auto a : m) {
    if (a.second.first == 1 && val > a.first) {
      val = a.first;
      ind = a.second.second;
    }
  }
  cout << ind + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
