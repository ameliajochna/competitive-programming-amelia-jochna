#include <iostream>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int p = 29;
const int maxN = 5e5 + 10;

int suf[maxN], pwr[maxN], n;
std::string s;

int seghash(int l, int r) {
  return ((static_cast<long long>(suf[l]) -
           static_cast<long long>(suf[r + 1]) * pwr[r - l + 1]) %
              MOD +
          MOD) %
         MOD;
}

void preprocess() {
  n = s.size();
  pwr[0] = 1;
  for (int i = 1; i <= n; i++)
    pwr[i] = (static_cast<long long>(pwr[i - 1]) * p) % MOD;

  for (int i = n - 1; i >= 0; i--)
    suf[i] =
        ((static_cast<long long>(suf[i + 1]) * p + (s[i] - 'a' + 1)) % MOD);
}

bool equal(int l1, int l2, int len) {
  return seghash(l1, l1 + len) == seghash(l2, l2 + len);
}

int lcp(int l1, int l2, int len) {
  int l = 0, r = len;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (equal(l1, l2, mid))
      l = mid;
    else
      r = mid;
  }
  if (equal(l1, l2, l)) return r;
  return l;
}

bool oneinddiff(int l1, int l2, int len) {
  int ind = lcp(l1, l2, len);
  if (equal(l1, l2, len)) return true;
  if (ind == len || equal(l1 + ind + 1, l2 + ind + 1, len - ind - 1))
    return true;
  return false;
}

bool period(int k) {
  std::vector<std::pair<int, std::pair<int, int> > > v;
  for (int i = 0; i + k - 1 < n; i += k) {
    int l = i, r = i + k - 1;
    int hash = seghash(l, r);
    if (v.size() == 0)
      v.push_back({hash, {1, l}});
    else if (v.size() == 1) {
      if (hash == v[0].first)
        v[0].second.first++;
      else
        v.push_back({hash, {1, l}});
    } else if (v.size() == 2) {
      if (hash == v[0].first)
        v[0].second.first++;
      else if (hash == v[1].first)
        v[1].second.first++;
      else
        return false;
      if (v[0].second.first != 1 && v[1].second.first != 1) return false;
    }
  }
  if (n % k != 0) {
    int l = (n / k) * k, len = n % k - 1;
    if (v.size() == 1) {
      int l0 = v[0].second.second;
      if (oneinddiff(l0, l, len)) return true;
      return false;
    } else if (v.size() == 2) {
      int cnt0 = v[0].second.first, cnt1 = v[1].second.first;
      int tmp0 = v[0].second.second, tmp1 = v[1].second.second;
      if (cnt0 == 1 && cnt1 == 1) {
        if ((seghash(tmp0, tmp0 + len) == seghash(l, l + len) ||
             seghash(tmp1, tmp1 + len) == seghash(l, l + len))) {
          int l0 = v[0].second.second, l1 = v[1].second.second;
          if (oneinddiff(l0, l1, k - 1)) return true;
        }
      } else {
        if ((seghash(tmp0, tmp0 + len) == seghash(l, l + len) && cnt0 != 1) ||
            (seghash(tmp1, tmp1 + len) == seghash(l, l + len) && cnt1 != 1)) {
          int l0 = v[0].second.second, l1 = v[1].second.second;
          if (oneinddiff(l0, l1, k - 1)) return true;
        }
      }
      return false;
    }
  }
  if (v.size() == 1)
    return true;
  else {
    int l1 = v[0].second.second, l2 = v[1].second.second;
    if (oneinddiff(l1, l2, k - 1)) return true;
    return false;
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> s;
  preprocess();
  std::vector<int> ans;
  for (int i = 1; i < n; i++)
    if (period(i)) ans.push_back(i);
  std::cout << ans.size() << '\n';
  for (auto x : ans) std::cout << x << " ";
}
