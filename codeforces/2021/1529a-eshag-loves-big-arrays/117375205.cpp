#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  int minval = 1e9, cnt = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (minval > tmp) {
      minval = tmp;
      cnt = 1;
    } else if (minval == tmp)
      cnt++;
  }
  cout << n - cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
