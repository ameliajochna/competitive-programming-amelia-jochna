#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

int const maxV = 2e6 + 10;
int mindiv[maxV];
int dp[maxV];

void fact(int limit) {
  for (int i = 2; i <= limit; i++) {
    if (mindiv[i] == 0) {
      mindiv[i] = i;
      for (int j = 2; i * j <= limit; j++)
        if (mindiv[i * j] > i || mindiv[i * j] == 0) mindiv[i * j] = i;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, mval = 0;
  std::cin >> n;

  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
    mval = std::max(mval, v[i]);
  }

  fact(mval);

  dp[1] = 0;
  for (int i = 2; i <= mval; i++) {
    int prev = 1, tmp = i;
    int maxfound = -1;
    while (mindiv[tmp] > 1) {
      int cur = mindiv[tmp];
      if (cur != prev) {
        int x = cur;
        int len = i / x, cnt = x, ans;
        if (cnt % 2 == 0)
          ans = 0;
        else
          ans = dp[len];
        maxfound = std::max(ans, maxfound);
      }
      prev = cur;
      tmp /= cur;
    }
    dp[i] = maxfound + 1;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) ans ^= dp[v[i]];

  std::cout << ":" << (ans ? ")" : "(") << '\n';
}
