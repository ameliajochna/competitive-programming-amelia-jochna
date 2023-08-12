#include <bits/stdc++.h>
using namespace std;
long long const inf = 1e9 * 2 * 1e5 + 10;
void solution() {
  int n;
  cin >> n;
  int div = 3;
  while (n % div != 0) {
    div++;
    div *= 2;
    div--;
  }
  cout << (n / div) << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
