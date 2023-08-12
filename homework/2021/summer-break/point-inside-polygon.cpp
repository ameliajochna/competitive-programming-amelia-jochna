#include <iostream>
#include <utility>

struct pii {
  long long first, second;
};

pii pt[int(1e3 + 10)];

template <typename T, typename U>
std::pair<T, U> operator-(const std::pair<T, U> &l, const std::pair<T, U> &r) {
  return {l.first - r.first, l.second - r.second};
}

long long orient(pii a, pii b, pii c) {
  pii v1 = b - a, v2 = c - a;
  return v1.first * v2.second - v2.first * v1.second;
}

long long dot(pii a, pii b) { return a.first * b.first + a.second * b.second; }

bool inDisk(pii a, pii b, pii p) { return dot(a - p, b - p) <= 0; }

bool onSeg(pii a, pii b, pii p) {
  return orient(a, b, p) == 0 && inDisk(a, b, p);
}

bool above(pii a, pii p) { return a.second <= p.second; }

bool crossesRay(pii a, pii p, pii q) {
  return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) std::cin >> pt[i].first >> pt[i].second;
  while (m--) {
    pii q;
    std::cin >> q.first >> q.second;
    int cnt = 0, flag = 0;
    for (int i = 0; i < n; i++) {
      if (onSeg(pt[i], pt[(i + 1) % n], q)) {
        std::cout << "BOUNDARY\n";
        flag = 1;
        break;
      }
      cnt += crossesRay(q, pt[i], pt[(i + 1) % n]);
    }
    if (flag) continue;
    if (cnt & 1)
      std::cout << "INSIDE\n";
    else
      std::cout << "OUTSIDE\n";
  }
}
