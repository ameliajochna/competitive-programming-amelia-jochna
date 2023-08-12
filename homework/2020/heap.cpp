#include <iostream>
#include <vector>

const int INF = 1e9 + 50;
int k;

struct minheap {
  std::vector<int> v;
  int next = 1;

  void pop() {
    if (next == 1) return;
    next--;
    v[1] = v[next];
    v[next] = INF;
    int u = 1;
    int left = 2 * u, right = 2 * u + 1;
    while (left <= next && right <= next + 1 &&
           (v[left] < v[u] || v[right] < v[u])) {
      if (v[left] < v[right]) {
        std::swap(v[left], v[u]);
        u = left;
      } else {
        std::swap(v[right], v[u]);
        u = right;
      }
      left = 2 * u, right = 2 * u + 1;
    }
  }

  void push(int x) {
    v[next] = x;
    int u = next;
    next++;
    while (u > 1 && v[u] < v[u / 2]) {
      std::swap(v[u], v[u / 2]);
      u /= 2;
    }
  }

  int top() {
    if (next != 1) return v[1];
  }
};

struct maxheap {
  std::vector<int> v;
  int next = 1;

  void pop() {
    if (next == 1) return;
    next--;
    v[1] = v[next];
    v[next] = 0;
    int cur = 1, left = cur * 2, right = cur * 2 + 1;
    while (left <= next && right <= next + 1 &&
           (v[cur] < v[left] || v[cur] < v[right])) {
      if (v[left] > v[right]) {
        std::swap(v[cur], v[left]);
        cur *= 2;
      } else {
        std::swap(v[cur], v[right]);
        cur = 2 * cur + 1;
      }
      left = cur * 2, right = cur * 2 + 1;
    }
  }

  void push(int val) {
    v[next] = val;
    int cur = next;
    while (cur > 1 && v[cur] > v[cur / 2]) {
      std::swap(v[cur], v[cur / 2]);
      cur /= 2;
    }
    next++;
  }

  int top() {
    if (next != 1) return v[1];
  }
};

int main() {
  std::cin.tie(0);
  std::cout.tie(0);

  maxheap less;     // a[i]: i <= k
  minheap greater;  // a[i]: i > k
  less.v.resize(1e6 + 20);
  for (int i = 0; i < 1e6 + 20; i++) greater.v.push_back(INF);
  std::cin >> k;
  while (true) {
    int e;
    std::cin >> e;
    if (e > 0) {
      if (less.next <= k) {
        less.push(e);
      } else {
        if (e < less.top()) {
          greater.push(less.top());
          less.pop();
          less.push(e);
        } else {
          greater.push(e);
        }
      }
    } else if (e == 0) {
      if (less.next <= k) {
        std::cout << "NIE MA\n";
      } else {
        std::cout << less.top() << '\n';
        less.pop();
        if (greater.next != 1) {
          less.push(greater.top());
          greater.pop();
        }
      }
    } else if (e == -1) {
      break;
    }
  }
  return 0;
}
