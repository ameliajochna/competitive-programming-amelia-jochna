#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  int len = n / 2;
  string s;
  for (int i = 0; i < len - 1; i++) {
    s += ('a');
  }
  if (n != 1) s += ('b');
  for (int i = 0; i < len; i++) {
    s += ('a');
  }
  if (n % 2 == 1) s += 'c';
  cout << s << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
