#include <bits/stdc++.h>
#define nd second
#define st first
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solution() {
  string s;
  cin >> s;
  bool fs = true;
  for (int i = 0; i < s.size(); i += 2) {
    cout << s[i];
  }
  cout << s[s.size() - 1];
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
