#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
using namespace std;
typedef long long ll;

void solution() {
  int n;
  cin >> n;
  deque<int> dq;
  int tmp;
  cin >> tmp;
  dq.push_back(tmp);
  for (int i = 1; i < n; i++) {
    int cur;
    cin >> cur;
    if (cur < dq.front())
      dq.push_front(cur);
    else
      dq.push_back(cur);
  }
  for (auto x : dq) {
    cout << x << ' ';
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
/*
   1
   3 3 2
 *.*
   .*.
   ...

 */
