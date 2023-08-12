#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
using namespace std;
typedef long long ll;

void solution() {
  int n;
  char c;
  cin >> n >> c;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (s[i] != c) cnt++;

  if (cnt == 0) {
    cout << "0\n";
  } else if (cnt == 1) {
    if (s[n - 1] != c) {
      cout << "1\n";
      cout << n - 1 << '\n';
    } else {
      cout << "1\n";
      cout << n << "\n";
    }
  } else {
    if (s[n - 1] != c) {
      set<int> div;
      for (int i = 0; i < n; i++) {
        if (s[i] != c) {
          for (int k = 1; k <= sqrt(i + 1); k++) {
            if ((i + 1) % k == 0) {
              div.insert(k);
              div.insert((i + 1) / k);
            }
          }
        }
      }
      for (int i = 1; i <= n; i++) {
        if (div.find(i) == div.end()) {
          cout << "1\n";
          cout << i << '\n';
          return;
        }
      }
      cout << "2\n";
      cout << n - 1 << " " << n << '\n';
    } else {
      cout << "1\n";
      cout << n << '\n';
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
