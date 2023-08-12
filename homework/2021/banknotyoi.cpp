#include <algorithm>
#include <deque>
#include <iostream>
#include <utility>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
const int maxN = 205, maxK = 2e4 + 5, inf = 1e9;

int used[maxN][maxK];  // used[i][j] - ile uzyto monet o nominale b[i] zeby
                       // wydac kwote j
int cnt[maxK];  // cnt[i] - sumarycznie ile minimalnie monet trzeba uzyc do
                // wydania kwoty i
int bfr[maxK];  // cnt[i] przed updatem
int b[maxN], c[maxN];
int n, k;

void add(int nr) {
  int val = b[nr];
  std::deque<int> dq;
  for (int r = 0; r < val; r++) {  // kolejne reszty mod r
    dq.clear();
    int l = 0;
    while (r + l * val <= k) {
      int cur = r + l * val;
      bfr[l] = cnt[cur] - l;
      while (!dq.empty() && bfr[l] <= bfr[dq.back()]) dq.pop_back();
      dq.push_back(l);
      cnt[cur] = bfr[dq.front()] + l;
      used[nr][cur] = l - dq.front();
      if (dq.front() == l - c[nr]) dq.pop_front();
      l++;
    }
  }
}

void ans(int i, int j) {
  if (i < 0) return;
  ans(i - 1, j - b[i] * used[i][j]);
  std::cout << used[i][j] << " ";
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> b[i];
  for (int i = 0; i < n; i++) std::cin >> c[i];
  std::cin >> k;

  cnt[0] = 0;
  for (int i = 1; i <= k; i++) cnt[i] = inf;

  for (int i = 0; i < n; i++) add(i);

  std::cout << cnt[k] << '\n';
  ans(n - 1, k);
  return 0;
}
