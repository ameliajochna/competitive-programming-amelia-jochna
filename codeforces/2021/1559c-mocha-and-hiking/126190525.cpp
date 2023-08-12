#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  int back = -1;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp != 0 && back == -1) back = i;
  }
  if (back == 0) {
    cout << n + 1 << " ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << '\n';
  } else if (back == -1) {
    for (int i = 1; i <= n + 1; i++) cout << i << " ";
    cout << '\n';
  } else {
    for (int i = 1; i <= back; i++) {
      cout << i << " ";
    }
    cout << n + 1 << " ";
    for (int i = back + 1; i <= n; i++) cout << i << " ";
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
