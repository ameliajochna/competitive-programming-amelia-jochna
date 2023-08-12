#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

bool prime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void solution() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int val = s[i] - '0';
    if (val == 1 || val == 4 || val == 6 || val == 8 || val == 9) {
      cout << "1\n" << val << '\n';
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int v1 = s[i] - '0', v2 = s[j] - '0';
      int num = 10 * v1 + v2;
      if (!prime(num)) {
        cout << "2\n" << num << '\n';
        return;
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
