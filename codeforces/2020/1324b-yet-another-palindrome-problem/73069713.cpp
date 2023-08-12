#include <bits/stdc++.h>
using namespace std;
int t, n, e;
int seq[5003];
int max_e_val;

bool finding_palindrom() {
  int previous_e = -1;
  max_e_val = 0;
  cin >> n;
  if (n == 1) {
    cin >> e;
    return true;
  }
  for (int i = 0; i < n; i++) {
    cin >> e;
    if (max_e_val < e) max_e_val = e;
    if (seq[e] != 0)
      if (previous_e != e || (previous_e == e && seq[e] > 1)) {
        for (int j = i + 1; j < n; j++) cin >> e;
        return true;
      }

    seq[e]++;
    previous_e = e;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int i = 0; i < t; i++) {
    if (finding_palindrom())
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
    fill_n(seq, max_e_val + 2, 0);
  }
  return 0;
}
