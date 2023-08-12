#include <bits/stdc++.h>

#include <iostream>
using namespace std;
long long ceil(long long x, long long y) {
  if (x % y == 0)
    return x / y;
  else
    return x / y + 1;
}

int main() {
  long long n, m, a, ans;
  cin >> n;
  cin >> m;
  cin >> a;
  ans = ceil(n, a) * ceil(m, a);
  cout << ans;
  return 0;
}
