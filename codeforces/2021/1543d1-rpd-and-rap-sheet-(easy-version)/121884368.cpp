#include <bits/stdc++.h>
#define nd second
#define st first
#define pll pair<ll, ll>
using namespace std;
typedef long long ll;

void solution() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int q = i ^ (max(i - 1, 0));
    cout << q << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    if (ans == 1) {
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
