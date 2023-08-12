#include <bits/stdc++.h>
#define nd second
#define st first
using namespace std;
typedef long long ll;
int const maxN = 5e5 + 10, INF = 1e9;

void solution() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = s + 'a';
  vector<int> pref(n);
  pref[0] = s[0] - 'a';
  for (int i = 1; i <= n; i++) {
    pref[i] = (pref[i - 1] + s[i] - 'a');
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int subs = 0;
    if (l == 0)
      subs = 0;
    else
      subs = pref[l - 1];
    int sum = pref[r] - subs;
    // cout<<sum<<" "<<r-l+1<<" ";
    cout << sum + (r - l + 1) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  solution();
}
