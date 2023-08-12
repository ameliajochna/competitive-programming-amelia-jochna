#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int const maxN = 500010;
int s[maxN];
int main() {
  int n;
  cin >> n;
  fill_n(s, n + 1, 1);
  for (int i = 2; i <= n; i++) {
    for (int j = 2; i * j <= n; j++) {
      s[i * j] = i;
    }
  }
  sort(s + 1, s + n + 1);
  for (int i = 2; i <= n; i++) cout << s[i] << " ";
  cout << '\n';
  return 0;
}
