#include <bits/stdc++.h>
using namespace std;
void solution() {
  string num;
  cin >> num;
  bool zero = false, one = false;
  for (int i = 0; i < num.size(); i++) {
    if (num[i] == '0')
      zero = true;
    else
      one = true;
  }
  if (one ^ zero || num.size() <= 2)
    cout << num << '\n';
  else {
    bool prevzero = false;
    cout << num[0];
    if (num[0] == '0') prevzero = true;
    for (int i = 1; i < num.size(); i++) {
      if (num[i] == '0') {
        if (!prevzero) cout << num[i];
        cout << "1";
        prevzero = false;
      } else {
        if (prevzero) cout << num[i];
        cout << "0";
        prevzero = true;
      }
    }
    if (prevzero)
      cout << "1";
    else
      cout << "0";
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
  return 0;
}
