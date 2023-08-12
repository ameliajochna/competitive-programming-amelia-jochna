#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  int orpref = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    orpref |= tmp;
    cout << (tmp ^ orpref) << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
