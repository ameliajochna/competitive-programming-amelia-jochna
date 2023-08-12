#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  for (int i = 1;; i++) {
    if (i % 3 == 0 || i % 10 == 3) continue;
    n--;
    if (n == 0) {
      cout << i << "\n";
      return;
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
