#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> mex(n);
  for (int i = 0; i < s1.size(); i++) {
    bool b[2] = {0, 0};
    b[s1[i] - '0'] = true;
    b[s2[i] - '0'] = true;
    if (!b[0])
      mex[i] = 0;
    else if (!b[1])
      mex[i] = 1;
    else
      mex[i] = 2;
  }
  // for(int i=0; i<s1.size(); i++)
  //  cout<<mex[i]<<" ";
  // cout<<'\n';
  int ans = 0;
  for (int i = 0; i < s1.size(); i++) {
    // cout<<i<<" "<<ans<<'\n';
    if (mex[i] == 2 || (i == (s1.size() - 1))) {
      ans += mex[i];
      continue;
    }
    int a1 = mex[i], a2 = mex[i + 1];
    // cout<<i<<" "<<a1<<" "<<a2<<" "<<ans<<'\n';
    if (a1 + a2 == 1) {
      ans += 2;
      i++;
    } else {
      ans += mex[i];
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
