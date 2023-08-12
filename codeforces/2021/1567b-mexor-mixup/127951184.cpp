#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;
int const maxN = 3e5 + 10;
int prefxor[maxN];

void solution() {
  int a, b;
  cin >> a >> b;
  // cout<<prefxor[a-1]<<" "<<(b^prefxor[a-1])<<'\n';
  if (prefxor[a - 1] == b) {
    cout << a << '\n';
  } else if ((b ^ prefxor[a - 1]) == a) {
    cout << a + 2 << '\n';
  } else
    cout << a + 1 << '\n';
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
