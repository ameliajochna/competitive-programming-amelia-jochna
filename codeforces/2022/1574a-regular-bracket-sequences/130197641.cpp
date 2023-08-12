#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<char> s(2 * n);
  for (int i = 0; i < 2 * n; i += 2) {
    s[i] = '(', s[i + 1] = ')';
    cout << s[i] << s[i + 1];
  }
  cout << '\n';
  int cnt = 1;
  for (int i = 1; i < 2 * n; i++) {
    if (s[i] == ')') {
      for (int j = i; j < 2 * n; j++) {
        if (s[j] == '(') {
          if (cnt < n) {
            // cout<<"PAIR: "<<i<<" "<<j<<'\n';
            for (int k = 0; k < 2 * n; k++) {
              if (k == i)
                cout << '(';
              else if (k == j)
                cout << ')';
              else
                cout << s[k];
            }
            cout << '\n';
            cnt++;
          }
        }
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
}
