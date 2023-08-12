#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<int> values(n);
  for (int i = 0; i < n; i++) values[i] = v[i];
  sort(values.begin(), values.end());

  int l = 0, r = n - 1;
  for (int i = 0; i < n - 1; i++) {
    // cout<<values[i]<<" "<<l<<" "<<r<<" "<<v[l]<<" "<<v[r]<<'\n';
    if (v[l] == values[i])
      l++;
    else if (v[r] == values[i])
      r--;
  }
  if (l == r)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
