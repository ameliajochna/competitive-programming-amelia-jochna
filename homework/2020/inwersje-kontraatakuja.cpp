#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 10;
typedef long long ll;
int n, a[N], tmp[N];

long long merge(int l1, int r1, int l2, int r2) {
  int j = min(l1, l2), start = j;
  long long inv = 0, rb = r1;
  while (l1 != r1 + 1 && l2 != r2 + 1) {
    if (a[l1] > a[l2]) {
      inv += rb - l1 + 1;
      tmp[j] = a[l2];
      l2++;
    } else {
      tmp[j] = a[l1];
      l1++;
    }
    j++;
  }
  while (l1 != r1 + 1) tmp[j] = a[l1], j++, l1++;
  while (l2 != r2 + 1) tmp[j] = a[l2], j++, l2++;
  for (int i = start; i <= max(r1, r2); i++) a[i] = tmp[i];
  return inv;
}

ll mergesort(int l, int r) {
  if (l >= r) return 0;
  int mid = (l + r) / 2;
  ll inv = 0;
  inv += mergesort(l, mid);
  inv += mergesort(mid + 1, r);
  inv += merge(l, mid, mid + 1, r);
  return inv;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << mergesort(1, n);
  return 0;
}
