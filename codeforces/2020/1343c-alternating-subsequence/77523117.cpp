#include <bits/stdc++.h>
using namespace std;
long long const inf = 1e9 * 2 * 1e5 + 10;
void solution() {
  int n;
  long long maxpos = 0, maxneg = -inf;
  long long sum = 0;
  bool prevpos = false, prevneg = false;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    if (e < 0) {
      if (prevpos) {
        sum += maxpos;
        maxpos = 0;
      }
      if (maxneg < e) maxneg = e;
      prevneg = true;
      prevpos = false;
    } else if (e > 0) {
      if (prevneg) {
        sum += maxneg;
        maxneg = -inf;
      }
      if (maxpos < e) maxpos = e;
      prevpos = true;
      prevneg = false;
    }
  }
  if (prevneg) {
    sum += maxneg;
  }
  if (prevpos) {
    sum += maxpos;
  }
  cout << sum << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
