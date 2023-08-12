#include <bits/stdc++.h>
using namespace std;
void solution() {
  int n;
  cin >> n;
  int maxval, maxdif = 0;
  cin >> maxval;
  for (int i = 0; i < n - 1; i++) {
    int tmp_e;
    cin >> tmp_e;
    maxval = max(maxval, tmp_e);
    maxdif = max(maxdif, maxval - tmp_e);
  }
  cout << ceil(log2(maxdif + 1)) << '\n';
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
