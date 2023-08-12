#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int> pii;
typedef long long ll;

void solution() {
  int n, x;
  scanf("%d%d", &n, &x);
  int even = 0, odd = 0;
  FOR(i, n) {
    int a;
    cin >> a;
    if (a % 2 == 0)
      even++;
    else
      odd++;
  }
  for (int i = 1; i <= odd; i += 2) {
    int left = x - i;
    if (left >= 0 && left <= even) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solution();
  return 0;
}
