#include <bits/stdc++.h>
#define nd second
#define st first
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solution() {
  int n;
  cin >> n;
  int zparz = 0, znparz = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a % 2 == 0 && i % 2 == 1)
      zparz++;
    else if (a % 2 == 1 && i % 2 == 0)
      znparz++;
  }
  if (zparz == znparz)
    cout << znparz << "\n";
  else
    cout << "-1\n";
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
