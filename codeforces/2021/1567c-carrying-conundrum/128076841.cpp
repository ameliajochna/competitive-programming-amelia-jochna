#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;
int const maxN = 3e5 + 10;
int prefxor[maxN];

void solution() {
  string s;
  cin >> s;
  int a = 0;
  for (int i = 0; i < s.size(); i += 2) {
    int v = s[i] - '0';
    a *= 10;
    a += v;
  }
  int b = 0;
  for (int i = 1; i < s.size(); i += 2) {
    int v = s[i] - '0';
    b *= 10;
    b += v;
  }
  // cout<<a<<" "<<b<<'\n';
  cout << ll(a + 1) * (b + 1) - 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  for (int i = 1; i < maxN; i++) prefxor[i] = prefxor[i - 1] ^ i;
  int t;
  cin >> t;
  while (t--) solution();
}
