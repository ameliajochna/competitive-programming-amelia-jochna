#include <bits/stdc++.h>
using namespace std;

void solution() {
  vector<int> cnt(28);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto x : s) cnt[int(x - 'a')]++;
  }
  for (auto a : cnt) {
    // cout<<a<<" "<<a%n<<" "<<n<<'\n';
    if (a % n != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solution();
}
