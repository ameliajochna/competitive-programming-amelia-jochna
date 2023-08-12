#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ind = -1;
  for (int i = 0; i < n; i++)
    if (s[i] == '0') ind = i;
  if (ind == -1) {
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << '\n';
  } else {
    if (ind < (n / 2)) {
      cout << ind + 1 << " " << n << ' ' << ind + 2 << " " << n << '\n';
    } else {
      cout << 1 << " " << ind + 1 << " " << 1 << " " << ind << '\n';
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
}
