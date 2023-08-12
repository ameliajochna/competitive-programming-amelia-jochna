#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool sprawdz(int x1, int x2, string &a, string &b) {
  bool eq = true, op = true;
  for (int i = x1 + 1; i <= x2; i++) {
    if (a[i] != b[i]) eq = false;
    if (a[i] == b[i]) op = false;
  }
  /*cout<<x1<<" "<<x2<<' ';
     if(eq) cout<<"eq ";
     else if(op) cout<<"op ";
     else cout<<"NIE ";
     cout<<'\n';*/
  return (eq | op);
}

void solution() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int cnt[2] = {0, 0};
  int prev = -1;
  for (int i = 0; i < n; i++) {
    cnt[a[i] - '0']++;
    if (cnt[0] == cnt[1]) {
      if (!sprawdz(prev, i, a, b)) {
        cout << "NO\n";
        return;
      }
      cnt[0] = 0, cnt[1] = 0;
      prev = i;
    }
  }
  if (prev != n - 1) {
    for (int i = prev + 1; i < n; i++) {
      if (a[i] != b[i]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
/*

 */
