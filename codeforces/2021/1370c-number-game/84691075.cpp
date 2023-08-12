#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void solution() {
  int n;
  cin >> n;
  pair<string, string> pss = {"Ashishgup", "FastestFinger"};
  if (n == 1)
    cout << pss.second;
  else if (n == 2)
    cout << pss.first;
  else if (n % 2 == 1) {
    cout << pss.first;
  } else {
    if ((n & (n - 1)) == 0)
      cout << pss.second;
    else if (n % 4 == 0)
      cout << pss.first;
    else if (prime(n / 2))
      cout << pss.second;
    else
      cout << pss.first;
  }
  cout << '\n';
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
