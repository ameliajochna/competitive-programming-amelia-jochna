#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int const MOD = 1e9 + 7;

void solution() {
  int n;
  cin >> n;
  ll multip = 1;
  vector<int> v;
  int stop = 0, cnt = 0;
  for (int i = 1; i < n; i++) {
    if (__gcd(i, n) == 1) {
      v.push_back(i);
      multip *= i;
      multip %= n;
      cnt++;
      if (multip == 1) stop = cnt;
    }
  }
  cout << stop << '\n';
  for (int i = 0; i < stop; i++) cout << v[i] << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  // cin>>t;
  while (t--) solution();
}
