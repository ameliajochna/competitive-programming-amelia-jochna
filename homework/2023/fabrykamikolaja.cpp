#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

template <class p, class q>
std::pair<p, q> operator-(const std::pair<p, q> &a, const std::pair<p, q> &b) {
  return std::make_pair(a.first - b.first, a.second - b.second);
}

template <class p, class q>
std::pair<p, q> operator+(const std::pair<p, q> &a, const std::pair<p, q> &b) {
  return std::make_pair(a.first + b.first, a.second + b.second);
}

template <class p, class q>
void umin(p &a, const q &b) {
  if (a > b) a = b;
}

template <class p, class q>
void umax(p &a, const q &b) {
  if (a < b) a = b;
}

struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const std::pair<T1, T2> &p) const {
    auto hash1 = std::hash<T1>{}(p.first);
    auto hash2 = std::hash<T2>{}(p.second);

    if (hash1 != hash2) {
      return hash1 ^ hash2;
    }

    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};

const int MOD[2] = {static_cast<int>(1e9 + 9), static_cast<int>(1e9 + 7)};
const int p[2] = {31, 29};
const int _log = 19;
const int maxN = static_cast<int>(2e5 + 10);

int suf[2][maxN], pwr[2][maxN];
int n, m, q, prnt[maxN][_log], dpth[maxN];
std::unordered_map<std::pair<int, int>, int, hash_pair> mp;
std::string s;
std::vector<std::pair<int, char> > T[maxN];

inline std::pair<int, int> seghash(int l, int r) {
  return {((static_cast<long long>(suf[0][l]) -
            static_cast<long long>(suf[0][r + 1]) * pwr[0][r - l + 1]) %
               MOD[0] +
           MOD[0]) %
              MOD[0],
          ((static_cast<long long>(suf[1][l]) -
            static_cast<long long>(suf[1][r + 1]) * pwr[1][r - l + 1]) %
               MOD[1] +
           MOD[1]) %
              MOD[1]};
}

void preprocess() {
  int l = static_cast<int>(s.size());
  pwr[0][0] = 1;
  pwr[1][0] = 1;
  for (int i = 1; i <= l; i++) {
    pwr[0][i] = (static_cast<long long>(pwr[0][i - 1]) * p[0]) % MOD[0];
    pwr[1][i] = (static_cast<long long>(pwr[1][i - 1]) * p[1]) % MOD[1];
  }

  for (int i = l - 1; i >= 0; i--) {
    suf[0][i] =
        ((static_cast<long long>(suf[0][i + 1]) * p[0] + (s[i] - 'a' + 1))) %
        MOD[0];
    suf[1][i] =
        ((static_cast<long long>(suf[1][i + 1]) * p[1] + (s[i] - 'a' + 1))) %
        MOD[1];
  }
}

void dfs(int u, int prev, char c, long long curh0, long long curh1, int dp) {
  if (u != 0) {
    curh0 += (c - 'a' + 1) * pwr[0][dp - 1];
    curh0 %= MOD[0];
    curh1 += (c - 'a' + 1) * pwr[1][dp - 1];
    curh1 %= MOD[1];
  }
  mp[{curh0, curh1}] = u;
  for (const auto &pr : T[u]) {
    int v = pr.first;
    if (v != prev) dfs(v, u, pr.second, curh0, curh1, dp + 1);
  }
}

bool ok(int l, int r) { return (mp.find(seghash(l, r)) != mp.end()); }

int lcp(int l1) {
  int l = 0, r = static_cast<int>(s.size()) - l1 - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (ok(l1, l1 + mid)) {
      l = mid;  // want longer
    } else {
      r = mid;
    }
  }
  if (ok(l1, l1 + r)) {
    return r;
  }
  if (ok(l1, l1 + l)) {
    return l;
  }
  return -1;
}

void maketree() {
  dpth[m] = 0;
  for (int i = static_cast<int>(s.size()) - 1; i >= 0;
       i--) {  // znajdz lcp sciezek z drzewa i podciagu od i do n
    int len = lcp(i), abv, cost = 0;
    if (len == -1) {
      abv = i + 1;
      cost = 1;
    } else {
      abv = i + len + 2;
      if (i + len + 1 < m) {
        cost = 1;
      } else if (i + len + 1 == m) {
        abv = m;
      }
    }
    prnt[i][0] = abv;
    dpth[i] = dpth[abv] + cost;
  }
  prnt[m][0] = m;
  for (int j = 1; j < _log; j++) {
    for (int i = 0; i <= m; i++) {
      prnt[i][j] = prnt[prnt[i][j - 1]][j - 1];
    }
  }
}

int bnlift(int u, int val) {
  for (int i = _log - 1; i >= 0; i--) {
    if (prnt[u][i] <= val) {
      u = prnt[u][i];
    }
  }
  if (prnt[u][0] <= val) {
    return prnt[u][0];
  }
  return u;
}

void query(int l, int r) {
  int v = bnlift(l, r);
  std::pair<int, int> hsh = seghash(v, r);

  int lst;
  if (mp.find(hsh) == mp.end()) {
    lst = 0;
  } else {
    lst = mp[hsh];
  }

  int diff = dpth[l] - dpth[v] + (lst == 0);
  std::cout << diff << " " << lst << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    char c;
    int u;
    std::cin >> u >> c;
    T[i].push_back({u, c});
    T[u].push_back({i, c});
  }
  std::cin >> s;
  preprocess();
  dfs(0, 0, 'a', 0, 0, 0);

  maketree();
  for (int i = 0; i < q; i++) {
    int l, r;
    std::cin >> l >> r;
    query(l - 1, r - 1);
  }
}
