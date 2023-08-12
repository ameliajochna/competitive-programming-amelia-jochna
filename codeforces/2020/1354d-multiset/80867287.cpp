#include <iostream>
using namespace std;
int const maxN = 1 << 21;
int a[2 * maxN];

void updt(int x, int val) {
  x += maxN;
  a[x] += val;
  x /= 2;
  while (x > 0) {
    a[x] = a[2 * x] + a[2 * x + 1];
    x /= 2;
  }
}

int kth(int u, int k) {
  if (u >= maxN) return u - maxN;
  if (a[2 * u] < k)
    kth(2 * u + 1, k - a[2 * u]);
  else
    kth(2 * u, k);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    updt(e, 1);
  }
  for (int i = 0; i < q; i++) {
    int tf;
    cin >> tf;
    if (tf < 0) {
      tf *= -1;
      updt(kth(1, tf), -1);

    } else
      updt(tf, 1);
  }
  for (int i = maxN; i < 2 * maxN; i++)
    if (a[i]) {
      cout << i - maxN;
      return 0;
    }
  cout << 0;
}
