#include <bits/stdc++.h>

#include "cgdzlib.h"

int const maxN = (int)5e5 + 10;
int n;
vector<int> v;

bool check(int ind, int d) {
  for (int i = 0; i < n; i++) {
    if (i == ind) continue;
    int ans = f(ind + 1, i + 1, d);
    if (ans == 1) return 1;
  }
  return 0;
}

vector<int> fnd(int ind, int d) {
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    if (i == ind) continue;
    int ans = f(ind + 1, i + 1, d);
    if (ans == 1) vec.pb(i);
  }
  return vec;
}

int binsearch(int i) {
  int l = 0, r = n - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (check(i, mid))
      l = mid;
    else
      r = mid;
  }
  if (check(i, r))
    return r;
  else
    return l;
}

int main() {
  fast;

  n = inicjuj();
  if (n == 1) {
    odpowiedz(1);
  }
  int mx = binsearch(0);
  vector<int> val = fnd(0, mx);
  int pos = val.front(), pos2 = val.back();
  if (val.size() == 1) {
    int mx2 = binsearch(pos);
    vector<int> ans = fnd(pos, mx2);
    pos2 = ans.front();
  }

  int gr = g(pos + 1, pos2 + 1);
  if (gr == 1)
    odpowiedz(pos2 + 1);
  else
    odpowiedz(pos + 1);
}
