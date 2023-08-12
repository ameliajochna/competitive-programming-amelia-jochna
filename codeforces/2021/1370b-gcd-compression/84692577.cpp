#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void solution() {
  int n;
  cin >> n;
  vector<int> a[2];
  for (int i = 1; i <= 2 * n; i++) {
    int x;
    cin >> x;
    a[x % 2].push_back(i);
  }
  int cnt = 0;
  for (int j = 0; j < 2; j++) {
    for (int i = 1; i < a[j].size(); i += 2) {
      if (cnt < n - 1) {
        cout << a[j][i - 1] << " " << a[j][i] << '\n';
        cnt++;
      }
    }
  }
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
