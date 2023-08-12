#include <bits/stdc++.h>
using namespace std;
int m, s;

string minimum() {
  int exsum = s;
  string nr;
  for (int i = m; i > 0; i--) {
    if (i * 9 < exsum) return "-1";
    if ((i - 1) * 9 >= exsum && (i != m || m == 1))
      nr.push_back('0');
    else if (i == m && (i - 1) * 9 >= exsum) {
      nr.push_back('1');
      exsum--;
    } else {
      nr.push_back(char(((exsum - 1) % 9 + 1) + int('0')));
      exsum -= (exsum - 1) % 9 + 1;
    }
  }
  return nr;
}

string maximum() {
  int exsum = s;
  string nr;
  for (int i = m; i > 0; i--) {
    if (i * 9 < exsum) return "-1";
    if ((i - 1) * 9 >= exsum) {
      nr.push_back('0');
    } else {
      nr.push_back(char(((exsum - 1) % 9 + 1) + int('0')));
      exsum -= (exsum - 1) % 9 + 1;
    }
  }
  return nr;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> m >> s;
  string minnr = minimum();
  string maxnr = maximum();
  if (minnr != "-1" && (s != 0 || m == 1)) {
    cout << minnr << " ";
    for (int i = maxnr.length() - 1; i >= 0; i--) cout << maxnr[i];
    cout << '\n';
  } else {
    cout << "-1 -1" << '\n';
  }
  return 0;
}
