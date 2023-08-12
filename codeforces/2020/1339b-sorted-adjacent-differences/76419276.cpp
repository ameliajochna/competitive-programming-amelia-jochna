#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a.begin() + 1, a.begin() + n + 1);
  int i = n / 2, j = n / 2 + 1, prev = 0;
  if (n % 2 != 0) {
    cout << a[j] << " ";
    prev = a[j];
    j++;
  }
  while (i >= 0 && j <= n) {
    if (abs(a[i] - prev) > abs(a[j] - prev)) {
      cout << a[i] << " " << a[j] << " ";
      prev = a[j];
    } else {
      cout << a[j] << " " << a[i] << " ";
      prev = a[i];
    }
    j++;
    i--;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
