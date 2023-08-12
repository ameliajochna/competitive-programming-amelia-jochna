#include <iostream>
#include <utility>
#include <vector>
const int maxN = 1e3 + 10, INF = 1e9;
int n, q;
std::vector<std::pair<long long, long long> > p;
std::pair<long long, long long> start;

long long crossproduct(std::pair<long long, long long> v1,
                       std::pair<long long, long long> v2) {
  return (v1.first * v2.second) - (v2.first * v1.second);
}

std::pair<int, int> binsearch(std::pair<long long, long long> Q) {
  std::pair<long long, long long> v1 = {Q.first - start.first,
                                        Q.second - start.second};
  int l = 1, r = n - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    std::pair<long long, long long> v2 = {p[mid].first - start.first,
                                          p[mid].second - start.second};
    if (crossproduct(v2, v1) >= 0)
      l = mid;
    else
      r = mid;
  }
  std::pair<long long, long long> v2 = {p[r].first - start.first,
                                        p[r].second - start.second};
  if (crossproduct(v2, v1) >= 0) return {r, r + 1};
  v2 = {p[l].first - start.first, p[l].second - start.second};
  if (crossproduct(v2, v1) >= 0)
    return {l, l + 1};
  else
    return {INF, INF};
}

bool inside(std::pair<long long, long long> Q) {
  std::pair<int, int> clleft = binsearch(Q);
  if (clleft.second > n + 1) return false;
  std::pair<long long, long long> p1 = p[clleft.first], p2 = p[clleft.second];
  std::pair<long long, long long> v1 = {p2.first - p1.first,
                                        p2.second - p1.second};
  std::pair<long long, long long> v2 = {Q.first - p1.first,
                                        Q.second - p1.second};
  if (clleft.second == n && crossproduct(v1, v2) == 0) {
    if (Q.first < p1.first) return true;
    return false;
  } else if (crossproduct(v1, v2) >= 0)
    return true;
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n >> q;
  std::vector<std::pair<long long, long long> > tmp(n);
  for (int i = 0; i < n; i++) std::cin >> tmp[i].first >> tmp[i].second;

  int ind = -1;
  start = {INF, INF};
  for (int i = 0; i < n; i++)
    if (tmp[i].first < start.first ||
        (tmp[i].first == start.first && tmp[i].second > start.second))
      start = tmp[i], ind = i;

  for (int i = ind; i < n; i++) p.push_back(tmp[i]);
  for (int i = 0; i < ind; i++) p.push_back(tmp[i]);
  p.push_back(start);
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    std::cout << (inside({x, y}) ? "D\n" : "F\n");
  }
}
