#include <iostream>
using namespace std;
bool a[201];
int n, x;

void clean() {
  for (int i = 0; i <= 100; i++) a[i] = false;
}

void solution() {
  clean();
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int tmp_val;
    cin >> tmp_val;
    if (tmp_val <= 100) a[tmp_val] = true;
  }
  int count = 0;
  for (int i = 0; i <= 100; i++) {
    if (a[i]) count++;
  }
  int i = 1;
  while (x > 0 || (x == 0 && a[i])) {
    if (!a[i]) x--;
    i++;
  }
  cout << i - 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solution();

  return 0;
}
