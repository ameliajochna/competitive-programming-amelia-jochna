#include <iostream>
#include <vector>
using namespace std;
#define nd second
#define st first
#define pii pair<int, int>
#define pb push_back
typedef long long ll;
int const maxN = int(1e6 + 10);
int cand[maxN];  // 0-nic, 1-cukierki, 2- cukierki + bon
int bef[maxN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  for (int i = 1; i < maxN; i++) cand[i] = 1, bef[i] = i;
  int m;
  cin >> m;
  while (m--) {
    int cur;
    cin >> cur;
    cand[cur] = 2;
  }
  int n;
  cin >> n;
  ll num = 1;
  vector<ll> ans;
  while (n--) {
    int cur;
    cin >> cur;
    int cnt = cur;
    for (int i = bef[cur]; cnt > 0 && i < maxN; i += cur) {
      bef[cur] = i;
      if (cand[i] == 0) continue;

      if (cand[i] == 2) ans.push_back(num);
      num++;
      cnt--;
      cand[i] = 0;
    }
    num += cnt;
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << '\n';
}
