#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<vector<int> > ans(n);
  vector<int> inp(n);
  vector<bool> cont(n);
  for (int i = 0; i < n; i++) cin >> inp[i];

  ans[0] = {1};
  for (int i = 1; i < n; i++) {
    if (inp[i] == 1) {
      ans[i] = ans[i - 1];
      ans[i].push_back(1);
    } else if (inp[i - 1] + 1 == inp[i]) {
      ans[i] = ans[i - 1];
      ans[i][ans[i].size() - 1]++;
      cont[i - 1] = true;
    } else {
      int chos = -1;
      for (int j = i - 1; j >= 0; j--) {
        if (inp[j] + 1 == inp[i] && !cont[j]) {
          chos = j;
          break;
        }
      }
      ans[i] = ans[chos];
      ans[i][ans[i].size() - 1]++;
      for (int j = chos; j < i; j++) cont[j] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < ans[i].size() - 1; j++) cout << ans[i][j] << ".";
    cout << ans[i][ans[i].size() - 1] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solution();
}
