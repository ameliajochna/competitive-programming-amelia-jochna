#include <iostream>
using namespace std;
int n, m;

void solution() {
  cin >> n >> m;
  int bct = 0, wct = 0, prev;
  if (n % 2 == 0 && m % 2 == 0)
    prev = 0;
  else
    prev = 1;  // black ->0, white -> 1
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      if (prev == 1) {
        cout << "B";
        prev = 0;
        bct++;
      } else {
        cout << "W";
        prev = 1;
        wct++;
      }
    }
    if (m % 2 == 0) {
      if (prev == 1)
        prev = 0;
      else
        prev = 1;
    }
    cout << '\n';
  }
  for (int j = 0; j < m - 1; j++) {
    if (prev == 1) {
      cout << "B";
      prev = 0;
      bct++;
    } else {
      cout << "W";
      prev = 1;
      wct++;
    }
  }
  if (wct == bct + 1)
    cout << "W";
  else
    cout << "B";
  cout << '\n';
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
