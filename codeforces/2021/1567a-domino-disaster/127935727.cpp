#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  char prev = ' ';
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'U') {
      cout << "D";
      prev = 'D';
    } else if (c == 'D') {
      cout << "U";
      prev = 'U';
    } else if (prev == 'L') {
      cout << "R";
      prev = 'R';
    } else {
      cout << "L";
      prev = 'L';
    }
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
