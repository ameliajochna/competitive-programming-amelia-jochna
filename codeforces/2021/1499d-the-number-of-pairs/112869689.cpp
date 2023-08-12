#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2e7;
int smldiv[maxN], cnt[maxN];

void solution() {
  int c, d, x;
  cin >> c >> d >> x;

  vector<int> xfact;
  int cur = x;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      xfact.push_back(i);
      if (x / i != i) xfact.push_back(x / i);
    }
  }

  int ans = 0;
  for (auto k : xfact) {
    // cout<<k<<" - \n";
    int z = x / k + d;
    if (z % c != 0) continue;
    z /= c;
    // cout<<z<<" "<<cnt[z]<<": "<<(1<<cnt[z])<<'\n';;
    ans += (1 << (cnt[z]));
  }
  cout << ans << '\n';
}

void precalc() {
  for (int i = 2; i <= maxN; i++) {
    if (smldiv[i] != 0) continue;
    for (int j = 1; i * j <= maxN; j++) {
      if (smldiv[i * j] == 0) smldiv[i * j] = i;
    }
  }
  for (int i = 2; i <= maxN; i++) {
    int mindiv = smldiv[i];
    cnt[i] = cnt[i / mindiv] + (mindiv != smldiv[i / mindiv]);
  }
  /*for(int i=0; i<=30; i++){
      cout<<i<<": "<<smldiv[i]<<" "<<cnt[i]<<'\n';
     }*/
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  precalc();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
