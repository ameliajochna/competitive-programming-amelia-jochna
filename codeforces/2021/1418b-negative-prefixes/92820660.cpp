#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  vector<bool> iflocked(n);
  vector<int> a(n), unlock, v1(n), v2(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    bool b;
    cin >> b;
    iflocked[i] = b;
    if (!iflocked[i]) unlock.push_back(a[i]);
  }
  sort(unlock.begin(), unlock.end());
  int pointer = 0;
  for (int i = 0; i < n; i++) {
    if (!iflocked[i])
      v1[i] = unlock[pointer], pointer++;
    else
      v1[i] = a[i];
  }
  reverse(unlock.begin(), unlock.end());
  pointer = 0;
  for (int i = 0; i < n; i++) {
    if (!iflocked[i])
      v2[i] = unlock[pointer], pointer++;
    else
      v2[i] = a[i];
  }
  int v1ans = 0, v2ans = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += v1[i];
    if (sum < 0) v1ans = i + 1;
  }
  sum = 0;
  for (int i = 0; i < n; i++) {
    sum += v2[i];
    if (sum < 0) v2ans = i + 1;
  }
  if (v1ans <= v2ans) {
    for (int i = 0; i < n; i++) cout << v1[i] << " ";
    cout << '\n';
  } else {
    for (int i = 0; i < n; i++) cout << v2[i] << " ";
    cout << '\n';
  }
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solution();
}
