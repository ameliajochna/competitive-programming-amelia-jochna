#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) p[i] = i + 1;
  cout << n << '\n';

  for (int i = 1; i <= n - 1; i++) {
    for (int j = 0; j < n; j++) cout << p[j] << " ";
    cout << '\n';
    swap(p[0], p[i]);
  }
  for (int j = 0; j < n; j++) cout << p[j] << " ";
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
