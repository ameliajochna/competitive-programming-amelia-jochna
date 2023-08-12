#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  for (int i = 0; 3 * i <= n; i++) {
    int newn = n - (3 * i);
    for (int j = 0; 5 * j <= newn; j++) {
      int nnewn = newn - (5 * j);
      if (nnewn % 7 == 0) {
        cout << i << " " << j << " " << nnewn / 7 << '\n';
        return;
      }
    }
  }
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
