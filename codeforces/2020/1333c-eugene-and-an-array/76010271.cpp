#include <bits/stdc++.h>
using namespace std;
map<long long, int> pos;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  long long a, sum = 0, ans = 0;
  int maxi = 0, n;
  pos[0] = -1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    sum += a;
    if (pos.find(sum) != pos.end()) {
      if (sum == 0 && pos[0] == -1)
        maxi = max(1, maxi);
      else
        maxi = max(maxi, pos[sum] + 1);
    }
    ans += i - maxi;
    pos[sum] = i;
  }
  cout << ans;
  return 0;
}
