#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

int const MAXQ = 10001;
std::set<std::pair<int, int> > freq;
int m, a[10001];

struct triplet {  // lewy, prawy, indeks
  int st, nd, rd;
};

triplet seg[MAXQ];

bool compare(triplet a, triplet b) {
  if (a.st / m != b.st / m) return a.st < b.st;
  if (a.nd != b.nd) return a.nd < b.nd;
  return a.st < b.st;
}

bool cmp2(triplet a, triplet b) { return a.rd < b.rd; }

int main() {
  int n, q;
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> seg[i].st >> seg[i].nd;
    seg[i].st--, seg[i].nd--;
    seg[i].rd = i;
  }
  m = sqrt(n);
  std::sort(seg, seg + q, compare);
  std::unordered_map<int, int> cnt;
  int l = 0, r = -1;
  for (int i = 0; i < q; i++) {
    triplet cur = seg[i];
    while (r < cur.nd) {
      r++;
      int e = a[r];
      if (cnt[e] != 0) freq.erase({-cnt[e], e});
      cnt[e]++;
      freq.insert({-cnt[e], e});
    }
    while (r > cur.nd) {
      int e = a[r];
      freq.erase({-cnt[e], e});
      cnt[e]--;
      if (cnt[e] != 0)
        freq.insert({-cnt[e], e});
      else
        cnt.erase(e);
      r--;
    }
    while (l > cur.st) {
      l--;
      int e = a[l];
      if (cnt[e] != 0) freq.erase({-cnt[e], e});
      cnt[e]++;
      freq.insert({-cnt[e], e});
    }
    while (l < cur.st) {
      int e = a[l];
      freq.erase({-cnt[e], e});
      cnt[e]--;
      if (cnt[e] != 0)
        freq.insert({-cnt[e], e});
      else
        cnt.erase(e);
      l++;
    }
    seg[i].st = freq.begin()->second;
  }
  std::sort(seg, seg + q, cmp2);
  for (int i = 0; i < q; i++) std::cout << seg[i].st << "\n";

  return 0;
}
