#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  int cnt = 0;
  bool cont = true;
  while (cont) {
    cont = false;
    for (int i = 1; i <= n; i++) {
      bool change = 0;
      if (i % 2 == 0) {  // even
        for (int j = 2; j <= n - 1; j += 2) {
          if (v[j] > v[j + 1]) {
            swap(v[j], v[j + 1]);
            change = true;
          }
        }
      } else {
        for (int j = 1; j <= n - 2; j += 2) {
          if (v[j] > v[j + 1]) {
            swap(v[j], v[j + 1]);
            change = true;
          }
        }
      }
      if (change) {
        cnt = i;
        cont = true;
      }
    }
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
