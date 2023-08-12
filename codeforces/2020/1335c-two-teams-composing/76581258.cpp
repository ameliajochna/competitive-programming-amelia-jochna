#include <bits/stdc++.h>
using namespace std;
int const maxN = 2e5 + 10;

void solution() {
  map<int, int> cmap;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    cmap[tmp]++;
  }
  int maxsame = 0;
  int diff = 0, best = -maxN;
  for (auto e : cmap) {
    if (e.second > maxsame) {
      diff += (maxsame != 0 ? 1 : 0);
      maxsame = e.second;
    } else
      diff++;
  }
  if (maxsame > diff) {
    maxsame--;
    diff++;
  }
  best = min(diff, maxsame);
  cout << best << '\n';
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
