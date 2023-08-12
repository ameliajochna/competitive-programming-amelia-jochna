#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

const int maxN = 2e6 + 10;
int z[maxN];

std::string shortest_period(std::string &s) {
  int n = s.size();
  z[0] = 0;
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    z[i] = 0;
    if (i <= r) z[i] = std::min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }

  int len = n;
  for (int i = n - 1; i > 0; i--)
    if (n % i == 0 && z[i] == n - i) len = i;

  std::string base;
  for (int i = 0; i < len; i++) base += s[i];

  return base;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::string> v;
  for (int i = 0; i < n; i++) {
    int len;
    std::string s;
    std::cin >> len >> s;
    v.push_back(shortest_period(s));
  }
  std::sort(v.begin(), v.end());

  int cnt = 1, ans = 0;
  for (int i = 1; i < v.size(); i++) {
    if (v[i - 1] != v[i]) {
      ans += (cnt * cnt);
      cnt = 0;
    }
    cnt++;
  }

  ans += (cnt * cnt);
  std::cout << ans << '\n';
}
