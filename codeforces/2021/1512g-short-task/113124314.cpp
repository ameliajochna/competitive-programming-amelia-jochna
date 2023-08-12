#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e7 + 5;
int s[maxN], ans[maxN];
void solution() {}

void precalc() {
  for (int i = 1; i < maxN; i++)
    for (int j = 1; i * j < maxN; j++) s[i * j] += i;
  for (int i = 1; i < maxN; i++) {
    if (s[i] > maxN) continue;
    if (ans[s[i]] == 0 || ans[s[i]] > i) ans[s[i]] = i;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  precalc();
  int t = 1;
  cin >> t;
  while (t--) {
    int sum;
    cin >> sum;
    if (ans[sum] == 0)
      cout << "-1";
    else
      cout << ans[sum];
    cout << '\n';
  }
}
