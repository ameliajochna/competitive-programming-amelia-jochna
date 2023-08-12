#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i] = abs(v[i]);
  }
  set<int> s;
  for (int bt = 0; bt < (1 << n); bt++) {
    int sum = 0;
    for (int i = 0; i < n; i++)
      if (bt & (1 << i)) sum += v[i];
    s.insert(sum);
  }
  if (s.size() == (1 << n))
    cout << "NO\n";
  else
    cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
