#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
typedef long long ll;
typedef pair<int, int> pii;
int h[4] = {0, 0, 0, 0}, mod[2] = {int(1000025267), int(1e9 + 9)}, b = 7177,
    val[2] = {1, 1};
int main() {
  int n;
  cin >> n;
  char a;
  while (scanf("%c", &a) != EOF) {
    int tmp = a - 'a' + 1;
    h[0] = (1LL * h[0] * b + tmp) % mod[0];
    h[1] = (1LL * tmp * val[0] + h[1]) % mod[0];
    val[0] = (1LL * val[0] * b) % mod[0];
  }
  if (h[0] == h[1] && h[2] == h[3])
    cout << "TAK\n";
  else
    cout << "NIE\n";
  return 0;
}
